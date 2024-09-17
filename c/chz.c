#include <stdio.h>

typedef struct {
	char ID : 4;
	char x : 4;
	char y : 4;
	char z : 4;
} frame_t;

int main () {
	printf("%d\n", sizeof(frame_t));
	return 0;
}
