#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

typedef enum {
	OP_RETURN,
	PLACEHOLDER_END,
} OpCode;
struct Arr {
	size_t len, cap;
	uint8_t dat[];
};
typedef struct Arr* Array;
typedef struct {
	unsigned len;
	const char* name;
} OpCodeDat;
Array arrInit (void) {
	constexpr int initLen = 16;
	Array t = calloc(sizeof(*t) + initLen, 1);
	if (!t) exit(ENOMEM);
	t->cap = initLen;
	return t;
}
void arrPush (Array *arr, size_t len, uint8_t dat[len]) {
	while ((*arr)->cap <= (*arr)->len + len) {
		(*arr)->cap *= 2;
		*arr = realloc(*arr, sizeof(**arr) + (*arr)->cap);
		if (!*arr) exit(ENOMEM);
	}
	memcpy((*arr)->dat + len, dat, len);
	(*arr)->len += len;
}
void disassemble (Array arr, const char* name) {
	const OpCodeDat opCodes[] = {
		{1, "OP_RETURN"},
	};
	printf("== %s ==\n", name);
	for (size_t i = 0; i < arr->len;) {
		OpCodeDat op = {1, "UNKNOWN"};
		if (arr->dat[i] < PLACEHOLDER_END) op = opCodes[arr->dat[i]];
		printf("%04d %s\n", arr->dat[i], op.name);
		i += op.len;
	}
}

int main (void) {
	Array chunk = arrInit();
	uint8_t op = OP_RETURN;
	arrPush(&chunk, 1, &op);
	disassemble(chunk, "test chunk");
	free(chunk);
}
