/** message_parese.h
 * This file is used to parse incoming USB messages from a host PC
 *
 * @author Alec Matthews <alec\@quailnet.net>
 */

#ifndef MESSAGE_PARSE
#define MESSAGE_PARSE

#include <stdbool.h>

typedef struct msg {
	unsigned char len; /* Message length */
	char id; /* Message identifying character. */
	long numeric; /* Contains number if the message was numeric. */
	bool isStop; /* True if messes was stop command. */
	bool isStart; /* True if message was start command. */
	bool isSave; /* True if message was save command. */
	bool processed; /* True if the message has already been delt with. */
} MESSAGE;

/* Since only one message can be processed at a time on an MCU platform
 * we will make it global. */
MESSAGE current_message;

/* Setup all memory used by the message processor. This must be called before
 * any other uses of ParseMessage.
 */
void SetupProcessor();

/** Parse new USB messages */
void ParseMessage(unsigned char *buf, unsigned int *len);

#endif /* MESSAGE_PARSE */
