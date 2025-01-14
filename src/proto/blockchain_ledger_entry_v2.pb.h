/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.6-dev */

#ifndef PB_HELIUM_BLOCKCHAIN_LEDGER_ENTRY_V2_PB_H_INCLUDED
#define PB_HELIUM_BLOCKCHAIN_LEDGER_ENTRY_V2_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
typedef struct _helium_blockchain_ledger_entry_v2 { /* NOTE: might need to add owner:binary here for portability reasons,
 leaving that out for now to revisit later. */
    /* Top level nonce since entry-specific nonces don't really matter */
    uint64_t nonce; 
    uint64_t hnt_balance; 
    uint64_t hst_balance; 
    uint64_t mobile_balance; 
    uint64_t iot_balance; 
} helium_blockchain_ledger_entry_v2;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define helium_blockchain_ledger_entry_v2_init_default {0, 0, 0, 0, 0}
#define helium_blockchain_ledger_entry_v2_init_zero {0, 0, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define helium_blockchain_ledger_entry_v2_nonce_tag 1
#define helium_blockchain_ledger_entry_v2_hnt_balance_tag 2
#define helium_blockchain_ledger_entry_v2_hst_balance_tag 3
#define helium_blockchain_ledger_entry_v2_mobile_balance_tag 4
#define helium_blockchain_ledger_entry_v2_iot_balance_tag 5

/* Struct field encoding specification for nanopb */
#define helium_blockchain_ledger_entry_v2_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT64,   nonce,             1) \
X(a, STATIC,   SINGULAR, UINT64,   hnt_balance,       2) \
X(a, STATIC,   SINGULAR, UINT64,   hst_balance,       3) \
X(a, STATIC,   SINGULAR, UINT64,   mobile_balance,    4) \
X(a, STATIC,   SINGULAR, UINT64,   iot_balance,       5)
#define helium_blockchain_ledger_entry_v2_CALLBACK NULL
#define helium_blockchain_ledger_entry_v2_DEFAULT NULL

extern const pb_msgdesc_t helium_blockchain_ledger_entry_v2_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define helium_blockchain_ledger_entry_v2_fields &helium_blockchain_ledger_entry_v2_msg

/* Maximum encoded size of messages (where known) */
#define helium_blockchain_ledger_entry_v2_size   55

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
