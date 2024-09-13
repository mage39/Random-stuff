#include <stdint.h>
#include <stddef.h>
#include <string.h>
#define MASK 0x3F
void base64Encode (char* restrict dest, size_t destLen, char* restrict src, size_t srcLen) {
	const char table[] = {
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"0123456789+/"
	};
	if (srcLen % 3) {
		char err[] = {"\0PAD YOUR OWN STRINGS"};
		if (destLen > sizeof(err)) {
			strncpy(dest, err, sizeof(err));
			return;
		} else return;
	}
	for (uint32_t i = 0, j = 0; i < srcLen; i += 3) {
		uint32_t temp = 0;
		memcpy(&temp, src + i, 3);
		for (uint32_t k = 1; k < 5; j++, k++) {
			if (j >= destLen) {
				char err[] = {"\0DESTINATION TOO SMOL"};
				if (destLen > sizeof(err)) {
					strncpy(dest, err, sizeof(err));
					return;
				} else {
					dest[0] = 0;
					return;
				}
			}
			uint32_t offset = (MASK << 32 - 6 * k & temp) >> 32 - 6 * k;
			dest[j] = table[offset];
		}
	}
}
#undef MASK
