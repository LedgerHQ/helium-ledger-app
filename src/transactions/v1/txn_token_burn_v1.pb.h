/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.0-dev */

#ifndef PB_HELIUM_TXNS_TXN_TOKEN_BURN_V1_PB_H_INCLUDED
#define PB_HELIUM_TXNS_TXN_TOKEN_BURN_V1_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _helium_txns_txn_token_burn_v1_Type {
    helium_txns_txn_token_burn_v1_Type_account = 0,
    helium_txns_txn_token_burn_v1_Type_channel = 1
} helium_txns_txn_token_burn_v1_Type;
#define _helium_txns_txn_token_burn_v1_Type_MIN helium_txns_txn_token_burn_v1_Type_account
#define _helium_txns_txn_token_burn_v1_Type_MAX helium_txns_txn_token_burn_v1_Type_channel
#define _helium_txns_txn_token_burn_v1_Type_ARRAYSIZE ((helium_txns_txn_token_burn_v1_Type)(helium_txns_txn_token_burn_v1_Type_channel+1))

/* Struct definitions */
typedef struct _helium_txns_txn_token_burn_v1 {
    helium_txns_txn_token_burn_v1_Type type;
    pb_callback_t payer;
    pb_callback_t key;
    uint64_t amount;
    uint64_t nonce;
    pb_callback_t signature;
/* @@protoc_insertion_point(struct:helium_txns_txn_token_burn_v1) */
} helium_txns_txn_token_burn_v1;


/* Initializer values for message structs */
#define helium_txns_txn_token_burn_v1_init_default {_helium_txns_txn_token_burn_v1_Type_MIN, {{NULL}, NULL}, {{NULL}, NULL}, 0, 0, {{NULL}, NULL}}
#define helium_txns_txn_token_burn_v1_init_zero  {_helium_txns_txn_token_burn_v1_Type_MIN, {{NULL}, NULL}, {{NULL}, NULL}, 0, 0, {{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define helium_txns_txn_token_burn_v1_type_tag   1
#define helium_txns_txn_token_burn_v1_payer_tag  2
#define helium_txns_txn_token_burn_v1_key_tag    3
#define helium_txns_txn_token_burn_v1_amount_tag 4
#define helium_txns_txn_token_burn_v1_nonce_tag  5
#define helium_txns_txn_token_burn_v1_signature_tag 6

/* Struct field encoding specification for nanopb */
#define helium_txns_txn_token_burn_v1_FIELDLIST(X, a) \
X(a, STATIC, SINGULAR, UENUM, type, 1) \
X(a, CALLBACK, SINGULAR, BYTES, payer, 2) \
X(a, CALLBACK, SINGULAR, BYTES, key, 3) \
X(a, STATIC, SINGULAR, UINT64, amount, 4) \
X(a, STATIC, SINGULAR, UINT64, nonce, 5) \
X(a, CALLBACK, SINGULAR, BYTES, signature, 6)
#define helium_txns_txn_token_burn_v1_CALLBACK pb_default_field_callback
#define helium_txns_txn_token_burn_v1_DEFAULT NULL

extern const pb_msgdesc_t helium_txns_txn_token_burn_v1_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define helium_txns_txn_token_burn_v1_fields &helium_txns_txn_token_burn_v1_msg

/* Maximum encoded size of messages (where known) */
/* helium_txns_txn_token_burn_v1_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif