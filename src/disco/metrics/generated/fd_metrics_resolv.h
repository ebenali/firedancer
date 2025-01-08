/* THIS FILE IS GENERATED BY gen_metrics.py. DO NOT HAND EDIT. */

#include "../fd_metrics_base.h"
#include "fd_metrics_enums.h"

#define FD_METRICS_COUNTER_RESOLV_NO_BANK_DROP_OFF  (16UL)
#define FD_METRICS_COUNTER_RESOLV_NO_BANK_DROP_NAME "resolv_no_bank_drop"
#define FD_METRICS_COUNTER_RESOLV_NO_BANK_DROP_TYPE (FD_METRICS_TYPE_COUNTER)
#define FD_METRICS_COUNTER_RESOLV_NO_BANK_DROP_DESC "Count of transactions dropped because the bank was not available"
#define FD_METRICS_COUNTER_RESOLV_NO_BANK_DROP_CVT  (FD_METRICS_CONVERTER_NONE)

#define FD_METRICS_COUNTER_RESOLV_STASH_OPERATION_OFF  (17UL)
#define FD_METRICS_COUNTER_RESOLV_STASH_OPERATION_NAME "resolv_stash_operation"
#define FD_METRICS_COUNTER_RESOLV_STASH_OPERATION_TYPE (FD_METRICS_TYPE_COUNTER)
#define FD_METRICS_COUNTER_RESOLV_STASH_OPERATION_DESC "Count of operations that happened on the transaction stash"
#define FD_METRICS_COUNTER_RESOLV_STASH_OPERATION_CVT  (FD_METRICS_CONVERTER_NONE)
#define FD_METRICS_COUNTER_RESOLV_STASH_OPERATION_CNT  (4UL)

#define FD_METRICS_COUNTER_RESOLV_STASH_OPERATION_INSERTED_OFF (17UL)
#define FD_METRICS_COUNTER_RESOLV_STASH_OPERATION_OVERRUN_OFF (18UL)
#define FD_METRICS_COUNTER_RESOLV_STASH_OPERATION_PUBLISHED_OFF (19UL)
#define FD_METRICS_COUNTER_RESOLV_STASH_OPERATION_REMOVED_OFF (20UL)

#define FD_METRICS_COUNTER_RESOLV_LUT_RESOLVED_OFF  (21UL)
#define FD_METRICS_COUNTER_RESOLV_LUT_RESOLVED_NAME "resolv_lut_resolved"
#define FD_METRICS_COUNTER_RESOLV_LUT_RESOLVED_TYPE (FD_METRICS_TYPE_COUNTER)
#define FD_METRICS_COUNTER_RESOLV_LUT_RESOLVED_DESC "Count of address lookup tables resolved"
#define FD_METRICS_COUNTER_RESOLV_LUT_RESOLVED_CVT  (FD_METRICS_CONVERTER_NONE)
#define FD_METRICS_COUNTER_RESOLV_LUT_RESOLVED_CNT  (6UL)

#define FD_METRICS_COUNTER_RESOLV_LUT_RESOLVED_INVALID_LOOKUP_INDEX_OFF (21UL)
#define FD_METRICS_COUNTER_RESOLV_LUT_RESOLVED_ACCOUNT_UNINITIALIZED_OFF (22UL)
#define FD_METRICS_COUNTER_RESOLV_LUT_RESOLVED_INVALID_ACCOUNT_DATA_OFF (23UL)
#define FD_METRICS_COUNTER_RESOLV_LUT_RESOLVED_INVALID_ACCOUNT_OWNER_OFF (24UL)
#define FD_METRICS_COUNTER_RESOLV_LUT_RESOLVED_ACCOUNT_NOT_FOUND_OFF (25UL)
#define FD_METRICS_COUNTER_RESOLV_LUT_RESOLVED_SUCCESS_OFF (26UL)

#define FD_METRICS_COUNTER_RESOLV_BLOCKHASH_EXPIRED_OFF  (27UL)
#define FD_METRICS_COUNTER_RESOLV_BLOCKHASH_EXPIRED_NAME "resolv_blockhash_expired"
#define FD_METRICS_COUNTER_RESOLV_BLOCKHASH_EXPIRED_TYPE (FD_METRICS_TYPE_COUNTER)
#define FD_METRICS_COUNTER_RESOLV_BLOCKHASH_EXPIRED_DESC "Count of transactions that failed to resolve because the blockhash was expired"
#define FD_METRICS_COUNTER_RESOLV_BLOCKHASH_EXPIRED_CVT  (FD_METRICS_CONVERTER_NONE)

#define FD_METRICS_COUNTER_RESOLV_TRANSACTION_BUNDLE_PEER_FAILURE_OFF  (28UL)
#define FD_METRICS_COUNTER_RESOLV_TRANSACTION_BUNDLE_PEER_FAILURE_NAME "resolv_transaction_bundle_peer_failure"
#define FD_METRICS_COUNTER_RESOLV_TRANSACTION_BUNDLE_PEER_FAILURE_TYPE (FD_METRICS_TYPE_COUNTER)
#define FD_METRICS_COUNTER_RESOLV_TRANSACTION_BUNDLE_PEER_FAILURE_DESC "Count of transactions that failed to resolve because a peer transaction in the bundle failed"
#define FD_METRICS_COUNTER_RESOLV_TRANSACTION_BUNDLE_PEER_FAILURE_CVT  (FD_METRICS_CONVERTER_NONE)

#define FD_METRICS_RESOLV_TOTAL (13UL)
extern const fd_metrics_meta_t FD_METRICS_RESOLV[FD_METRICS_RESOLV_TOTAL];
