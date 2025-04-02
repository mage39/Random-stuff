#include <stdlib.h>
#include <stdbit.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <time.h>

#define forin(i, start, stop) for (unsigned i = (start); i < (stop); i++)

typedef unsigned uint;
static constexpr uint radix = 16;
static constexpr uint radixMask = radix - 1;
static constexpr uint radixMaskWidth = stdc_count_ones(radixMask);

void randList (size_t length, uint list[length]) {
	srand(time(NULL));
	forin(i, 0, length) list[i] = rand();
}

void printList (size_t length, uint list[length]) {
	for (uint i = 0; i < length;) {
		printf("%8X", list[i]);
		putchar((++i % 20) ? ' ' : '\n');
	}
	puts("");
}

static void pushBack (size_t length, uint list[length], uint start, uint end) {
	if (start >= end) return;
	size_t len = (end - start) * sizeof(int);
	uint* whence = list + start;
	if (list + length <= whence + len) return;
	memmove(whence + 1, whence, len);
}

static void fillBucket (size_t length, uint list[length], uint start, uint end, uint i, uint j) {
	forin(k, start, end) {
		forin(l, k, length) {
			uint match = list[l] & (radixMask << i * radixMaskWidth);
			if (match == j << i * radixMaskWidth) {
				uint t = list[l];
				pushBack(length, list, k, l);
				list[k] = t;
			}
		}
	}
}

void rsort (size_t length, uint list[length]) {
	forin(i, 0, sizeof(uint) * (CHAR_BIT / radixMaskWidth)) {
		uint buckets[radix] = {0};
		forin(j, 0, length) {
			uint match = list[j] & (radixMask << i * radixMaskWidth);
			buckets[match >> i * radixMaskWidth]++;
		}
		forin(j, 1, radix) buckets[j] += buckets[j - 1];
		if (*buckets) fillBucket(length, list, 0, *buckets, i, 0);
		forin(j, 1, radix) {
			if (buckets[j - 1] != buckets[j]) {
				fillBucket(length, list, buckets[j - 1], buckets[j], i, j);
			}
		}
		printList(length, list);
	}
}
