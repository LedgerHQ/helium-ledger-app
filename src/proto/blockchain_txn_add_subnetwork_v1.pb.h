/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.6-dev */

#ifndef PB_HELIUM_BLOCKCHAIN_TXN_ADD_SUBNETWORK_V1_PB_H_INCLUDED
#define PB_HELIUM_BLOCKCHAIN_TXN_ADD_SUBNETWORK_V1_PB_H_INCLUDED
#include <pb.h>
#include "blockchain_token_type_v1.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
typedef struct _helium_blockchain_txn_add_subnetwork_v1 { 
    helium_blockchain_token_type_v1 token_type; 
    pb_callback_t subnetwork_key; 
    pb_callback_t reward_server_keys; 
    uint64_t premine; 
    pb_callback_t network_signature; 
    pb_callback_t subnetwork_signature; 
} helium_blockchain_txn_add_subnetwork_v1;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define helium_blockchain_txn_add_subnetwork_v1_init_default {_helium_blockchain_token_type_v1_MIN, {{NULL}, NULL}, {{NULL}, NULL}, 0, {{NULL}, NULL}, {{NULL}, NULL}}
#define helium_blockchain_txn_add_subnetwork_v1_init_zero {_helium_blockchain_token_type_v1_MIN, {{NULL}, NULL}, {{NULL}, NULL}, 0, {{NULL}, NULL}, {{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define helium_blockchain_txn_add_subnetwork_v1_token_type_tag 1
#define helium_blockchain_txn_add_subnetwork_v1_subnetwork_key_tag 2
#define helium_blockchain_txn_add_subnetwork_v1_reward_server_keys_tag 3
#define helium_blockchain_txn_add_subnetwork_v1_premine_tag 4
#define helium_blockchain_txn_add_subnetwork_v1_network_signature_tag 5
#define helium_blockchain_txn_add_subnetwork_v1_subnetwork_signature_tag 6

/* Struct field encoding specification for nanopb */
#define helium_blockchain_txn_add_subnetwork_v1_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    token_type,        1) \
X(a, CALLBACK, SINGULAR, BYTES,    subnetwork_key,    2) \
X(a, CALLBACK, REPEATED, BYTES,    reward_server_keys,   3) \
X(a, STATIC,   SINGULAR, UINT64,   premine,           4) \
X(a, CALLBACK, SINGULAR, BYTES,    network_signature,   5) \
X(a, CALLBACK, SINGULAR, BYTES,    subnetwork_signature,   6)
#define helium_blockchain_txn_add_subnetwork_v1_CALLBACK pb_default_field_callback
#define helium_blockchain_txn_add_subnetwork_v1_DEFAULT NULL

extern const pb_msgdesc_t helium_blockchain_txn_add_subnetwork_v1_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define helium_blockchain_txn_add_subnetwork_v1_fields &helium_blockchain_txn_add_subnetwork_v1_msg

/* Maximum encoded size of messages (where known) */
/* helium_blockchain_txn_add_subnetwork_v1_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
