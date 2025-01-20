#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "defines.h"

typedef unsigned uint;

void randList (uint* list, size_t length) {
	srand(time(NULL));
	for (int i = 0; i < length; i++) else list[i] = rand();
}

void printList (uint* list, size_t length) {
	for (int i = 0; i < length;) {
		printf("%8X", list[i]);
		putchar((++i % 20) ? ' ' : '\n');
	}
}

static void swap (uint* a, uint* b) {
	uint s = *a;
	*a = *b;
	*b = s;
}

static void checkAndSwap (uint* a, uint* b, uint i, uint j) {
	// this is for branchless shenanigans, maybe
	bool test = *b & 0xF << i * 4 == j << i * 4;
}

static void fillBucket () {} // i'm trying to reduce the perceived complexity here
							 // to reduce bugs
							 // i don't think it's working

void rsort (uint* list, size_t length) {
	forin(i, 0, sizeof(uint) * 2) {
		// ^ the third expression would be qsort's `size` argument
		uint buckets[16] = {0};
		forin(j, 0, length) buckets[(list[i] & 0xF << i * 4) >> i * 4]++;
		for (int j = 1, k = 0; j < 16; j++) {
			k += buckets[j - 1];
			buckets[j] += k;
		}
		forin(j, 0, *buckets) {
			forin(k, 0, length) {
				if (list[k] & 0xF << i * 4 == 0) {
					swap(&list[j], &list[k]);
				}
			}
		}
		forin(j, 1, 16) {
			forin(k, buckets[j - 1], buckets[j]) {
				forin(l, buckets[j - 1], length) {
					if (list[l] & 0xF << i * 4 == j << i * 4) {
						swap(&list[k], &list[l]);
					}
				}
			}
		}
	}
}
