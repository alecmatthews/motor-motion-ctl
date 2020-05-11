/** message_parese.h
 * This file is used to parse incoming USB messages from a host PC
 *
 * @author Alec Matthews <alec\@quailnet.net>
 */

#ifndef MESSAGE_PARSE
#define MESSAGE_PARSE

#include <stdbool.h>

#include "stm32g4xx_hal.h"

bool send_encoder_val;

/** Parse new USB messages */
void ParseMessage(uint8_t* buf, uint32_t* len);

#endif /* MESSAGE_PARSE */
