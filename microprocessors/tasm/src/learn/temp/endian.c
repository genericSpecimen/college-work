#include <stdio.h>
int main(void) {
	union {
		unsigned int word;  // a 32-bit integer
		unsigned char bytes[4];
	} u;
	u.word = 0x0A0B0C0D;
	for (int i = 0; i < 4; i++) {
		printf("byte[%d] = 0x%x\n", i, (int)u.bytes[i]);
	}
}
