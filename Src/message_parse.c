#include "message_parse.h"

void ParseMessage(uint8_t* buf, uint32_t* len) {
	if (*len > 1) return;

	send_encoder_val = (buf[0] == (uint8_t)'E');
}
