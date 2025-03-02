#include <stdio.h>
#include "rsort.h"
#define LEN 8

int main (void) {
	uint list[LEN];
	randList(list, LEN);
	printList(list, LEN);
	puts("\n");
	rsort(list, LEN);
	puts("");
	printList(list, LEN);
	puts("");
	return 0;
}
