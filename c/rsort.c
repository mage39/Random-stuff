#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "defines.h"

typedef unsigned uint;
static constexpr uint radixMask = 0xF;

void randList (uint* list, size_t length) {
	srand(time(NULL));
	for (uint i = 0; i < length; i++) list[i] = rand();
}

void printList (uint* list, size_t length) {
	for (uint i = 0; i < length;) {
		printf("%8X", list[i]);
		putchar((++i % 20) ? ' ' : '\n');
	}
}

static void checkAndSwap (uint* a, uint* b, uint i, uint j) {
	// this is for branchless shenanigans, maybe
	bool test = (*b & radixMask << i * 4) == j << i * 4;
	if (test) {
		uint s = *a;
		*a = *b;
		*b = s;
	}
}

static void fillBucket (uint* list, uint length, uint start, uint end, uint i, uint j) { 
	forin(k, start, end) forin(l, start, length) {
		checkAndSwap(&list[k], &list[l], i, j);
	}
}

void rsort (uint* list, size_t length) {
	constexpr uint radix = 16;
	forin(i, 0, sizeof(uint) * 2) {
		// ^ the third expression would be qsort's `size` argument
		uint buckets[radix] = {0};
		forin(j, 0, length) buckets[(list[j] & radixMask << i * 4) >> i * 4]++;
		forin(j, 1, radix) buckets[j] += buckets[j - 1];
		if (*buckets) fillBucket(list, length, 0, *buckets, i, 0);
		forin(j, 1, radix) {
			if (buckets[j - 1] != buckets[j]) {
				fillBucket(list, length, buckets[j - 1], buckets[j], i, j);
			}
		}
	}
}
