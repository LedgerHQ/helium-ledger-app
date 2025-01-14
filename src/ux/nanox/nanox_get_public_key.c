#include "bolos_target.h"

#ifdef HAVE_UX_FLOW

#include <stdint.h>
#include <os.h>
#include <cx.h>
#include "helium.h"
#include "helium_ux.h"
#include "nanox_error.h"

#define CTX cmd.getPublicKeyContext

static uint16_t adpu_tx;

static void flush_key()
{
  io_exchange_with_code(SW_OK, adpu_tx);
  ui_idle();
}


UX_FLOW_DEF_VALID(
    ux_display_public_flow_1_step, 
    bnnn_paging,
    flush_key(),
    {
      .title = (char *)global.title,
      .text = (char *)global.fullStr
    });


UX_DEF(ux_display_public_flow,
  &ux_display_public_flow_1_step
);

void ui_getPublicKey(void)
{
  if(G_ux.stack_count == 0) {
    ux_stack_push();
  }
  ux_flow_init(0, ux_display_public_flow, NULL);
}

// handleGetPublicKey is the entry point for the getPublicKey command. It
// reads the command parameters, prepares and displays the approval screen,
// and 
void handle_get_public_key(uint8_t p1, uint8_t p2,
                           __attribute__((unused)) uint8_t *dataBuffer,
                           __attribute__((unused)) uint16_t dataLength,
                           __attribute__((unused)) volatile unsigned int *flags,
                           __attribute__((unused)) volatile unsigned int *tx) {
	size_t output_len;
    adpu_tx = 2;
	// Sanity-check the command parameters.
	if ((p1 != P1_PUBKEY_DISPLAY_ON) && (p1 != P1_PUBKEY_DISPLAY_OFF)) {
		THROW(SW_INVALID_PARAM);
	}

	G_io_apdu_buffer[0] = 0; // prepend 0 byte to signify b58 format
#ifdef HELIUM_TESTNET
	G_io_apdu_buffer[1] = NETTYPE_TEST | KEYTYPE_ED25519;
#else
	G_io_apdu_buffer[1] = NETTYPE_MAIN | KEYTYPE_ED25519;
#endif
	global.account_index = p2;
	get_pubkey_bytes(global.account_index, &G_io_apdu_buffer[adpu_tx]);
	adpu_tx += SIZE_OF_PUB_KEY_BIN;

	cx_sha256_t hash;
	unsigned char hash_buffer[32];

    for(uint8_t i=0; i<2; i++) {
        if (global.account_index < 10) {
            global.title_len = sizeof("Confirm Wallet N\0");
            memcpy(global.title, &"Confirm Wallet N\0", global.title_len);
            global.title[global.title_len - 3] = global.account_index + 48;
        } else if (global.account_index < 100) {
            global.title_len = sizeof("Confirm Wallet NN\0");
            memcpy(global.title, &"Confirm Wallet NN\0", global.title_len);
            global.title[global.title_len - 4] = global.account_index/10 + 48;
            global.title[global.title_len - 3] = global.account_index%10 + 48;
        } else {
            global.title_len = sizeof("Confirm Wallet NNN\0");
            memcpy(global.title, &"Confirm Wallet NNN\0", global.title_len);
            global.title[global.title_len - 5] = global.account_index/100 + 48;
            global.title[global.title_len - 4] = global.account_index%100/10 + 48;
            global.title[global.title_len - 3] = global.account_index%10 + 48;
        }
    }

	if (p1 == P1_PUBKEY_DISPLAY_ON) {
	  cx_sha256_init(&hash);
	  cx_hash(&hash.header, CX_LAST, G_io_apdu_buffer, adpu_tx, hash_buffer, 32);
	  cx_sha256_init(&hash);
	  cx_hash(&hash.header, CX_LAST, hash_buffer, 32, hash_buffer, 32);

	  memmove(&G_io_apdu_buffer[adpu_tx], hash_buffer, SIZE_OF_SHA_CHECKSUM);
	  adpu_tx += SIZE_OF_SHA_CHECKSUM;

	  // Encoding key as a base58 string
	  btchip_encode_base58(G_io_apdu_buffer, adpu_tx, global.fullStr, &output_len);
      btchip_encode_base58(G_io_apdu_buffer, adpu_tx, global.fullStr, &output_len);
	  global.fullStr[51] = '\0';

	  // Running the flow showing the pubkey in the screen
	  ui_getPublicKey();

	  *flags |= IO_ASYNCH_REPLY;
	} else {
        // Flush the APDU buffer, sending the response.
	    io_exchange_with_code(SW_OK, adpu_tx);
    }
}

#endif
