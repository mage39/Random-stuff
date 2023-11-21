#include "Header.h"

#define LEN 16384

int main() {
	unsigned list[LEN] = { 0 };
	int lineLength = 8;

	randList(list, LEN, 64);
	
	printList(list, LEN, lineLength);
	printf("\n");
	LSDradixSort(list, LEN);
	printList(list, LEN, lineLength);

	return 0;
}

void blockMergeSort(int list[], int length) {
	for (int blockSize = 1; blockSize < length; blockSize *= 2) {
		// for () {}
		for (int i = 0; i < blockSize; i++) {
			if (blockSize + i < length && list[i] > list[i + blockSize]) {
				int a = list[i + blockSize];
				list[i + blockSize] = list[i];
				list[i] = a;
			}
		}
	}
}
