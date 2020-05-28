/* message_send.h
 * produce the message buffers that are used to send messages to the PC host.
 *
 * @author Alec Matthews <alec\@quailnet.net>
 */

#define SEND_BUF_LEN 30
#define START_1 0
#define START_2 1
#define LEN 2
#define ID 3

/* global send buffer */
unsigned char send_buf[SEND_BUF_LEN];

/** Place the correct message in the buffer to send the encoder value.
 * @returns the total length of the message in the buffer.
 */
int SendEncoder(int encoder_val);

/** Place the correct message in the buffer to send the kp value.
 * @returns the total length of the message in the buffer.
 */
int SendKP(int kp);

/** Place the correct message in the buffer to send the ki value.
 * @returns the total length of the message in the buffer.
 */
int SendKI(int ki);

/** Place the correct message in the buffer to send the kd value.
 * @returns the total length of the message in the buffer.
 */
int SendKD(int kd);
