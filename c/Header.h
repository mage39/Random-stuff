#pragma once
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>

int gcd(int a, int b) {
	a = a > 0 ? a : ~--a;
	b = b > 0 ? b : ~--b;
	while (b) {
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int lcm(int a, int b) {
	int c = a * b;
	return c > 0 ? c : -c / gcd(a, b);
}

int intSqrt(int a) {
	int b = 1;
	int i = 1;

	while (a > b) {
		a -= b;
		b += 2;
		i++;
	}
	return i;
}

double pi(double x) {  // note that any input above 1+e7 has a noticeable compute time, and any input above 1+e9 has a compute time greater than 60s
	double output = 0;
	for (double i = 0; i < x; i++) {
		double a = 1 / (i * 2 + 1);
		output += (int)i & 1 ? -a : a;
	}
	return 4 * output;
}

void randList(unsigned list[], int length, int modNum) {
	srand(time(NULL));

	for (int i = 0; i < length; i++) {
		if (modNum) list[i] = rand() % modNum;
		else list[i] = rand();
	}
}

void printList(unsigned list[], int length, int lineLength) {
	for (int i = 0; i < length;) {
		printf("%3X ", list[i]);
		printf((++i % lineLength) ? "" : "\n");
	}
}

void LSDradixSort(unsigned int list[], int length) {
#define RADIX_BASE 16

	for (int offset = 0; offset < 16; offset += 4) {
		int pointer = 0;
		int count[RADIX_BASE] = { 0 };

		for (int i = 0; i < length; i++) {
			for (unsigned int j = 0; j < RADIX_BASE; j++) {
				if ((list[i] & 0xF << offset) == j << offset) count[j]++;
			}
		}

		for (int i = 0; i < RADIX_BASE; i++) {
			for (int j = 0; j < length; j++) {
				if ((list[j] & 0xF << offset) == i << offset) {
					unsigned int a = list[pointer];
					list[pointer] = list[j];
					list[j] = a;
					pointer++;
				}
			}
		}
	}
}

void doubleLSDradix(double list[], int length) {
	int count[16] = {0};
	union cmp {
		double d;
		uint64_t i;
	};

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < 4; j++) {
			union cmp a;
			a.d = list[i];
			if ((a.i & 3 << 62) == j << 62) count[j]++;
		}
	}
	int ptrs[4];
	memcpy(ptrs, count, sizeof(ptrs));

	for (int i = 0; i < length; i++) {
		double a = list[length - count[i] - 1];
		list[length - count[i] - 1] = list[i];
		list[i] = a;
		count[i]--;
	}
}

void LSDradixSortUnderstandable(unsigned int list[], int length) {
#ifndef RADIX_BASE
	#define RADIX_BASE 10
#endif
	
	int maxOrderOfMagnitudeExpected = 1000000000;
	for (int offset = 0; offset < maxOrderOfMagnitudeExpected; offset += RADIX_BASE) {
		int pointer = 0;
		int count[RADIX_BASE] = { 0 };

		for (int i = 0; i < length; i++) { // countsort
			for (unsigned int j = 0; j < RADIX_BASE; j++) {
				if ((list[i] / offset % RADIX_BASE) == j) count[j]++;
			}
		}

		for (int i = 0; i < RADIX_BASE; i++) {
			for (int j = 0; j < length; j++) {
				if ((list[i] / offset % RADIX_BASE) == offset % RADIX_BASE) { // if (cond) do swap, pointer denotes where to swap from here
					unsigned int a = list[pointer];
					list[pointer] = list[j];
					list[j] = a;
					pointer++;
				}
			}
		}
	}
}

#define LEN 39
typedef unsigned __int128 uint128_t;
void print_uint128 (uint128_t num) {
	char str[LEN] = {0};
	for (int i = 0; i < LEN; i++) {
		str[i] = "0123456789"[num % 10];
		num /= 10;
	}
	for (int i = LEN - 1; i >= 0; i--) {
		printf("%c", str[i]);
		if (!i) break;
		printf((i % 3) ? "" : ",");
	}
	printf("\n");
}

/*typedef enum typeChecker {
	isChar,
	isInt,
	isFloat
} typeChecker;

int aTotallyPolymorphicFunction(typeChecker a, ...) {
	va_list va;
	va_start(va, a);

	if (a == isChar) {
		char* b = va_arg(va, char*);

		printf("%s", b);
		va_end(va);
		return 0;
	}
	else if (a == isInt) {
		int b = va_arg(va, int);

		printf("%i", b);
		va_end(va);
		return 0;
	}
	else if (a == isFloat) {
		float b = va_arg(va, float);

		printf("%.5f", b);
		va_end(va);
		return 0;
	}
	else {
		va_end(va);
		return -1;
	}
}*/

typedef enum {
	UCHAR,
	FLOAT, DOUBLE, LDOUBLE,
	UNSIGNED, UL, ULALT, ULL,
	CHAR,
	FLOATALT, DOUBLEALT, LDOUBLEALT,
	INT, LINT, LINTALT, LLINT
} WidePtrType;

typedef struct {
	WidePtrType type;
	unsigned len;
	void* ptr;
} WidePtr;

// or something, i havent got the whole thing straight in my head
// but this is mostly compliant with how i want to make it
