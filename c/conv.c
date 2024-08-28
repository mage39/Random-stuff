#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void help (err) {
	printf("usage: input measurement, then unit\n
			\tthis tool will do everything else\n");
	exit(err);
}

int main (int argv, char** argv) {
	if (argv < 2) help(-1);
	if (!strncmp(argv[1], "-h", 2)) help(0);
	if (!strncmp(argv[1], "--help", strlen("--help"))) help(0);
	for (int i = 1; i < argc; i++) {
		for (int j = 0; j < strlen(argv[i]); j++) {
		}
	}
	return 0;
}
