#include <stdio.h>

typedef struct {
	char ID : 4;
	char x : 4;
	char y : 4;
	char z : 4;
} frame_t;
typedef struct {
	char ID : 4;
	char skip : 4;
} frameskip_t;
#define FRAMESKIP_INIT(a) frameskip_t a = {.ID = -1}

int main () {
	printf("%d\n", sizeof(frame_t));
	return 0;
}
