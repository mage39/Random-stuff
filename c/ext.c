#include <string.h>
#include <stdio.h>

#define SPACE " \f\n\r\t\v"
#define UPPER "QWERTYUIOPASDFGHJKZXCVBNML"
#define LOWER "qwertyuiopasdfghjklzxcvbnm"
#define DIGIT "1234567890"
#define NUMANY DIGIT "xabcdefABCDEFpP"
#define ALPHA UPPER LOWER
#define ALNUM ALPHA DIGIT

typedef struct {
	char* tok;
	size_t len;
} Token;

void tokenize (char* buf, Token* toks, int toksLen) {
	char* ptr = buf;
	for (int i = 0; ptr < buf + strlen(buf) && i < toksLen; i++) {
		ptr += strspn(ptr, SPACE);
		toks[i] = (Token){ptr, 0};
		if (isdigit(*ptr)) {
			toks[i].len += strspn(ptr, NUMANY);
			ptr += toks[i].len;
		}
		if (*ptr = '.' && isdigit(ptr[1])) {
			toks[i].len += strspn(++ptr, NUMANY);
			ptr += toks[i].len;
			continue;
		}
		if (*ptr == '"') {
			toks[i].len += strchr(ptr + 1, '"') - ptr;
			ptr += toks[i].len;
			continue;
		}
		if (*ptr == '(') {
			toks[i].len += strchr(ptr, ')') - ptr;
			ptr += toks[i].len;
			continue;
		}
		if (*ptr == '[') {
			toks[i].len += strchr(ptr, ']') - ptr;
			ptr += toks[i].len;
			continue;
		}
		if (*ptr == '.') {
			size_t t = strspn(ptr, ".");
			if (t > 2) {
				ptr += t;
				continue;
			}
			toks[i].len = 1;
			ptr++;
			continue;
		}
		if (isalpha(*ptr)) {
			toks[i].len = strspn(ptr, ALNUM);
			ptr += toks[i].len;
			continue;
		}
	}
}

int main (void) {
	constexpr int LEN = 64;
	constexpr int TOKCNT = 10;
	char buf[LEN];
	printf("$ ");
	fflush(stdout);
	fgets(buf, LEN, stdin);
	while (strcmp(buf, "quit\n")) {
		puts(buf);
		Token toks[TOKCNT];
		tokenize(buf, toks, TOKCNT);
