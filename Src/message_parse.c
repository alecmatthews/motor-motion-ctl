#include "message_parse.h"

#define NUMERIC_LENGTH 5

/* -- forward decelerations -- */
bool HeaderAligned(unsigned char *buf);

void ClearMessage();

long GetNum(unsigned char* buffer);

void SetupProcessor() {
	ClearMessage();
}

void ParseMessage(unsigned char *buf, unsigned int *len) {
	unsigned char *c_byte = buf;

	while (!HeaderAligned(c_byte))
		c_byte++;

	// ignore start bytes
	c_byte += 2;

	ClearMessage();
	// get message length
	current_message.len = *c_byte;

	c_byte++;
	current_message.id = *c_byte;

	if (current_message.len == NUMERIC_LENGTH) {
		c_byte++;
		current_message.numeric = GetNum(c_byte);
		return;
	}

	/* id meaning
	 * S - stop running
	 * R -continue running
	 * W - save constants to flash
	 * P - set p constant
	 * p - request p constant
	 * I - set i constant
	 * i - request i constant
	 * D - set d constant
	 * d - request d constants
	 * E - set desired encoder value
	 * e - request encoder value
	 */
	// these messages are the ones without a numeric payload.
	switch(current_message.id) {
	case 'S':
		current_message.isStop = true;
		break;
	case 'R':
		current_message.isStart = true;
		break;
	case 'W':
		current_message.isSave = true;
		break;
	default:
		break;
	}
}

bool HeaderAligned(unsigned char *buf) {
	return true;
}

void ClearMessage() {
	current_message.len = 0;
	current_message.id = '\0';
	current_message.numeric = -1;
	current_message.isStop = false;
	current_message.isStart = false;
	current_message.isSave = false;
	current_message.processed = false;
}

long GetNum(unsigned char* buffer) {
	// this is gonna be a gross mess
	long ret = 0;

	ret |= (*buffer) << 24;
	buffer++;
	ret |= (*buffer) << 16;
	buffer++;
	ret |= (*buffer) << 8;
	buffer++;
	ret |= (*buffer);

	return ret;
}
