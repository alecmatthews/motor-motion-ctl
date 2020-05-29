#include "message_send.h"

#include <stdlib.h>
#include <string.h>

/* forward decelerations */
void ClearBuffer();

void CopyStart();

void CopyInt(unsigned char *start_ptr, int val);

int SendEncoder(int encoder_val) {
	// encoder value can range from 0 - 360000
	ClearBuffer();
	CopyStart();
	send_buf[LEN] = 5;
	send_buf[ID] = 'e';
	CopyInt(send_buf + ID + 1, encoder_val);

	return 8;
}

int SendKP(int kp) {
	ClearBuffer();
	CopyStart();
	send_buf[LEN] = 5;
	send_buf[ID] = 'p';
	CopyInt(send_buf + ID + 1, kp);

	return 8;
}

int SendKI(int ki) {
	ClearBuffer();
	CopyStart();
	send_buf[LEN] = 5;
	send_buf[ID] = 'i';
	CopyInt(send_buf + ID + 1, ki);

	return 8;
}

int SendKD(int kd) {
	ClearBuffer();
	CopyStart();
	send_buf[LEN] = 5;
	send_buf[ID] = 'd';
	CopyInt(send_buf + ID + 1, kd);

	return 8;
}

void ClearBuffer() {
	memset(send_buf, 0, SEND_BUF_LEN);
}

void CopyStart() {
	send_buf[START_1] = 0x55;
	send_buf[START_2] = 0xAA;
}

void CopyInt(unsigned char *start_ptr, int val) {
	*start_ptr = val >> 24;
	*(++start_ptr) = (val >> 16) & 0xFF;
	*(++start_ptr) = (val >> 8) & 0xFF;
	*(++start_ptr) = val & 0xFF;
}
