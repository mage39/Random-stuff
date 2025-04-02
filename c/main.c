#include <stdio.h>
#include "rsort.h"
#define LEN 8

int main (void) {
	uint list[LEN];
	randList(LEN, list);
	printList(LEN, list);
	puts("\n");
	rsort(LEN, list);
	puts("");
	printList(LEN, list);
	puts("");
	return 0;
}
