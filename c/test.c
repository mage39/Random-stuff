#include <stdio.h>
#include "Header.h"

int main () {
	unsigned list[32];
	randList(list, 32, 0);
	printList(list, 32, 8);
	printf("\n");
	LSDradixSort(list, 32);
	printList(list, 32, 8);
}
