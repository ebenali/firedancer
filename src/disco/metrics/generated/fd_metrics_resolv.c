/* THIS FILE IS GENERATED BY gen_metrics.py. DO NOT HAND EDIT. */
#include "fd_metrics_resolv.h"

const fd_metrics_meta_t FD_METRICS_RESOLV[FD_METRICS_RESOLV_TOTAL] = {
    DECLARE_METRIC( RESOLV_NO_BANK_DROP, COUNTER ),
    DECLARE_METRIC_ENUM( RESOLV_STASH_OPERATION, COUNTER, RESOLVE_STASH_OPERATION, INSERTED ),
    DECLARE_METRIC_ENUM( RESOLV_STASH_OPERATION, COUNTER, RESOLVE_STASH_OPERATION, OVERRUN ),
    DECLARE_METRIC_ENUM( RESOLV_STASH_OPERATION, COUNTER, RESOLVE_STASH_OPERATION, PUBLISHED ),
    DECLARE_METRIC_ENUM( RESOLV_STASH_OPERATION, COUNTER, RESOLVE_STASH_OPERATION, REMOVED ),
    DECLARE_METRIC_ENUM( RESOLV_LUT_RESOLVED, COUNTER, LUT_RESOLVE_RESULT, INVALID_LOOKUP_INDEX ),
    DECLARE_METRIC_ENUM( RESOLV_LUT_RESOLVED, COUNTER, LUT_RESOLVE_RESULT, ACCOUNT_UNINITIALIZED ),
    DECLARE_METRIC_ENUM( RESOLV_LUT_RESOLVED, COUNTER, LUT_RESOLVE_RESULT, INVALID_ACCOUNT_DATA ),
    DECLARE_METRIC_ENUM( RESOLV_LUT_RESOLVED, COUNTER, LUT_RESOLVE_RESULT, INVALID_ACCOUNT_OWNER ),
    DECLARE_METRIC_ENUM( RESOLV_LUT_RESOLVED, COUNTER, LUT_RESOLVE_RESULT, ACCOUNT_NOT_FOUND ),
    DECLARE_METRIC_ENUM( RESOLV_LUT_RESOLVED, COUNTER, LUT_RESOLVE_RESULT, SUCCESS ),
    DECLARE_METRIC( RESOLV_BLOCKHASH_EXPIRED, COUNTER ),
    DECLARE_METRIC( RESOLV_TRANSACTION_BUNDLE_PEER_FAILURE, COUNTER ),
};
