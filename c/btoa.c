#include <string.h>
#include <stdio.h>

int main (int argc, char** argv) {
	if (argc < 2) {
		printf("GIMME DATA\n");
		return -1;
	}
	unsigned output[64] = {0};
	int integer = 0;
	for (int i = 1, k = 0; i < argc; i++) {
		if (!strncmp(argv[i], "-i", 2)) {
			integer = 1;
			continue;
		}
		for (int j = 0; j < strlen(argv[i]); j++) {
			output[k] <<= 1;
			if (argv[i][j] == '1') output[k] |= 1;
			else if (argv[i][j] != '0') {
				printf("YOU FUCKED IT UP\n");
				return -1;
			}
		}
		k++;
	}
	if (integer) printf("%u\n", output[0]);
	else {
		for (int i = 0; i < 64 && output[i]; i++) {
			printf("%c", output[i]);
		}
		printf("\n");
	}
	return 0;
}
