#include <assert.h>
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

void randList (uint* list, size_t length) {
	srand(time(NULL));
	forin(i, 0, length) list[i] = rand();
}

void printList (uint* list, size_t length) {
	for (uint i = 0; i < length;) {
		printf("%8X", list[i]);
		putchar((++i % 20) ? ' ' : '\n');
	}
}

static void swap (uint* a, uint* b) {
	uint s = *a;
	*a = *b;
	*b = s;
}

static void pushBack (uint* list, size_t length, uint idx) {
	if (length - idx < 2) return;
	size_t amount = (length - idx - 1) * sizeof(uint);
	uint end = list[length - 1];
	memmove(list + idx + 1, list + idx, amount);
	list[idx] = end;
}

static void fillBucket (uint* list, size_t length, uint start, uint end, uint i, uint j) {
	printf("start: %X, end: %X, searching for: %X\n", start, end, j);
	forin(k, start, end) {
		forin(l, start, length) {
			uint match = list[l] & (radixMask << i * radixMaskWidth);
			if (match == j << i * radixMaskWidth) {
				swap(&list[k], &list[l]);
				pushBack(list, length, k + 1);
				break;
			}
		}
	}
}

void rsort (uint* list, size_t length) {
	forin(i, 0, sizeof(uint) * (CHAR_BIT / radixMaskWidth)) {
		uint buckets[radix] = {0};
		forin(j, 0, length) {
			uint match = list[j] & (radixMask << i * radixMaskWidth);
			buckets[match >> i * radixMaskWidth]++;
		}
		forin(j, 1, radix) buckets[j] += buckets[j - 1];
		printList(buckets, 16);
		puts("");
		if (*buckets) {
			fillBucket(list, length, 0, *buckets, i, 0);
			printList(list, length);
			puts(" 0 bucket");
		}
		forin(j, 1, radix) {
			if (buckets[j - 1] != buckets[j]) {
				fillBucket(list, length, buckets[j - 1], buckets[j], i, j);
				printList(list, length);
				printf(" %X bucket\n", j);
			}
		}
	}
}
