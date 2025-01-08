#include "../../../../disco/tiles.h"

#include "../../../../ballet/pack/fd_pack.h"
#include "../../../../ballet/blake3/fd_blake3.h"
#include "../../../../ballet/bmtree/fd_bmtree.h"
#include "../../../../disco/metrics/fd_metrics.h"
#include "../../../../disco/topo/fd_pod_format.h"
#include "../../../../disco/bank/fd_bank_abi.h"
#include "../../../../disco/metrics/generated/fd_metrics_bank.h"

#define FD_BANK_TRANSACTION_LANDED    1
#define FD_BANK_TRANSACTION_EXECUTED  2

typedef struct {
  ulong kind_id;

  fd_blake3_t * blake3;
  void * bmtree;

  uchar * txn_abi_mem;
  uchar * txn_sidecar_mem;

  void const * _bank;
  ulong _microblock_idx;
  int _is_bundle;

  ulong * busy_fseq;

  fd_wksp_t * pack_in_mem;
  ulong       pack_in_chunk0;
  ulong       pack_in_wmark;

  fd_wksp_t * out_mem;
  ulong       out_chunk0;
  ulong       out_wmark;
  ulong       out_chunk;

  struct {
    ulong slot_acquire[ 3 ];

    ulong txn_load_address_lookup_tables[ 6 ];
    ulong transaction_result[ 40 ];
    ulong processing_failed;
    ulong fee_only;
    ulong exec_failed;
    ulong success;
  } metrics;
} fd_bank_ctx_t;

FD_FN_CONST static inline ulong
scratch_align( void ) {
  return 128UL;
}

FD_FN_PURE static inline ulong
scratch_footprint( fd_topo_tile_t const * tile ) {
  (void)tile;
  ulong l = FD_LAYOUT_INIT;
  l = FD_LAYOUT_APPEND( l, alignof( fd_bank_ctx_t ), sizeof( fd_bank_ctx_t ) );
  l = FD_LAYOUT_APPEND( l, FD_BLAKE3_ALIGN, FD_BLAKE3_FOOTPRINT );
  l = FD_LAYOUT_APPEND( l, FD_BMTREE_COMMIT_ALIGN, FD_BMTREE_COMMIT_FOOTPRINT(0) );
  l = FD_LAYOUT_APPEND( l, FD_BANK_ABI_TXN_ALIGN, MAX_TXN_PER_MICROBLOCK*FD_BANK_ABI_TXN_FOOTPRINT );
  l = FD_LAYOUT_APPEND( l, FD_BANK_ABI_TXN_ALIGN, FD_BANK_ABI_TXN_FOOTPRINT_SIDECAR_MAX );
  return FD_LAYOUT_FINI( l, scratch_align() );
}

static inline void
metrics_write( fd_bank_ctx_t * ctx ) {
  FD_MCNT_ENUM_COPY( BANK, SLOT_ACQUIRE,  ctx->metrics.slot_acquire );

  FD_MCNT_ENUM_COPY( BANK, TRANSACTION_LOAD_ADDRESS_TABLES, ctx->metrics.txn_load_address_lookup_tables );
  FD_MCNT_ENUM_COPY( BANK, TRANSACTION_RESULT,  ctx->metrics.transaction_result );

  FD_MCNT_SET( BANK, PROCESSING_FAILED,            ctx->metrics.processing_failed );
  FD_MCNT_SET( BANK, FEE_ONLY_TRANSACTIONS,        ctx->metrics.fee_only          );
  FD_MCNT_SET( BANK, EXECUTED_FAILED_TRANSACTIONS, ctx->metrics.exec_failed       );
  FD_MCNT_SET( BANK, SUCCESSFUL_TRANSACTIONS,      ctx->metrics.success           );
}

static int
before_frag( fd_bank_ctx_t * ctx,
             ulong           in_idx,
             ulong           seq,
             ulong           sig ) {
  (void)in_idx;
  (void)seq;

  /* Pack also outputs "leader slot done" which we can ignore. */
  if( FD_UNLIKELY( fd_disco_poh_sig_pkt_type( sig )!=POH_PKT_TYPE_MICROBLOCK ) ) return 1;

  ulong target_bank_idx = fd_disco_poh_sig_bank_tile( sig );
  if( FD_UNLIKELY( target_bank_idx!=ctx->kind_id ) ) return 1;

  return 0;
}

extern void * fd_ext_bank_pre_balance_info( void const * bank, void * txns, ulong txn_cnt );
extern void * fd_ext_bank_load_and_execute_txns( void const * bank, void * txns, ulong txn_cnt, int * out_processing_results, int * out_transaction_err, uint * out_consumed_cus );
extern int    fd_ext_bank_execute_and_commit_bundle( void const * bank, void * txns, ulong txn_cnt, uint * out_consumed_cus );
extern void   fd_ext_bank_commit_txns( void const * bank, void const * txns, ulong txn_cnt , void * load_and_execute_output, void * pre_balance_info );
extern void   fd_ext_bank_release_thunks( void * load_and_execute_output );
extern void   fd_ext_bank_release_pre_balance_info( void * pre_balance_info );
extern int    fd_ext_bank_verify_precompiles( void const * bank, void const * txn );

static inline void
during_frag( fd_bank_ctx_t * ctx,
             ulong           in_idx,
             ulong           seq,
             ulong           sig,
             ulong           chunk,
             ulong           sz ) {
  (void)in_idx;
  (void)seq;
  (void)sig;

  uchar * src = (uchar *)fd_chunk_to_laddr( ctx->pack_in_mem, chunk );
  uchar * dst = (uchar *)fd_chunk_to_laddr( ctx->out_mem, ctx->out_chunk );

  if( FD_UNLIKELY( chunk<ctx->pack_in_chunk0 || chunk>ctx->pack_in_wmark || sz>USHORT_MAX ) )
    FD_LOG_ERR(( "chunk %lu %lu corrupt, not in range [%lu,%lu]", chunk, sz, ctx->pack_in_chunk0, ctx->pack_in_wmark ));

  fd_memcpy( dst, src, sz-sizeof(fd_microblock_bank_trailer_t) );
  fd_microblock_bank_trailer_t * trailer = (fd_microblock_bank_trailer_t *)( src+sz-sizeof(fd_microblock_bank_trailer_t) );
  ctx->_bank = trailer->bank;
  ctx->_microblock_idx = trailer->microblock_idx;
  ctx->_is_bundle = trailer->is_bundle;
}

static void
hash_transactions( void *       mem,
                   fd_txn_p_t * txns,
                   ulong        txn_cnt,
                   uchar *      mixin ) {
  fd_bmtree_commit_t * bmtree = fd_bmtree_commit_init( mem, 32UL, 1UL, 0UL );
  for( ulong i=0UL; i<txn_cnt; i++ ) {
    fd_txn_p_t * _txn = txns + i;
    if( FD_UNLIKELY( !(_txn->flags & FD_TXN_P_FLAGS_EXECUTE_SUCCESS) ) ) continue;

    fd_txn_t * txn = TXN(_txn);
    for( ulong j=0; j<txn->signature_cnt; j++ ) {
      fd_bmtree_node_t node[1];
      fd_bmtree_hash_leaf( node, _txn->payload+txn->signature_off+64UL*j, 64UL, 1UL );
      fd_bmtree_commit_append( bmtree, node, 1UL );
    }
  }
  uchar * root = fd_bmtree_commit_fini( bmtree );
  fd_memcpy( mixin, root, 32UL );
}

static inline void
handle_microblock( fd_bank_ctx_t *     ctx,
                   ulong               seq,
                   ulong               sig,
                   ulong               sz,
                   fd_stem_context_t * stem ) {
  uchar * dst = (uchar *)fd_chunk_to_laddr( ctx->out_mem, ctx->out_chunk );

  ulong slot = fd_disco_poh_sig_slot( sig );
  ulong txn_cnt = (sz-sizeof(fd_microblock_bank_trailer_t))/sizeof(fd_txn_p_t);

  ulong sanitized_txn_cnt = 0UL;
  ulong sidecar_footprint_bytes = 0UL;
  for( ulong i=0UL; i<txn_cnt; i++ ) {
    fd_txn_p_t * txn = (fd_txn_p_t *)( dst + (i*sizeof(fd_txn_p_t)) );

    void * abi_txn = ctx->txn_abi_mem + (sanitized_txn_cnt*FD_BANK_ABI_TXN_FOOTPRINT);
    void * abi_txn_sidecar = ctx->txn_sidecar_mem + sidecar_footprint_bytes;
    txn->flags &= ~FD_TXN_P_FLAGS_SANITIZE_SUCCESS;

    int result = fd_bank_abi_txn_init( abi_txn, abi_txn_sidecar, ctx->_bank, slot, ctx->blake3, txn->payload, txn->payload_sz, TXN(txn), !!(txn->flags & FD_TXN_P_FLAGS_IS_SIMPLE_VOTE) );
    ctx->metrics.txn_load_address_lookup_tables[ result ]++;
    if( FD_UNLIKELY( result!=FD_BANK_ABI_TXN_INIT_SUCCESS ) ) continue;

    int precompile_result = fd_ext_bank_verify_precompiles( ctx->_bank, abi_txn );
    if( FD_UNLIKELY( precompile_result ) ) {
      FD_MCNT_INC( BANK, PRECOMPILE_VERIFY_FAILURE, 1 );
      continue;
    }

    txn->flags |= FD_TXN_P_FLAGS_SANITIZE_SUCCESS;

    fd_txn_t * txn1 = TXN(txn);
    sidecar_footprint_bytes += FD_BANK_ABI_TXN_FOOTPRINT_SIDECAR( txn1->acct_addr_cnt, txn1->addr_table_adtl_cnt, txn1->instr_cnt, txn1->addr_table_lookup_cnt );
    sanitized_txn_cnt++;
  }

  /* Just because a transaction was executed doesn't mean it succeeded,
     but all executed transactions get committed. */
  int  processing_results[ MAX_TXN_PER_MICROBLOCK ] = { 0  };
  int  transaction_err   [ MAX_TXN_PER_MICROBLOCK ] = { 0  };
  uint consumed_cus      [ MAX_TXN_PER_MICROBLOCK ] = { 0U };

  void * pre_balance_info = fd_ext_bank_pre_balance_info( ctx->_bank, ctx->txn_abi_mem, sanitized_txn_cnt );

  void * load_and_execute_output = fd_ext_bank_load_and_execute_txns( ctx->_bank,
                                                                      ctx->txn_abi_mem,
                                                                      sanitized_txn_cnt,
                                                                      processing_results,
                                                                      transaction_err,
                                                                      consumed_cus );

  ulong sanitized_idx = 0UL;
  for( ulong i=0UL; i<txn_cnt; i++ ) {
    fd_txn_p_t * txn = (fd_txn_p_t *)( dst + (i*sizeof(fd_txn_p_t)) );

    uint requested_cus       = txn->pack_cu.requested_execution_cus;
    uint non_execution_cus   = txn->pack_cu.non_execution_cus;
    /* Assume failure, set below if success.  If it doesn't land in the
       block, rebate the non-execution CUs too. */
    txn->bank_cu.rebated_cus = requested_cus + non_execution_cus;
    txn->flags               &= ~FD_TXN_P_FLAGS_EXECUTE_SUCCESS;
    if( FD_UNLIKELY( !(txn->flags & FD_TXN_P_FLAGS_SANITIZE_SUCCESS) ) ) continue;

    sanitized_idx++;

    /* Stash the result in the flags value so that pack can inspect it.
     */
    txn->flags = (txn->flags & 0x00FFFFFFU) | ((uint)transaction_err[ sanitized_idx-1UL ]<<24);

    ctx->metrics.transaction_result[ transaction_err   [ sanitized_idx-1UL ] ]++;

    ctx->metrics.processing_failed += (ulong)(processing_results[ sanitized_idx-1UL ]==0                         );
    ctx->metrics.fee_only          += (ulong)(processing_results[ sanitized_idx-1UL ]==FD_BANK_TRANSACTION_LANDED);

    if( FD_UNLIKELY( !(processing_results[ sanitized_idx-1UL ] & FD_BANK_TRANSACTION_LANDED) ) ) continue;

    /* TXN_P_FLAGS_EXECUTE_SUCCESS means that it should be included in
       the block.  It's a bit of a misnomer now that there are fee-only
       transactions. */
    txn->flags                      |= FD_TXN_P_FLAGS_EXECUTE_SUCCESS;

    if( FD_UNLIKELY( !(processing_results[ sanitized_idx-1UL ] & FD_BANK_TRANSACTION_EXECUTED) ) ) continue;

    if( transaction_err[ sanitized_idx-1UL ] ) ctx->metrics.exec_failed++;
    else                                       ctx->metrics.success++;

    uint executed_cus                = consumed_cus[ sanitized_idx-1UL ];
    txn->bank_cu.actual_consumed_cus = non_execution_cus + executed_cus;
    if( FD_UNLIKELY( executed_cus>requested_cus ) ) {
      /* There's basically a bug in the Agave codebase right now
         regarding the cost model for some transactions.  Some built-in
         instructions like creating an address lookup table consume more
         CUs than the cost model allocates for them, which is only
         allowed because the runtime computes requested CUs differently
         from the cost model.  Rather than implement a broken system,
         we'll just permit the risk of slightly overpacking blocks by
         ignoring these transactions when it comes to rebating. */
      FD_LOG_INFO(( "Transaction executed %u CUs but only requested %u CUs", executed_cus, requested_cus ));
      FD_MCNT_INC( BANK, COST_MODEL_UNDERCOUNT, 1UL );
      txn->bank_cu.rebated_cus = 0U;
      continue;
    }
    txn->bank_cu.rebated_cus = requested_cus - executed_cus;
  }

  /* Commit must succeed so no failure path.  This function takes
     ownership of the load_and_execute_output and pre_balance_info heap
     allocations and will free them before it returns.  They should not
     be reused.  Once commit is called, the transactions MUST be mixed
     into the PoH otherwise we will fork and diverge, so the link from
     here til PoH mixin must be completely reliable with nothing dropped. */
  fd_ext_bank_commit_txns( ctx->_bank, ctx->txn_abi_mem, sanitized_txn_cnt, load_and_execute_output, pre_balance_info );
  pre_balance_info        = NULL;
  load_and_execute_output = NULL;

  /* Indicate to pack tile we are done processing the transactions so
     it can pack new microblocks using these accounts. */
  fd_fseq_update( ctx->busy_fseq, seq );

  /* Now produce the merkle hash of the transactions for inclusion
     (mixin) to the PoH hash.  This is done on the bank tile because
     it shards / scales horizontally here, while PoH does not. */
  fd_microblock_trailer_t * trailer = (fd_microblock_trailer_t *)( dst + txn_cnt*sizeof(fd_txn_p_t) );
  hash_transactions( ctx->bmtree, (fd_txn_p_t*)dst, txn_cnt, trailer->hash );

  /* MAX_MICROBLOCK_SZ - (MAX_TXN_PER_MICROBLOCK*sizeof(fd_txn_p_t)) == 64
     so there's always 64 extra bytes at the end to stash the hash. */
  FD_STATIC_ASSERT( MAX_MICROBLOCK_SZ-(MAX_TXN_PER_MICROBLOCK*sizeof(fd_txn_p_t))>=sizeof(fd_microblock_trailer_t), poh_shred_mtu );
  FD_STATIC_ASSERT( MAX_MICROBLOCK_SZ-(MAX_TXN_PER_MICROBLOCK*sizeof(fd_txn_p_t))>=sizeof(fd_microblock_bank_trailer_t), poh_shred_mtu );

  /* We have a race window with the GUI, where if the slot is ending it
     will snap these metrics to draw the waterfall, but see them outdated
     because housekeeping hasn't run.  For now just update them here, but
     PoH should eventually flush the pipeline before ending the slot. */
  metrics_write( ctx );

  ulong bank_sig = fd_disco_bank_sig( slot, ctx->_microblock_idx );

  /* We always need to publish, even if there are no successfully executed
     transactions so the PoH tile can keep an accurate count of microblocks
     it has seen. */
  ulong tspub = (ulong)fd_frag_meta_ts_comp( fd_tickcount() );
  ulong new_sz = txn_cnt*sizeof(fd_txn_p_t) + sizeof(fd_microblock_trailer_t);
  fd_stem_publish( stem, 0UL, bank_sig, ctx->out_chunk, new_sz, 0UL, 0UL, tspub );
  ctx->out_chunk = fd_dcache_compact_next( ctx->out_chunk, new_sz, ctx->out_chunk0, ctx->out_wmark );
}

static inline void
handle_bundle( fd_bank_ctx_t *     ctx,
               ulong               seq,
               ulong               sig,
               ulong               sz,
               fd_stem_context_t * stem ) {
  (void)seq;
  (void)stem;

  uchar * dst = (uchar *)fd_chunk_to_laddr( ctx->out_mem, ctx->out_chunk );
  fd_txn_p_t * txns = (fd_txn_p_t *)dst;

  ulong slot = fd_disco_poh_sig_slot( sig );
  ulong txn_cnt = (sz-sizeof(fd_microblock_bank_trailer_t))/sizeof(fd_txn_p_t);

  int execution_success = 1;

  ulong sidecar_footprint_bytes = 0UL;
  for( ulong i=0UL; i<txn_cnt; i++ ) {
    fd_txn_p_t * txn = txns+i;

    void * abi_txn = ctx->txn_abi_mem + (i*FD_BANK_ABI_TXN_FOOTPRINT);
    void * abi_txn_sidecar = ctx->txn_sidecar_mem + sidecar_footprint_bytes;
    txn->flags &= ~(FD_TXN_P_FLAGS_SANITIZE_SUCCESS | FD_TXN_P_FLAGS_EXECUTE_SUCCESS);

    int result = fd_bank_abi_txn_init( abi_txn, abi_txn_sidecar, ctx->_bank, slot, ctx->blake3, txn->payload, txn->payload_sz, TXN(txn), !!(txn->flags & FD_TXN_P_FLAGS_IS_SIMPLE_VOTE) );
    ctx->metrics.txn_load_address_lookup_tables[ result ]++;
    if( FD_UNLIKELY( result!=FD_BANK_ABI_TXN_INIT_SUCCESS ) ) {
      execution_success = 0;
      continue;
    }

    int precompile_result = fd_ext_bank_verify_precompiles( ctx->_bank, abi_txn );
    if( FD_UNLIKELY( precompile_result ) ) {
      execution_success = 0;
      FD_MCNT_INC( BANK, PRECOMPILE_VERIFY_FAILURE, 1 );
      continue;
    }

    txn->flags |= FD_TXN_P_FLAGS_SANITIZE_SUCCESS;

    fd_txn_t * txn1 = TXN(txn);
    sidecar_footprint_bytes += FD_BANK_ABI_TXN_FOOTPRINT_SIDECAR( txn1->acct_addr_cnt, txn1->addr_table_adtl_cnt, txn1->instr_cnt, txn1->addr_table_lookup_cnt );
  }

  uint consumed_cus[ MAX_TXN_PER_MICROBLOCK ] = { 0U };
  if( FD_LIKELY( execution_success ) ) {
    /* TODO: Plumb through errors. */
    execution_success = fd_ext_bank_execute_and_commit_bundle( ctx->_bank, ctx->txn_abi_mem, txn_cnt, consumed_cus );
  }

  if( FD_LIKELY( execution_success ) ) {
    ctx->metrics.success += txn_cnt;
    ctx->metrics.transaction_result[ FD_METRICS_ENUM_TRANSACTION_ERROR_V_SUCCESS_IDX ] += txn_cnt;
    for( ulong i=0UL; i<txn_cnt; i++ ) txns[ i ].flags |= FD_TXN_P_FLAGS_EXECUTE_SUCCESS;
  } else {
    /* If any transaction fails in a bundle ... they all fail */
    for( ulong i=0UL; i<txn_cnt; i++ ) {
      fd_txn_p_t * txn = txns+i;
      /* Don't double count metrics for transactions that failed to
         sanitize. */
      if( FD_UNLIKELY( !(txn->flags & FD_TXN_P_FLAGS_SANITIZE_SUCCESS) ) ) continue;

      txn->flags &= ~FD_TXN_P_FLAGS_EXECUTE_SUCCESS;
      ctx->metrics.processing_failed++;
      ctx->metrics.transaction_result[ FD_METRICS_ENUM_TRANSACTION_ERROR_V_BUNDLE_PEER_IDX ]++;
    }
  }

  /* Indicate to pack tile we are done processing the transactions so
     it can pack new microblocks using these accounts. */
  fd_fseq_update( ctx->busy_fseq, seq );

  for( ulong i=0UL; i<txn_cnt; i++ ) {
    fd_txn_p_t * txn = txns+i;

    uint requested_cus       = txn->pack_cu.requested_execution_cus;
    uint non_execution_cus   = txn->pack_cu.non_execution_cus;
    /* Assume failure, set below if success.  If it doesn't land in the
       block, rebate the non-execution CUs too. */
    txn->bank_cu.rebated_cus = requested_cus + non_execution_cus;

    if( FD_LIKELY( (txn->flags & (FD_TXN_P_FLAGS_SANITIZE_SUCCESS|FD_TXN_P_FLAGS_EXECUTE_SUCCESS))==(FD_TXN_P_FLAGS_SANITIZE_SUCCESS|FD_TXN_P_FLAGS_EXECUTE_SUCCESS) ) ) {
      uint executed_cus = consumed_cus[ i ];
      txn->bank_cu.actual_consumed_cus = non_execution_cus + executed_cus;
      if( FD_UNLIKELY( executed_cus>requested_cus ) ) {
        /* There's basically a bug in the Agave codebase right now
          regarding the cost model for some transactions.  Some built-in
          instructions like creating an address lookup table consume more
          CUs than the cost model allocates for them, which is only
          allowed because the runtime computes requested CUs differently
          from the cost model.  Rather than implement a broken system,
          we'll just permit the risk of slightly overpacking blocks by
          ignoring these transactions when it comes to rebating. */
        FD_LOG_INFO(( "Transaction executed %u CUs but only requested %u CUs", executed_cus, requested_cus ));
        FD_MCNT_INC( BANK, COST_MODEL_UNDERCOUNT, 1UL );
        txn->bank_cu.rebated_cus = 0U;
        continue;
      }
      txn->bank_cu.rebated_cus = requested_cus - executed_cus;
    }
  }

  /* We need to publish each transaction separately into its own
     microblock, so make a temporary copy on the stack so we can move
     all the data around. */
  fd_txn_p_t bundle_txn_temp[ 5UL ];
  for( ulong i=0UL; i<txn_cnt; i++ ) {
    fd_memcpy( bundle_txn_temp+i, txns+i, sizeof(fd_txn_p_t) );
  }

  for( ulong i=0UL; i<txn_cnt; i++ ) {
    uchar * dst = (uchar *)fd_chunk_to_laddr( ctx->out_mem, ctx->out_chunk );
    fd_memcpy( dst, bundle_txn_temp+i, sizeof(fd_txn_p_t) );

    fd_microblock_trailer_t * trailer = (fd_microblock_trailer_t *)( dst+sizeof(fd_txn_p_t) );
    hash_transactions( ctx->bmtree, (fd_txn_p_t*)dst, 1UL, trailer->hash );

    ulong bank_sig = fd_disco_bank_sig( slot, ctx->_microblock_idx+i );

    ulong tspub = (ulong)fd_frag_meta_ts_comp( fd_tickcount() );
    ulong new_sz = sizeof(fd_txn_p_t) + sizeof(fd_microblock_trailer_t);
    fd_stem_publish( stem, 0UL, bank_sig, ctx->out_chunk, new_sz, 0UL, 0UL, tspub );
    ctx->out_chunk = fd_dcache_compact_next( ctx->out_chunk, new_sz, ctx->out_chunk0, ctx->out_wmark );
  }

  metrics_write( ctx );
}

static inline void
after_frag( fd_bank_ctx_t *     ctx,
            ulong               in_idx,
            ulong               seq,
            ulong               sig,
            ulong               sz,
            ulong               tsorig,
            fd_stem_context_t * stem ) {
  (void)in_idx;
  (void)tsorig;

  if( FD_UNLIKELY( ctx->_is_bundle ) ) handle_bundle( ctx, seq, sig, sz, stem );
  else                                 handle_microblock( ctx, seq, sig, sz, stem );
}

static void
unprivileged_init( fd_topo_t *      topo,
                   fd_topo_tile_t * tile ) {
  void * scratch = fd_topo_obj_laddr( topo, tile->tile_obj_id );

  FD_SCRATCH_ALLOC_INIT( l, scratch );
  fd_bank_ctx_t * ctx = FD_SCRATCH_ALLOC_APPEND( l, alignof( fd_bank_ctx_t ), sizeof( fd_bank_ctx_t ) );
  void * blake3 = FD_SCRATCH_ALLOC_APPEND( l, FD_BLAKE3_ALIGN, FD_BLAKE3_FOOTPRINT );
  void * bmtree = FD_SCRATCH_ALLOC_APPEND( l, FD_BMTREE_COMMIT_ALIGN,           FD_BMTREE_COMMIT_FOOTPRINT(0)      );
  ctx->txn_abi_mem = FD_SCRATCH_ALLOC_APPEND( l, FD_BANK_ABI_TXN_ALIGN, MAX_TXN_PER_MICROBLOCK*FD_BANK_ABI_TXN_FOOTPRINT );
  ctx->txn_sidecar_mem = FD_SCRATCH_ALLOC_APPEND( l, FD_BANK_ABI_TXN_ALIGN, FD_BANK_ABI_TXN_FOOTPRINT_SIDECAR_MAX );

#define NONNULL( x ) (__extension__({                                        \
      __typeof__((x)) __x = (x);                                             \
      if( FD_UNLIKELY( !__x ) ) FD_LOG_ERR(( #x " was unexpectedly NULL" )); \
      __x; }))

  ctx->kind_id = tile->kind_id;
  ctx->blake3 = NONNULL( fd_blake3_join( fd_blake3_new( blake3 ) ) );
  ctx->bmtree = NONNULL( bmtree );

  ulong busy_obj_id = fd_pod_queryf_ulong( topo->props, ULONG_MAX, "bank_busy.%lu", tile->kind_id );
  FD_TEST( busy_obj_id!=ULONG_MAX );
  ctx->busy_fseq = fd_fseq_join( fd_topo_obj_laddr( topo, busy_obj_id ) );
  if( FD_UNLIKELY( !ctx->busy_fseq ) ) FD_LOG_ERR(( "banking tile %lu has no busy flag", tile->kind_id ));

  memset( &ctx->metrics, 0, sizeof( ctx->metrics ) );

  ctx->pack_in_mem = topo->workspaces[ topo->objs[ topo->links[ tile->in_link_id[ 0UL ] ].dcache_obj_id ].wksp_id ].wksp;
  ctx->pack_in_chunk0 = fd_dcache_compact_chunk0( ctx->pack_in_mem, topo->links[ tile->in_link_id[ 0UL ] ].dcache );
  ctx->pack_in_wmark  = fd_dcache_compact_wmark ( ctx->pack_in_mem, topo->links[ tile->in_link_id[ 0UL ] ].dcache, topo->links[ tile->in_link_id[ 0UL ] ].mtu );

  ctx->out_mem    = topo->workspaces[ topo->objs[ topo->links[ tile->out_link_id[ 0 ] ].dcache_obj_id ].wksp_id ].wksp;
  ctx->out_chunk0 = fd_dcache_compact_chunk0( ctx->out_mem, topo->links[ tile->out_link_id[ 0 ] ].dcache );
  ctx->out_wmark  = fd_dcache_compact_wmark ( ctx->out_mem, topo->links[ tile->out_link_id[ 0 ] ].dcache, topo->links[ tile->out_link_id[ 0 ] ].mtu );
  ctx->out_chunk  = ctx->out_chunk0;
}

/* For a bundle, one bundle might burst into at most 5 separate PoH mixins, since the
   microblocks cannot be conflicting. */

#define STEM_BURST (5UL)

/* See explanation in fd_pack */
#define STEM_LAZY  (128L*3000L)

#define STEM_CALLBACK_CONTEXT_TYPE  fd_bank_ctx_t
#define STEM_CALLBACK_CONTEXT_ALIGN alignof(fd_bank_ctx_t)

#define STEM_CALLBACK_METRICS_WRITE metrics_write
#define STEM_CALLBACK_BEFORE_FRAG   before_frag
#define STEM_CALLBACK_DURING_FRAG   during_frag
#define STEM_CALLBACK_AFTER_FRAG    after_frag

#include "../../../../disco/stem/fd_stem.c"

fd_topo_run_tile_t fd_tile_bank = {
  .name                     = "bank",
  .scratch_align            = scratch_align,
  .scratch_footprint        = scratch_footprint,
  .unprivileged_init        = unprivileged_init,
  .run                      = stem_run,
};
