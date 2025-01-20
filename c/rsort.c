#include <stdlib.h>
#include <stdio.h>
#include "defines.h"

void randList (unsigned* list, size_t length, int modNum) {
	srand(time(NULL));
	for (int i = 0; i < length; i++) {
		if (modNum) list[i] = rand() % modNum;
		else list[i] = rand();
	}
}

void printList (unsigned* list, size_t length, int lineLength) {
	for (int i = 0; i < length;) {
		printf("%8X", list[i]);
		printf((++i % lineLength) ? " " : "\n");
	}
}

void rsort (unsigned* list, size_t length) {
	forin(i, 0, sizeof(unsigned) * 2) {
		unsigned buckets[16] = {0};
		forin(j, 0, length) buckets[(list[i] & 0xF << i * 4) >> i * 4]++;
		for (int j = 1, k = 0; j < 16; j++) {
			k += buckets[j - 1];
			buckets[j] += k;
		}
		// `buckets` contains list of indexes that must be filled,
		// from `buckets[i - 1]` to `buckets[i]`,
		// with elements in `list` matching the condition which put that number
		// in that bucket in the first place
