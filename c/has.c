#include <string.h>
#include <stdio.h>

#define LOWER "qwertyuiopasdfrghjklzxcvbnm"

int main (int argc, char** argv) {
	if (argc != 2) {
	   fputs("usage: takes from stdin and checks that each line has all "
			   "characters in first argument\n", stderr);
	   return 1;
	}
	char buf[32];
	// bool found[UCHAR_MAX + (size_t)1] = {0};
	// apparently i need that to make this faster, but smol brain RN
	while (fgets(buf, sizeof(buf), stdin)) {
		bool failed = false;
		for (unsigned i = 0; i < strlen(argv[1]); i++) {
			if (strchr(buf, (unsigned)argv[1][i]) == NULL) {
				failed = true;
				break;
			}
		}
		if (failed) continue;
		else fputs(buf, stdout);
	}
}
