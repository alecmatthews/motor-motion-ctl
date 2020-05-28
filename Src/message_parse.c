#include "message_parse.h"

#define NUMERIC_LENGTH 4

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
		current_message.numeric = GetNum(c_byte);
		return;
	}

	/* id meaning
	 * S - stop running
	 * R -continue running
	 * W - save constants to flash
	 * P - set p constant
	 * I - set i constant
	 * D - set d constant
	 * E - set desired encoder value
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
}

long GetNum(unsigned char* buffer) {
	// this is gonna be a gross mess
	// we have to change from big endian to little endian
	unsigned int b0, b1, b2, b3;

	b0 = (*buffer) >> 24;
	buffer++;
	b1 = (*buffer) >> 8;
	buffer++;
	b2 = (*buffer) << 8;
	buffer++;
	b3 = (*buffer) << 24;

	return (b0 | b1 | b2 | b3);
}
