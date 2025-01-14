/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.6-dev */

#ifndef PB_BLOCKCHAIN_GOSSIP_HANDLER_PB_H_INCLUDED
#define PB_BLOCKCHAIN_GOSSIP_HANDLER_PB_H_INCLUDED
#include <pb.h>

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
typedef struct _blockchain_gossip_block { 
    pb_callback_t from; 
    pb_callback_t block; 
    pb_callback_t hash; 
    uint64_t height; 
} blockchain_gossip_block;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define blockchain_gossip_block_init_default     {{{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, 0}
#define blockchain_gossip_block_init_zero        {{{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}, 0}

/* Field tags (for use in manual encoding/decoding) */
#define blockchain_gossip_block_from_tag         1
#define blockchain_gossip_block_block_tag        2
#define blockchain_gossip_block_hash_tag         3
#define blockchain_gossip_block_height_tag       4

/* Struct field encoding specification for nanopb */
#define blockchain_gossip_block_FIELDLIST(X, a) \
X(a, CALLBACK, SINGULAR, BYTES,    from,              1) \
X(a, CALLBACK, SINGULAR, BYTES,    block,             2) \
X(a, CALLBACK, SINGULAR, BYTES,    hash,              3) \
X(a, STATIC,   SINGULAR, UINT64,   height,            4)
#define blockchain_gossip_block_CALLBACK pb_default_field_callback
#define blockchain_gossip_block_DEFAULT NULL

extern const pb_msgdesc_t blockchain_gossip_block_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define blockchain_gossip_block_fields &blockchain_gossip_block_msg

/* Maximum encoded size of messages (where known) */
/* blockchain_gossip_block_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
