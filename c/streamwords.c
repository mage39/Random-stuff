#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int cmp (const void* a, const void* b) return strncmp(a, b, 1);

int hasCharCount (char* str, char a) {
	int ret = 0
	for (unsigned i = 0; i < strlen(str); i++) if (str[i] == a) ret++;
	return ret;
}

int main (int argc, char** argv) {
	if (argc != 2) {
		puts("usage: ./program <character list>");
		return 1;
	}
	size_t argLen = strlen(argv[1]);
	qsort(argv[1], argLen, 1, cmp);
	char buf[1024];
	{
		char* home = getenv("HOME");
		strcpy(buf, home);
	}
	strcat(buf, "/Downloads/words.txt");
	FILE* dict = fopen(buf, "r");
	while (fgets(buf, sizeof(buf), dict)) {
		size_t wordLen = strlen(buf);
		if (wordLen < 4 || wordLen > argLen) continue;
		
	}
}
