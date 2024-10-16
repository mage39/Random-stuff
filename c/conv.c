#include <string.h>
#include <stdlib.h>
#include <stdio.h>

enum UNITDEF {
	ERR, INCH, FT, YD, MI, NMI,
	M,
	OZ, LB, STONE, TON,
	G, TONNE,
	MIPH, FTPS, KNOT,
	MPS, KMPH
};
typedef enum UNITDEF UNITDEF;

static void help (int err) {
	printf("USAGE: conv <unit> <unit-definition> [<unit-definition>]\n
			\t<unit> is any floating point number, optionally with a trailing SI prefix\n
			\t<unit-definition> is any of the SI or freedom units, optionally with a leading SI prefix\n
			\tthe optional <unit-definition> denotes an intended output unit, otherwise one is selected for you\n\n
			NOTE: micro is denoted by 'u' and deca is denoted by 'D' here\n
			\ti couldnt be bothered with the hassle of following pre-1900s standards to the letter\n");
	exit(err);
}

static int SImul (char prefix) {
	switch (prefix) {
		case 0 ... 9: return 0;
		case 'D': return 1;
		case 'h': return 2;
		case 'k': return 3;
		case 'M': return 6;
		case 'G': return 9;
		case 'T': return 12;
		case 'P': return 15;
		case 'E': return 18;
		case 'Z': return 21;
		case 'Y': return 24;
		case 'Q': return 30;
		case 'd': return -1;
		case 'c': return -2;
		case 'm': return -3;
		case 'u': return -6;
		case 'n': return -9;
		case 'p': return -12;
		case 'f': return -15;
		case 'a': return -18;
		case 'z': return -21;
		case 'y': return -24;
		case 'q': return -30;
		default: return -4;
	}
}

static UNITDEF unitDef (char which[], size_t len) {
	int offset = 0;
	if (!SImul(which[0])) {
		printf("parse error: number discovered in <unit-definition>\n");
		exit(-2);
	}
	if (len > 1 && SImul(which[0]) != -4) offset = 1;
	if (!strncmp(which + offset, "m", 1)) return M;
	printf("parse error: unknown <unit-definition>\n");
	exit(-2);
}

int main (int argv, char** argv) {
	if (argv > 4 || argv < 2) help(-1);
	if (argv == 2) {
		if (!strncmp(argv[1], "-h", 2)) help(0);
		if (!strncmp(argv[1], "--help", strlen("--help"))) help(0);
		help(-1);
	}
	double unit = atof(argv[1]);
	int unitPrefix = SImul(argv[1][strlen(argv[1]) - 1]);
	if (unitPrefix == -4) {
		printf("parse error: unknown symbol found in <unit>\n");
		exit(-2);
	}
	unit *= pow(10, unitPrefix);
	return 0;
}
