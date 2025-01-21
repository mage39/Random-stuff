#include <stdlib.h>
#include <stdbit.h>
#include <limits.h>
#include <stdio.h>
#include <time.h>

#define forin(i, start, stop) for (unsigned i = (start); i < (stop); i++)

typedef unsigned uint;
static constexpr uint radix = 16;
static constexpr uint radixMask = radix - 1;
static constexpr uint radixMaskWidth = stdc_count_ones(radixMask);

void randList (uint* list, size_t length) {
	srand(time(NULL));
	forin(i, 0, length) list[i] = rand();
}

void printList (uint* list, size_t length) {
	for (uint i = 0; i < length;) {
		printf("%8X", list[i]);
		putchar((++i % 20) ? ' ' : '\n');
	}
	puts("");
}

static void checkAndSwap (uint* a, uint* b, uint i, uint j) {
	if ((*b & radixMask << i * radixMaskWidth) == j << i * radixMaskWidth) {
		uint s = *a;
		*a = *b;
		*b = s;
	}
}

static void fillBucket (uint* list, uint length, uint start, uint end, uint i, uint j) {
	forin(k, start, end) {
		forin(l, start, length) {
			checkAndSwap(&list[k], &list[l], i, j);
			break;
		}
	}
}

void rsort (uint* list, size_t length) {
	forin(i, 0, sizeof(uint) * (CHAR_BIT / radixMaskWidth)) {
		uint buckets[radix] = {0};
		forin(j, 0, length) {
			uint match = list[j] & radixMask << i * radixMaskWidth;
			buckets[match >> i * radixMaskWidth]++;
		}
		forin(j, 1, radix) buckets[j] += buckets[j - 1];
		if (*buckets) fillBucket(list, length, 0, *buckets, i, 0);
		forin(j, 1, radix) {
			if (buckets[j - 1] != buckets[j]) {
				fillBucket(list, length, buckets[j - 1], buckets[j], i, j);
			}
		}
	}
}
