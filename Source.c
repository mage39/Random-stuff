#include "Header.h"

#define LEN 10

int main() {
	int list[LEN] = { 0 };
	int lineLength = 5;

	randList(list, LEN, 10);
	
	printList(list, LEN, lineLength);
	printf("\n");
	void blockMergeSort(int list[], int length);
	blockMergeSort(list, LEN);
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
