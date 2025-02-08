/* THIS FILE IS GENERATED BY gen_metrics.py. DO NOT HAND EDIT. */

#define FD_METRICS_ENUM_TILE_REGIME_NAME "tile_regime"
#define FD_METRICS_ENUM_TILE_REGIME_V_CAUGHT_UP_HOUSEKEEPING_IDX  0
#define FD_METRICS_ENUM_TILE_REGIME_V_CAUGHT_UP_HOUSEKEEPING_NAME "caught_up_housekeeping"
#define FD_METRICS_ENUM_TILE_REGIME_V_PROCESSING_HOUSEKEEPING_IDX  1
#define FD_METRICS_ENUM_TILE_REGIME_V_PROCESSING_HOUSEKEEPING_NAME "processing_housekeeping"
#define FD_METRICS_ENUM_TILE_REGIME_V_BACKPRESSURE_HOUSEKEEPING_IDX  2
#define FD_METRICS_ENUM_TILE_REGIME_V_BACKPRESSURE_HOUSEKEEPING_NAME "backpressure_housekeeping"
#define FD_METRICS_ENUM_TILE_REGIME_V_CAUGHT_UP_PREFRAG_IDX  3
#define FD_METRICS_ENUM_TILE_REGIME_V_CAUGHT_UP_PREFRAG_NAME "caught_up_prefrag"
#define FD_METRICS_ENUM_TILE_REGIME_V_PROCESSING_PREFRAG_IDX  4
#define FD_METRICS_ENUM_TILE_REGIME_V_PROCESSING_PREFRAG_NAME "processing_prefrag"
#define FD_METRICS_ENUM_TILE_REGIME_V_BACKPRESSURE_PREFRAG_IDX  5
#define FD_METRICS_ENUM_TILE_REGIME_V_BACKPRESSURE_PREFRAG_NAME "backpressure_prefrag"
#define FD_METRICS_ENUM_TILE_REGIME_V_CAUGHT_UP_POSTFRAG_IDX  6
#define FD_METRICS_ENUM_TILE_REGIME_V_CAUGHT_UP_POSTFRAG_NAME "caught_up_postfrag"
#define FD_METRICS_ENUM_TILE_REGIME_V_PROCESSING_POSTFRAG_IDX  7
#define FD_METRICS_ENUM_TILE_REGIME_V_PROCESSING_POSTFRAG_NAME "processing_postfrag"

#define FD_METRICS_ENUM_TPU_RECV_TYPE_NAME "tpu_recv_type"
#define FD_METRICS_ENUM_TPU_RECV_TYPE_V_UDP_IDX  0
#define FD_METRICS_ENUM_TPU_RECV_TYPE_V_UDP_NAME "udp"
#define FD_METRICS_ENUM_TPU_RECV_TYPE_V_QUIC_FAST_IDX  1
#define FD_METRICS_ENUM_TPU_RECV_TYPE_V_QUIC_FAST_NAME "quic_fast"
#define FD_METRICS_ENUM_TPU_RECV_TYPE_V_QUIC_FRAG_IDX  2
#define FD_METRICS_ENUM_TPU_RECV_TYPE_V_QUIC_FRAG_NAME "quic_frag"

#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_NAME "quic_frame_type"
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_UNKNOWN_IDX  0
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_UNKNOWN_NAME "unknown"
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_ACK_IDX  1
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_ACK_NAME "ack"
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_RESET_STREAM_IDX  2
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_RESET_STREAM_NAME "reset_stream"
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_STOP_SENDING_IDX  3
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_STOP_SENDING_NAME "stop_sending"
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_CRYPTO_IDX  4
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_CRYPTO_NAME "crypto"
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_NEW_TOKEN_IDX  5
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_NEW_TOKEN_NAME "new_token"
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_STREAM_IDX  6
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_STREAM_NAME "stream"
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_MAX_DATA_IDX  7
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_MAX_DATA_NAME "max_data"
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_MAX_STREAM_DATA_IDX  8
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_MAX_STREAM_DATA_NAME "max_stream_data"
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_MAX_STREAMS_IDX  9
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_MAX_STREAMS_NAME "max_streams"
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_DATA_BLOCKED_IDX  10
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_DATA_BLOCKED_NAME "data_blocked"
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_STREAM_DATA_BLOCKED_IDX  11
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_STREAM_DATA_BLOCKED_NAME "stream_data_blocked"
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_STREAMS_BLOCKED_IDX  12
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_STREAMS_BLOCKED_NAME "streams_blocked"
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_NEW_CONN_ID_IDX  13
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_NEW_CONN_ID_NAME "new_conn_id"
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_RETIRE_CONN_ID_IDX  14
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_RETIRE_CONN_ID_NAME "retire_conn_id"
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_PATH_CHALLENGE_IDX  15
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_PATH_CHALLENGE_NAME "path_challenge"
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_PATH_RESPONSE_IDX  16
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_PATH_RESPONSE_NAME "path_response"
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_CONN_CLOSE_QUIC_IDX  17
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_CONN_CLOSE_QUIC_NAME "conn_close_quic"
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_CONN_CLOSE_APP_IDX  18
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_CONN_CLOSE_APP_NAME "conn_close_app"
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_HANDSHAKE_DONE_IDX  19
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_HANDSHAKE_DONE_NAME "handshake_done"
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_PING_IDX  20
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_PING_NAME "ping"
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_PADDING_IDX  21
#define FD_METRICS_ENUM_QUIC_FRAME_TYPE_V_PADDING_NAME "padding"

#define FD_METRICS_ENUM_QUIC_STREAM_CLOSE_TYPE_NAME "quic_stream_close_type"
#define FD_METRICS_ENUM_QUIC_STREAM_CLOSE_TYPE_V_END_IDX  0
#define FD_METRICS_ENUM_QUIC_STREAM_CLOSE_TYPE_V_END_NAME "end"
#define FD_METRICS_ENUM_QUIC_STREAM_CLOSE_TYPE_V_PEER_RESET_IDX  1
#define FD_METRICS_ENUM_QUIC_STREAM_CLOSE_TYPE_V_PEER_RESET_NAME "peer_reset"
#define FD_METRICS_ENUM_QUIC_STREAM_CLOSE_TYPE_V_PEER_STOP_IDX  2
#define FD_METRICS_ENUM_QUIC_STREAM_CLOSE_TYPE_V_PEER_STOP_NAME "peer_stop"
#define FD_METRICS_ENUM_QUIC_STREAM_CLOSE_TYPE_V_DROP_IDX  3
#define FD_METRICS_ENUM_QUIC_STREAM_CLOSE_TYPE_V_DROP_NAME "drop"
#define FD_METRICS_ENUM_QUIC_STREAM_CLOSE_TYPE_V_CONN_ABORT_IDX  4
#define FD_METRICS_ENUM_QUIC_STREAM_CLOSE_TYPE_V_CONN_ABORT_NAME "conn_abort"

#define FD_METRICS_ENUM_QUIC_ACK_TX_NAME "quic_ack_tx"
#define FD_METRICS_ENUM_QUIC_ACK_TX_V_NOOP_IDX  0
#define FD_METRICS_ENUM_QUIC_ACK_TX_V_NOOP_NAME "noop"
#define FD_METRICS_ENUM_QUIC_ACK_TX_V_NEW_IDX  1
#define FD_METRICS_ENUM_QUIC_ACK_TX_V_NEW_NAME "new"
#define FD_METRICS_ENUM_QUIC_ACK_TX_V_MERGED_IDX  2
#define FD_METRICS_ENUM_QUIC_ACK_TX_V_MERGED_NAME "merged"
#define FD_METRICS_ENUM_QUIC_ACK_TX_V_DROP_IDX  3
#define FD_METRICS_ENUM_QUIC_ACK_TX_V_DROP_NAME "drop"
#define FD_METRICS_ENUM_QUIC_ACK_TX_V_CANCEL_IDX  4
#define FD_METRICS_ENUM_QUIC_ACK_TX_V_CANCEL_NAME "cancel"

#define FD_METRICS_ENUM_QUIC_ENC_LEVEL_NAME "quic_enc_level"
#define FD_METRICS_ENUM_QUIC_ENC_LEVEL_V_INITIAL_IDX  0
#define FD_METRICS_ENUM_QUIC_ENC_LEVEL_V_INITIAL_NAME "initial"
#define FD_METRICS_ENUM_QUIC_ENC_LEVEL_V_EARLY_IDX  1
#define FD_METRICS_ENUM_QUIC_ENC_LEVEL_V_EARLY_NAME "early"
#define FD_METRICS_ENUM_QUIC_ENC_LEVEL_V_HANDSHAKE_IDX  2
#define FD_METRICS_ENUM_QUIC_ENC_LEVEL_V_HANDSHAKE_NAME "handshake"
#define FD_METRICS_ENUM_QUIC_ENC_LEVEL_V_APP_IDX  3
#define FD_METRICS_ENUM_QUIC_ENC_LEVEL_V_APP_NAME "app"

#define FD_METRICS_ENUM_LUT_RESOLVE_RESULT_NAME "lut_resolve_result"
#define FD_METRICS_ENUM_LUT_RESOLVE_RESULT_V_INVALID_LOOKUP_INDEX_IDX  0
#define FD_METRICS_ENUM_LUT_RESOLVE_RESULT_V_INVALID_LOOKUP_INDEX_NAME "invalid_lookup_index"
#define FD_METRICS_ENUM_LUT_RESOLVE_RESULT_V_ACCOUNT_UNINITIALIZED_IDX  1
#define FD_METRICS_ENUM_LUT_RESOLVE_RESULT_V_ACCOUNT_UNINITIALIZED_NAME "account_uninitialized"
#define FD_METRICS_ENUM_LUT_RESOLVE_RESULT_V_INVALID_ACCOUNT_DATA_IDX  2
#define FD_METRICS_ENUM_LUT_RESOLVE_RESULT_V_INVALID_ACCOUNT_DATA_NAME "invalid_account_data"
#define FD_METRICS_ENUM_LUT_RESOLVE_RESULT_V_INVALID_ACCOUNT_OWNER_IDX  3
#define FD_METRICS_ENUM_LUT_RESOLVE_RESULT_V_INVALID_ACCOUNT_OWNER_NAME "invalid_account_owner"
#define FD_METRICS_ENUM_LUT_RESOLVE_RESULT_V_ACCOUNT_NOT_FOUND_IDX  4
#define FD_METRICS_ENUM_LUT_RESOLVE_RESULT_V_ACCOUNT_NOT_FOUND_NAME "account_not_found"
#define FD_METRICS_ENUM_LUT_RESOLVE_RESULT_V_SUCCESS_IDX  5
#define FD_METRICS_ENUM_LUT_RESOLVE_RESULT_V_SUCCESS_NAME "success"

#define FD_METRICS_ENUM_RESOLVE_STASH_OPERATION_NAME "resolve_stash_operation"
#define FD_METRICS_ENUM_RESOLVE_STASH_OPERATION_V_INSERTED_IDX  0
#define FD_METRICS_ENUM_RESOLVE_STASH_OPERATION_V_INSERTED_NAME "inserted"
#define FD_METRICS_ENUM_RESOLVE_STASH_OPERATION_V_OVERRUN_IDX  1
#define FD_METRICS_ENUM_RESOLVE_STASH_OPERATION_V_OVERRUN_NAME "overrun"
#define FD_METRICS_ENUM_RESOLVE_STASH_OPERATION_V_PUBLISHED_IDX  2
#define FD_METRICS_ENUM_RESOLVE_STASH_OPERATION_V_PUBLISHED_NAME "published"
#define FD_METRICS_ENUM_RESOLVE_STASH_OPERATION_V_REMOVED_IDX  3
#define FD_METRICS_ENUM_RESOLVE_STASH_OPERATION_V_REMOVED_NAME "removed"

#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_NAME "pack_txn_insert_return"
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_BUNDLE_BLACKLIST_IDX  0
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_BUNDLE_BLACKLIST_NAME "bundle_blacklist"
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_WRITE_SYSVAR_IDX  1
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_WRITE_SYSVAR_NAME "write_sysvar"
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_ESTIMATION_FAIL_IDX  2
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_ESTIMATION_FAIL_NAME "estimation_fail"
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_DUPLICATE_ACCOUNT_IDX  3
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_DUPLICATE_ACCOUNT_NAME "duplicate_account"
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_TOO_MANY_ACCOUNTS_IDX  4
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_TOO_MANY_ACCOUNTS_NAME "too_many_accounts"
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_TOO_LARGE_IDX  5
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_TOO_LARGE_NAME "too_large"
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_EXPIRED_IDX  6
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_EXPIRED_NAME "expired"
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_ADDR_LUT_IDX  7
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_ADDR_LUT_NAME "addr_lut"
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_UNAFFORDABLE_IDX  8
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_UNAFFORDABLE_NAME "unaffordable"
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_DUPLICATE_IDX  9
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_DUPLICATE_NAME "duplicate"
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_PRIORITY_IDX  10
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_PRIORITY_NAME "priority"
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_NONVOTE_ADD_IDX  11
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_NONVOTE_ADD_NAME "nonvote_add"
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_VOTE_ADD_IDX  12
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_VOTE_ADD_NAME "vote_add"
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_NONVOTE_REPLACE_IDX  13
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_NONVOTE_REPLACE_NAME "nonvote_replace"
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_VOTE_REPLACE_IDX  14
#define FD_METRICS_ENUM_PACK_TXN_INSERT_RETURN_V_VOTE_REPLACE_NAME "vote_replace"

#define FD_METRICS_ENUM_PACK_TXN_SCHEDULE_NAME "pack_txn_schedule"
#define FD_METRICS_ENUM_PACK_TXN_SCHEDULE_V_TAKEN_IDX  0
#define FD_METRICS_ENUM_PACK_TXN_SCHEDULE_V_TAKEN_NAME "taken"
#define FD_METRICS_ENUM_PACK_TXN_SCHEDULE_V_CU_LIMIT_IDX  1
#define FD_METRICS_ENUM_PACK_TXN_SCHEDULE_V_CU_LIMIT_NAME "cu_limit"
#define FD_METRICS_ENUM_PACK_TXN_SCHEDULE_V_FAST_PATH_IDX  2
#define FD_METRICS_ENUM_PACK_TXN_SCHEDULE_V_FAST_PATH_NAME "fast_path"
#define FD_METRICS_ENUM_PACK_TXN_SCHEDULE_V_BYTE_LIMIT_IDX  3
#define FD_METRICS_ENUM_PACK_TXN_SCHEDULE_V_BYTE_LIMIT_NAME "byte_limit"
#define FD_METRICS_ENUM_PACK_TXN_SCHEDULE_V_WRITE_COST_IDX  4
#define FD_METRICS_ENUM_PACK_TXN_SCHEDULE_V_WRITE_COST_NAME "write_cost"
#define FD_METRICS_ENUM_PACK_TXN_SCHEDULE_V_SLOW_PATH_IDX  5
#define FD_METRICS_ENUM_PACK_TXN_SCHEDULE_V_SLOW_PATH_NAME "slow_path"
#define FD_METRICS_ENUM_PACK_TXN_SCHEDULE_V_DEFER_SKIP_IDX  6
#define FD_METRICS_ENUM_PACK_TXN_SCHEDULE_V_DEFER_SKIP_NAME "defer_skip"

#define FD_METRICS_ENUM_PACK_TIMING_STATE_NAME "pack_timing_state"
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_NO_TXN_NO_BANK_NO_LEADER_NO_MICROBLOCK_IDX  0
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_NO_TXN_NO_BANK_NO_LEADER_NO_MICROBLOCK_NAME "no_txn_no_bank_no_leader_no_microblock"
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_TXN_NO_BANK_NO_LEADER_NO_MICROBLOCK_IDX  1
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_TXN_NO_BANK_NO_LEADER_NO_MICROBLOCK_NAME "txn_no_bank_no_leader_no_microblock"
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_NO_TXN_BANK_NO_LEADER_NO_MICROBLOCK_IDX  2
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_NO_TXN_BANK_NO_LEADER_NO_MICROBLOCK_NAME "no_txn_bank_no_leader_no_microblock"
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_TXN_BANK_NO_LEADER_NO_MICROBLOCK_IDX  3
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_TXN_BANK_NO_LEADER_NO_MICROBLOCK_NAME "txn_bank_no_leader_no_microblock"
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_NO_TXN_NO_BANK_LEADER_NO_MICROBLOCK_IDX  4
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_NO_TXN_NO_BANK_LEADER_NO_MICROBLOCK_NAME "no_txn_no_bank_leader_no_microblock"
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_TXN_NO_BANK_LEADER_NO_MICROBLOCK_IDX  5
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_TXN_NO_BANK_LEADER_NO_MICROBLOCK_NAME "txn_no_bank_leader_no_microblock"
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_NO_TXN_BANK_LEADER_NO_MICROBLOCK_IDX  6
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_NO_TXN_BANK_LEADER_NO_MICROBLOCK_NAME "no_txn_bank_leader_no_microblock"
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_TXN_BANK_LEADER_NO_MICROBLOCK_IDX  7
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_TXN_BANK_LEADER_NO_MICROBLOCK_NAME "txn_bank_leader_no_microblock"
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_NO_TXN_NO_BANK_NO_LEADER_MICROBLOCK_IDX  8
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_NO_TXN_NO_BANK_NO_LEADER_MICROBLOCK_NAME "no_txn_no_bank_no_leader_microblock"
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_TXN_NO_BANK_NO_LEADER_MICROBLOCK_IDX  9
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_TXN_NO_BANK_NO_LEADER_MICROBLOCK_NAME "txn_no_bank_no_leader_microblock"
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_NO_TXN_BANK_NO_LEADER_MICROBLOCK_IDX  10
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_NO_TXN_BANK_NO_LEADER_MICROBLOCK_NAME "no_txn_bank_no_leader_microblock"
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_TXN_BANK_NO_LEADER_MICROBLOCK_IDX  11
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_TXN_BANK_NO_LEADER_MICROBLOCK_NAME "txn_bank_no_leader_microblock"
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_NO_TXN_NO_BANK_LEADER_MICROBLOCK_IDX  12
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_NO_TXN_NO_BANK_LEADER_MICROBLOCK_NAME "no_txn_no_bank_leader_microblock"
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_TXN_NO_BANK_LEADER_MICROBLOCK_IDX  13
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_TXN_NO_BANK_LEADER_MICROBLOCK_NAME "txn_no_bank_leader_microblock"
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_NO_TXN_BANK_LEADER_MICROBLOCK_IDX  14
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_NO_TXN_BANK_LEADER_MICROBLOCK_NAME "no_txn_bank_leader_microblock"
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_TXN_BANK_LEADER_MICROBLOCK_IDX  15
#define FD_METRICS_ENUM_PACK_TIMING_STATE_V_TXN_BANK_LEADER_MICROBLOCK_NAME "txn_bank_leader_microblock"

#define FD_METRICS_ENUM_AVAIL_TXN_TYPE_NAME "avail_txn_type"
#define FD_METRICS_ENUM_AVAIL_TXN_TYPE_V_ALL_IDX  0
#define FD_METRICS_ENUM_AVAIL_TXN_TYPE_V_ALL_NAME "all"
#define FD_METRICS_ENUM_AVAIL_TXN_TYPE_V_REGULAR_IDX  1
#define FD_METRICS_ENUM_AVAIL_TXN_TYPE_V_REGULAR_NAME "regular"
#define FD_METRICS_ENUM_AVAIL_TXN_TYPE_V_VOTES_IDX  2
#define FD_METRICS_ENUM_AVAIL_TXN_TYPE_V_VOTES_NAME "votes"
#define FD_METRICS_ENUM_AVAIL_TXN_TYPE_V_CONFLICTING_IDX  3
#define FD_METRICS_ENUM_AVAIL_TXN_TYPE_V_CONFLICTING_NAME "conflicting"
#define FD_METRICS_ENUM_AVAIL_TXN_TYPE_V_BUNDLES_IDX  4
#define FD_METRICS_ENUM_AVAIL_TXN_TYPE_V_BUNDLES_NAME "bundles"

#define FD_METRICS_ENUM_BANK_SLOT_ACQUIRE_NAME "bank_slot_acquire"
#define FD_METRICS_ENUM_BANK_SLOT_ACQUIRE_V_SUCCESS_IDX  0
#define FD_METRICS_ENUM_BANK_SLOT_ACQUIRE_V_SUCCESS_NAME "success"
#define FD_METRICS_ENUM_BANK_SLOT_ACQUIRE_V_TOO_HIGH_IDX  1
#define FD_METRICS_ENUM_BANK_SLOT_ACQUIRE_V_TOO_HIGH_NAME "too_high"
#define FD_METRICS_ENUM_BANK_SLOT_ACQUIRE_V_TOO_LOW_IDX  2
#define FD_METRICS_ENUM_BANK_SLOT_ACQUIRE_V_TOO_LOW_NAME "too_low"

#define FD_METRICS_ENUM_BANK_LOAD_ADDRESS_LOOKUP_TABLE_NAME "bank_load_address_lookup_table"
#define FD_METRICS_ENUM_BANK_LOAD_ADDRESS_LOOKUP_TABLE_V_SUCCESS_IDX  0
#define FD_METRICS_ENUM_BANK_LOAD_ADDRESS_LOOKUP_TABLE_V_SUCCESS_NAME "success"
#define FD_METRICS_ENUM_BANK_LOAD_ADDRESS_LOOKUP_TABLE_V_SLOT_HASHES_SYSVAR_NOT_FOUND_IDX  1
#define FD_METRICS_ENUM_BANK_LOAD_ADDRESS_LOOKUP_TABLE_V_SLOT_HASHES_SYSVAR_NOT_FOUND_NAME "slot_hashes_sysvar_not_found"
#define FD_METRICS_ENUM_BANK_LOAD_ADDRESS_LOOKUP_TABLE_V_ACCOUNT_NOT_FOUND_IDX  2
#define FD_METRICS_ENUM_BANK_LOAD_ADDRESS_LOOKUP_TABLE_V_ACCOUNT_NOT_FOUND_NAME "account_not_found"
#define FD_METRICS_ENUM_BANK_LOAD_ADDRESS_LOOKUP_TABLE_V_INVALID_ACCOUNT_OWNER_IDX  3
#define FD_METRICS_ENUM_BANK_LOAD_ADDRESS_LOOKUP_TABLE_V_INVALID_ACCOUNT_OWNER_NAME "invalid_account_owner"
#define FD_METRICS_ENUM_BANK_LOAD_ADDRESS_LOOKUP_TABLE_V_INVALID_ACCOUNT_DATA_IDX  4
#define FD_METRICS_ENUM_BANK_LOAD_ADDRESS_LOOKUP_TABLE_V_INVALID_ACCOUNT_DATA_NAME "invalid_account_data"
#define FD_METRICS_ENUM_BANK_LOAD_ADDRESS_LOOKUP_TABLE_V_INVALID_INDEX_IDX  5
#define FD_METRICS_ENUM_BANK_LOAD_ADDRESS_LOOKUP_TABLE_V_INVALID_INDEX_NAME "invalid_index"

#define FD_METRICS_ENUM_TRANSACTION_ERROR_NAME "transaction_error"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_SUCCESS_IDX  0
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_SUCCESS_NAME "success"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_ACCOUNT_IN_USE_IDX  1
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_ACCOUNT_IN_USE_NAME "account_in_use"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_ACCOUNT_LOADED_TWICE_IDX  2
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_ACCOUNT_LOADED_TWICE_NAME "account_loaded_twice"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_ACCOUNT_NOT_FOUND_IDX  3
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_ACCOUNT_NOT_FOUND_NAME "account_not_found"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_PROGRAM_ACCOUNT_NOT_FOUND_IDX  4
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_PROGRAM_ACCOUNT_NOT_FOUND_NAME "program_account_not_found"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_INSUFFICIENT_FUNDS_FOR_FEE_IDX  5
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_INSUFFICIENT_FUNDS_FOR_FEE_NAME "insufficient_funds_for_fee"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_INVALID_ACCOUNT_FOR_FEE_IDX  6
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_INVALID_ACCOUNT_FOR_FEE_NAME "invalid_account_for_fee"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_ALREADY_PROCESSED_IDX  7
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_ALREADY_PROCESSED_NAME "already_processed"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_BLOCKHASH_NOT_FOUND_IDX  8
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_BLOCKHASH_NOT_FOUND_NAME "blockhash_not_found"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_INSTRUCTION_ERROR_IDX  9
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_INSTRUCTION_ERROR_NAME "instruction_error"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_CALL_CHAIN_TOO_DEEP_IDX  10
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_CALL_CHAIN_TOO_DEEP_NAME "call_chain_too_deep"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_MISSING_SIGNATURE_FOR_FEE_IDX  11
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_MISSING_SIGNATURE_FOR_FEE_NAME "missing_signature_for_fee"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_INVALID_ACCOUNT_INDEX_IDX  12
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_INVALID_ACCOUNT_INDEX_NAME "invalid_account_index"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_SIGNATURE_FAILURE_IDX  13
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_SIGNATURE_FAILURE_NAME "signature_failure"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_INVALID_PROGRAM_FOR_EXECUTION_IDX  14
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_INVALID_PROGRAM_FOR_EXECUTION_NAME "invalid_program_for_execution"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_SANITIZE_FAILURE_IDX  15
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_SANITIZE_FAILURE_NAME "sanitize_failure"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_CLUSTER_MAINTENANCE_IDX  16
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_CLUSTER_MAINTENANCE_NAME "cluster_maintenance"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_ACCOUNT_BORROW_OUTSTANDING_IDX  17
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_ACCOUNT_BORROW_OUTSTANDING_NAME "account_borrow_outstanding"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_WOULD_EXCEED_MAX_BLOCK_COST_LIMIT_IDX  18
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_WOULD_EXCEED_MAX_BLOCK_COST_LIMIT_NAME "would_exceed_max_block_cost_limit"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_UNSUPPORTED_VERSION_IDX  19
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_UNSUPPORTED_VERSION_NAME "unsupported_version"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_INVALID_WRITABLE_ACCOUNT_IDX  20
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_INVALID_WRITABLE_ACCOUNT_NAME "invalid_writable_account"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_WOULD_EXCEED_MAX_ACCOUNT_COST_LIMIT_IDX  21
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_WOULD_EXCEED_MAX_ACCOUNT_COST_LIMIT_NAME "would_exceed_max_account_cost_limit"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_WOULD_EXCEED_ACCOUNT_DATA_BLOCK_LIMIT_IDX  22
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_WOULD_EXCEED_ACCOUNT_DATA_BLOCK_LIMIT_NAME "would_exceed_account_data_block_limit"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_TOO_MANY_ACCOUNT_LOCKS_IDX  23
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_TOO_MANY_ACCOUNT_LOCKS_NAME "too_many_account_locks"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_ADDRESS_LOOKUP_TABLE_NOT_FOUND_IDX  24
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_ADDRESS_LOOKUP_TABLE_NOT_FOUND_NAME "address_lookup_table_not_found"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_INVALID_ADDRESS_LOOKUP_TABLE_OWNER_IDX  25
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_INVALID_ADDRESS_LOOKUP_TABLE_OWNER_NAME "invalid_address_lookup_table_owner"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_INVALID_ADDRESS_LOOKUP_TABLE_DATA_IDX  26
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_INVALID_ADDRESS_LOOKUP_TABLE_DATA_NAME "invalid_address_lookup_table_data"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_INVALID_ADDRESS_LOOKUP_TABLE_INDEX_IDX  27
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_INVALID_ADDRESS_LOOKUP_TABLE_INDEX_NAME "invalid_address_lookup_table_index"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_INVALID_RENT_PAYING_ACCOUNT_IDX  28
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_INVALID_RENT_PAYING_ACCOUNT_NAME "invalid_rent_paying_account"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_WOULD_EXCEED_MAX_VOTE_COST_LIMIT_IDX  29
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_WOULD_EXCEED_MAX_VOTE_COST_LIMIT_NAME "would_exceed_max_vote_cost_limit"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_WOULD_EXCEED_ACCOUNT_DATA_TOTAL_LIMIT_IDX  30
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_WOULD_EXCEED_ACCOUNT_DATA_TOTAL_LIMIT_NAME "would_exceed_account_data_total_limit"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_DUPLICATE_INSTRUCTION_IDX  31
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_DUPLICATE_INSTRUCTION_NAME "duplicate_instruction"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_INSUFFICIENT_FUNDS_FOR_RENT_IDX  32
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_INSUFFICIENT_FUNDS_FOR_RENT_NAME "insufficient_funds_for_rent"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_MAX_LOADED_ACCOUNTS_DATA_SIZE_EXCEEDED_IDX  33
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_MAX_LOADED_ACCOUNTS_DATA_SIZE_EXCEEDED_NAME "max_loaded_accounts_data_size_exceeded"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_INVALID_LOADED_ACCOUNTS_DATA_SIZE_LIMIT_IDX  34
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_INVALID_LOADED_ACCOUNTS_DATA_SIZE_LIMIT_NAME "invalid_loaded_accounts_data_size_limit"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_RESANITIZATION_NEEDED_IDX  35
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_RESANITIZATION_NEEDED_NAME "resanitization_needed"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_PROGRAM_EXECUTION_TEMPORARILY_RESTRICTED_IDX  36
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_PROGRAM_EXECUTION_TEMPORARILY_RESTRICTED_NAME "program_execution_temporarily_restricted"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_UNBALANCED_TRANSACTION_IDX  37
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_UNBALANCED_TRANSACTION_NAME "unbalanced_transaction"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_PROGRAM_CACHE_HIT_MAX_LIMIT_IDX  38
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_PROGRAM_CACHE_HIT_MAX_LIMIT_NAME "program_cache_hit_max_limit"
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_BUNDLE_PEER_IDX  39
#define FD_METRICS_ENUM_TRANSACTION_ERROR_V_BUNDLE_PEER_NAME "bundle_peer"

#define FD_METRICS_ENUM_SHRED_PROCESSING_RESULT_NAME "shred_processing_result"
#define FD_METRICS_ENUM_SHRED_PROCESSING_RESULT_V_BAD_SLOT_IDX  0
#define FD_METRICS_ENUM_SHRED_PROCESSING_RESULT_V_BAD_SLOT_NAME "bad_slot"
#define FD_METRICS_ENUM_SHRED_PROCESSING_RESULT_V_PARSE_FAILED_IDX  1
#define FD_METRICS_ENUM_SHRED_PROCESSING_RESULT_V_PARSE_FAILED_NAME "parse_failed"
#define FD_METRICS_ENUM_SHRED_PROCESSING_RESULT_V_REJECTED_IDX  2
#define FD_METRICS_ENUM_SHRED_PROCESSING_RESULT_V_REJECTED_NAME "rejected"
#define FD_METRICS_ENUM_SHRED_PROCESSING_RESULT_V_IGNORED_IDX  3
#define FD_METRICS_ENUM_SHRED_PROCESSING_RESULT_V_IGNORED_NAME "ignored"
#define FD_METRICS_ENUM_SHRED_PROCESSING_RESULT_V_OKAY_IDX  4
#define FD_METRICS_ENUM_SHRED_PROCESSING_RESULT_V_OKAY_NAME "okay"
#define FD_METRICS_ENUM_SHRED_PROCESSING_RESULT_V_COMPLETES_IDX  5
#define FD_METRICS_ENUM_SHRED_PROCESSING_RESULT_V_COMPLETES_NAME "completes"

#define FD_METRICS_ENUM_GOSSIP_MESSAGE_NAME "gossip_message"
#define FD_METRICS_ENUM_GOSSIP_MESSAGE_V_PULL_REQUEST_IDX  0
#define FD_METRICS_ENUM_GOSSIP_MESSAGE_V_PULL_REQUEST_NAME "pull_request"
#define FD_METRICS_ENUM_GOSSIP_MESSAGE_V_PULL_RESPONSE_IDX  1
#define FD_METRICS_ENUM_GOSSIP_MESSAGE_V_PULL_RESPONSE_NAME "pull_response"
#define FD_METRICS_ENUM_GOSSIP_MESSAGE_V_PUSH_IDX  2
#define FD_METRICS_ENUM_GOSSIP_MESSAGE_V_PUSH_NAME "push"
#define FD_METRICS_ENUM_GOSSIP_MESSAGE_V_PRUNE_IDX  3
#define FD_METRICS_ENUM_GOSSIP_MESSAGE_V_PRUNE_NAME "prune"
#define FD_METRICS_ENUM_GOSSIP_MESSAGE_V_PING_IDX  4
#define FD_METRICS_ENUM_GOSSIP_MESSAGE_V_PING_NAME "ping"
#define FD_METRICS_ENUM_GOSSIP_MESSAGE_V_PONG_IDX  5
#define FD_METRICS_ENUM_GOSSIP_MESSAGE_V_PONG_NAME "pong"

#define FD_METRICS_ENUM_CRDS_VALUE_NAME "crds_value"
#define FD_METRICS_ENUM_CRDS_VALUE_V_CONTACT_INFO_V1_IDX  0
#define FD_METRICS_ENUM_CRDS_VALUE_V_CONTACT_INFO_V1_NAME "contact_info_v1"
#define FD_METRICS_ENUM_CRDS_VALUE_V_VOTE_IDX  1
#define FD_METRICS_ENUM_CRDS_VALUE_V_VOTE_NAME "vote"
#define FD_METRICS_ENUM_CRDS_VALUE_V_LOWEST_SLOT_IDX  2
#define FD_METRICS_ENUM_CRDS_VALUE_V_LOWEST_SLOT_NAME "lowest_slot"
#define FD_METRICS_ENUM_CRDS_VALUE_V_SNAPSHOT_HASHES_IDX  3
#define FD_METRICS_ENUM_CRDS_VALUE_V_SNAPSHOT_HASHES_NAME "snapshot_hashes"
#define FD_METRICS_ENUM_CRDS_VALUE_V_ACCOUNTS_HASHES_IDX  4
#define FD_METRICS_ENUM_CRDS_VALUE_V_ACCOUNTS_HASHES_NAME "accounts_hashes"
#define FD_METRICS_ENUM_CRDS_VALUE_V_EPOCH_SLOTS_IDX  5
#define FD_METRICS_ENUM_CRDS_VALUE_V_EPOCH_SLOTS_NAME "epoch_slots"
#define FD_METRICS_ENUM_CRDS_VALUE_V_VERSION_V1_IDX  6
#define FD_METRICS_ENUM_CRDS_VALUE_V_VERSION_V1_NAME "version_v1"
#define FD_METRICS_ENUM_CRDS_VALUE_V_VERSION_V2_IDX  7
#define FD_METRICS_ENUM_CRDS_VALUE_V_VERSION_V2_NAME "version_v2"
#define FD_METRICS_ENUM_CRDS_VALUE_V_NODE_INSTANCE_IDX  8
#define FD_METRICS_ENUM_CRDS_VALUE_V_NODE_INSTANCE_NAME "node_instance"
#define FD_METRICS_ENUM_CRDS_VALUE_V_DUPLICATE_SHRED_IDX  9
#define FD_METRICS_ENUM_CRDS_VALUE_V_DUPLICATE_SHRED_NAME "duplicate_shred"
#define FD_METRICS_ENUM_CRDS_VALUE_V_INCREMENTAL_SNAPSHOT_HASHES_IDX  10
#define FD_METRICS_ENUM_CRDS_VALUE_V_INCREMENTAL_SNAPSHOT_HASHES_NAME "incremental_snapshot_hashes"
#define FD_METRICS_ENUM_CRDS_VALUE_V_CONTACT_INFO_V2_IDX  11
#define FD_METRICS_ENUM_CRDS_VALUE_V_CONTACT_INFO_V2_NAME "contact_info_v2"
#define FD_METRICS_ENUM_CRDS_VALUE_V_RESTART_LAST_VOTED_FORK_SLOTS_IDX  12
#define FD_METRICS_ENUM_CRDS_VALUE_V_RESTART_LAST_VOTED_FORK_SLOTS_NAME "restart_last_voted_fork_slots"
#define FD_METRICS_ENUM_CRDS_VALUE_V_RESTART_HEAVIEST_FORK_IDX  13
#define FD_METRICS_ENUM_CRDS_VALUE_V_RESTART_HEAVIEST_FORK_NAME "restart_heaviest_fork"

#define FD_METRICS_ENUM_CRDS_DROP_REASON_NAME "crds_drop_reason"
#define FD_METRICS_ENUM_CRDS_DROP_REASON_V_SUCCESS_IDX  0
#define FD_METRICS_ENUM_CRDS_DROP_REASON_V_SUCCESS_NAME "success"
#define FD_METRICS_ENUM_CRDS_DROP_REASON_V_DUPLICATE_IDX  1
#define FD_METRICS_ENUM_CRDS_DROP_REASON_V_DUPLICATE_NAME "duplicate"
#define FD_METRICS_ENUM_CRDS_DROP_REASON_V_UNKNOWN_DISCRIMINANT_IDX  2
#define FD_METRICS_ENUM_CRDS_DROP_REASON_V_UNKNOWN_DISCRIMINANT_NAME "unknown_discriminant"
#define FD_METRICS_ENUM_CRDS_DROP_REASON_V_OWN_MESSAGE_IDX  3
#define FD_METRICS_ENUM_CRDS_DROP_REASON_V_OWN_MESSAGE_NAME "own_message"
#define FD_METRICS_ENUM_CRDS_DROP_REASON_V_INVALID_SIGNATURE_IDX  4
#define FD_METRICS_ENUM_CRDS_DROP_REASON_V_INVALID_SIGNATURE_NAME "invalid_signature"
#define FD_METRICS_ENUM_CRDS_DROP_REASON_V_TABLE_FULL_IDX  5
#define FD_METRICS_ENUM_CRDS_DROP_REASON_V_TABLE_FULL_NAME "table_full"
#define FD_METRICS_ENUM_CRDS_DROP_REASON_V_PUSH_QUEUE_FULL_IDX  6
#define FD_METRICS_ENUM_CRDS_DROP_REASON_V_PUSH_QUEUE_FULL_NAME "push_queue_full"
#define FD_METRICS_ENUM_CRDS_DROP_REASON_V_INVALID_GOSSIP_PORT_IDX  7
#define FD_METRICS_ENUM_CRDS_DROP_REASON_V_INVALID_GOSSIP_PORT_NAME "invalid_gossip_port"
#define FD_METRICS_ENUM_CRDS_DROP_REASON_V_PEER_TABLE_FULL_IDX  8
#define FD_METRICS_ENUM_CRDS_DROP_REASON_V_PEER_TABLE_FULL_NAME "peer_table_full"
#define FD_METRICS_ENUM_CRDS_DROP_REASON_V_INACTIVES_QUEUE_FULL_IDX  9
#define FD_METRICS_ENUM_CRDS_DROP_REASON_V_INACTIVES_QUEUE_FULL_NAME "inactives_queue_full"
#define FD_METRICS_ENUM_CRDS_DROP_REASON_V_DISCARDED_PEER_IDX  10
#define FD_METRICS_ENUM_CRDS_DROP_REASON_V_DISCARDED_PEER_NAME "discarded_peer"
#define FD_METRICS_ENUM_CRDS_DROP_REASON_V_ENCODING_FAILED_IDX  11
#define FD_METRICS_ENUM_CRDS_DROP_REASON_V_ENCODING_FAILED_NAME "encoding_failed"

#define FD_METRICS_ENUM_PULL_REQ_FAIL_REASON_NAME "pull_req_fail_reason"
#define FD_METRICS_ENUM_PULL_REQ_FAIL_REASON_V_PEER_NOT_IN_ACTIVES_IDX  0
#define FD_METRICS_ENUM_PULL_REQ_FAIL_REASON_V_PEER_NOT_IN_ACTIVES_NAME "peer_not_in_actives"
#define FD_METRICS_ENUM_PULL_REQ_FAIL_REASON_V_UNRESPONSIVE_PEER_IDX  1
#define FD_METRICS_ENUM_PULL_REQ_FAIL_REASON_V_UNRESPONSIVE_PEER_NAME "unresponsive_peer"
#define FD_METRICS_ENUM_PULL_REQ_FAIL_REASON_V_PENDING_POOL_FULL_IDX  2
#define FD_METRICS_ENUM_PULL_REQ_FAIL_REASON_V_PENDING_POOL_FULL_NAME "pending_pool_full"
#define FD_METRICS_ENUM_PULL_REQ_FAIL_REASON_V_ENCODING_FAILED_IDX  3
#define FD_METRICS_ENUM_PULL_REQ_FAIL_REASON_V_ENCODING_FAILED_NAME "encoding_failed"

#define FD_METRICS_ENUM_PULL_REQ_BLOOM_FILTER_RESULT_NAME "pull_req_bloom_filter_result"
#define FD_METRICS_ENUM_PULL_REQ_BLOOM_FILTER_RESULT_V_HIT_IDX  0
#define FD_METRICS_ENUM_PULL_REQ_BLOOM_FILTER_RESULT_V_HIT_NAME "hit"
#define FD_METRICS_ENUM_PULL_REQ_BLOOM_FILTER_RESULT_V_MISS_IDX  1
#define FD_METRICS_ENUM_PULL_REQ_BLOOM_FILTER_RESULT_V_MISS_NAME "miss"

#define FD_METRICS_ENUM_PEER_TYPES_NAME "peer_types"
#define FD_METRICS_ENUM_PEER_TYPES_V_TVU_IDX  0
#define FD_METRICS_ENUM_PEER_TYPES_V_TVU_NAME "tvu"
#define FD_METRICS_ENUM_PEER_TYPES_V_REPAIR_IDX  1
#define FD_METRICS_ENUM_PEER_TYPES_V_REPAIR_NAME "repair"
#define FD_METRICS_ENUM_PEER_TYPES_V_VOTER_IDX  2
#define FD_METRICS_ENUM_PEER_TYPES_V_VOTER_NAME "voter"

#define FD_METRICS_ENUM_PRUNE_FAILURE_REASON_NAME "prune_failure_reason"
#define FD_METRICS_ENUM_PRUNE_FAILURE_REASON_V_NOT_FOR_ME_IDX  0
#define FD_METRICS_ENUM_PRUNE_FAILURE_REASON_V_NOT_FOR_ME_NAME "not_for_me"
#define FD_METRICS_ENUM_PRUNE_FAILURE_REASON_V_SIGN_ENCODING_FAILED_IDX  1
#define FD_METRICS_ENUM_PRUNE_FAILURE_REASON_V_SIGN_ENCODING_FAILED_NAME "sign_encoding_failed"
#define FD_METRICS_ENUM_PRUNE_FAILURE_REASON_V_INVALID_SIGNATURE_IDX  2
#define FD_METRICS_ENUM_PRUNE_FAILURE_REASON_V_INVALID_SIGNATURE_NAME "invalid_signature"

#define FD_METRICS_ENUM_GOSSIP_PEER_STATE_NAME "gossip_peer_state"
#define FD_METRICS_ENUM_GOSSIP_PEER_STATE_V_TOTAL_IDX  0
#define FD_METRICS_ENUM_GOSSIP_PEER_STATE_V_TOTAL_NAME "total"
#define FD_METRICS_ENUM_GOSSIP_PEER_STATE_V_ACTIVE_IDX  1
#define FD_METRICS_ENUM_GOSSIP_PEER_STATE_V_ACTIVE_NAME "active"
#define FD_METRICS_ENUM_GOSSIP_PEER_STATE_V_INACTIVE_IDX  2
#define FD_METRICS_ENUM_GOSSIP_PEER_STATE_V_INACTIVE_NAME "inactive"

#define FD_METRICS_ENUM_RECV_PONG_EVENT_NAME "recv_pong_event"
#define FD_METRICS_ENUM_RECV_PONG_EVENT_V_NEW_PEER_IDX  0
#define FD_METRICS_ENUM_RECV_PONG_EVENT_V_NEW_PEER_NAME "new_peer"
#define FD_METRICS_ENUM_RECV_PONG_EVENT_V_WRONG_TOKEN_IDX  1
#define FD_METRICS_ENUM_RECV_PONG_EVENT_V_WRONG_TOKEN_NAME "wrong_token"
#define FD_METRICS_ENUM_RECV_PONG_EVENT_V_INVALID_SIGNATURE_IDX  2
#define FD_METRICS_ENUM_RECV_PONG_EVENT_V_INVALID_SIGNATURE_NAME "invalid_signature"
#define FD_METRICS_ENUM_RECV_PONG_EVENT_V_EXPIRED_IDX  3
#define FD_METRICS_ENUM_RECV_PONG_EVENT_V_EXPIRED_NAME "expired"
#define FD_METRICS_ENUM_RECV_PONG_EVENT_V_TABLE_FULL_IDX  4
#define FD_METRICS_ENUM_RECV_PONG_EVENT_V_TABLE_FULL_NAME "table_full"

#define FD_METRICS_ENUM_SEND_PING_EVENT_NAME "send_ping_event"
#define FD_METRICS_ENUM_SEND_PING_EVENT_V_ACTIVES_TABLE_FULL_IDX  0
#define FD_METRICS_ENUM_SEND_PING_EVENT_V_ACTIVES_TABLE_FULL_NAME "actives_table_full"
#define FD_METRICS_ENUM_SEND_PING_EVENT_V_ACTIVES_TABLE_INSERT_IDX  1
#define FD_METRICS_ENUM_SEND_PING_EVENT_V_ACTIVES_TABLE_INSERT_NAME "actives_table_insert"
#define FD_METRICS_ENUM_SEND_PING_EVENT_V_MAX_PING_COUNT_EXCEEDED_IDX  2
#define FD_METRICS_ENUM_SEND_PING_EVENT_V_MAX_PING_COUNT_EXCEEDED_NAME "max_ping_count_exceeded"

#define FD_METRICS_ENUM_MAKE_PRUNE_EVENT_NAME "make_prune_event"
#define FD_METRICS_ENUM_MAKE_PRUNE_EVENT_V_STALE_ENTRY_IDX  0
#define FD_METRICS_ENUM_MAKE_PRUNE_EVENT_V_STALE_ENTRY_NAME "stale_entry"
#define FD_METRICS_ENUM_MAKE_PRUNE_EVENT_V_HIGH_DUPLICATES_IDX  1
#define FD_METRICS_ENUM_MAKE_PRUNE_EVENT_V_HIGH_DUPLICATES_NAME "high_duplicates"
#define FD_METRICS_ENUM_MAKE_PRUNE_EVENT_V_ENCODING_FAILED_IDX  2
#define FD_METRICS_ENUM_MAKE_PRUNE_EVENT_V_ENCODING_FAILED_NAME "encoding_failed"

