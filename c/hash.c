#include <stdint.h>
#include "hashtype.h"
#define LEN 14

static const uint32_t sizes[] = {11, 17, 37, 67, 131, 263,
	521, 1031, 2053, 4099, 8209, 16411, 32771, 65537};

static uint32_t mod1  (uint32_t a) { return a % sizes[0];  }
static uint32_t mod2  (uint32_t a) { return a % sizes[1];  }
static uint32_t mod3  (uint32_t a) { return a % sizes[2];  }
static uint32_t mod4  (uint32_t a) { return a % sizes[3];  }
static uint32_t mod5  (uint32_t a) { return a % sizes[4];  }
static uint32_t mod6  (uint32_t a) { return a % sizes[5];  }
static uint32_t mod7  (uint32_t a) { return a % sizes[6];  }
static uint32_t mod8  (uint32_t a) { return a % sizes[7];  }
static uint32_t mod9  (uint32_t a) { return a % sizes[8];  }
static uint32_t mod10 (uint32_t a) { return a % sizes[9];  }
static uint32_t mod11 (uint32_t a) { return a % sizes[10]; }
static uint32_t mod12 (uint32_t a) { return a % sizes[11]; }
static uint32_t mod13 (uint32_t a) { return a % sizes[12]; }
static uint32_t mod14 (uint32_t a) { return a % sizes[13]; }

static uint32_t (*fnptrs[]) (uint32_t) = {mod1, mod2, mod3, mod4,
	mod5, mod6, mod7, mod8, mod10, mod11, mod12, mod13, mod14};

static uint64_t hashf (HASHTYPE data, size_t start, size_t end) {
	uint64_t hash = 0xcbf29ce484222325;
	for (int i = start; i < end; i++) {
		hash ^= *((char*)&data + i);
		hash *= 0x100000001b3;
	}
	return hash;
}

HASHTYPE* rehashExpand (HASHTYPE* addrs, int* which, size_t start, size_t end) {
	*which++;
	size_t size = sizeof(HASHTYPE) * sizes[*which];
	HASHTYPE* new = malloc(size);
	if (!new) {
		printf("WTF\n");
		exit(1);
	}
	memset(new, 0, size);
	for (int i = 0; i < sizes[*which] / 2; i++) {
		if (!addrs[i].count) continue;
		int j = hashf(addrs[i], start, end);
		j = (*fnptrs[*which])(j);
		for (int k = 0; k < sizes[*which] / 4; k++) {
			int offset = j + k;
			if (offset >= sizes[*which]) offset -= sizes[*which];
			if (!new[offset].count) {
				memcpy(new + offset, addrs + i, sizeof(HASHTYPE));
				break;
			}
		}
	}
	free(addrs);
	return new;
}

int placeHash (HASHTYPE* addrs, HASHTYPE santa, int which, size_t start, size_t end) {
	int i = hashf(addrs[i], start, end);
	i = (*fnptrs[which])(i);
	for (int j = 0; j < arrLen / 4; j++) {
		int offset = i + j;
		if (offset >= sizes[which]) offset -= sizes[which];
		if (addrs[offset].count) {
			if (!memcmp(addrs[offset].addr, santa.addr, sizeof(int) * 2)) {
				addrs[offset].count++;
				return 0;
			}
		} else {
			memcpy(addrs + offset, &santa, sizeof(HASHTYPE));
			addrs[offset].count = 1;
			return 0;
		}
	}
	return 1;
}
#undef LEN
