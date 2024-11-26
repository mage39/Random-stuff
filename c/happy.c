#include <math.h>
#include <stdio.h>
#include <string.h>

#define LEN 10

int main () {
	char input[LEN] = {'y'};
	while (strchr(input, 'y')) {
		int sum = 0;
		printf("Enter a number: ");
		fgets(input, LEN, stdin);
		for (int i = 0; i < 100; i++) {
			sum = 0;
			int len = strspn(input, "0123456789");
			for (int j = 0; j < len; j++) sum += pow(input[j] - '0', 2);
			if (sum == 1 || sum == 4) break;
			sprintf(input, "%d", sum);
		}
		if(sum == 1) {
			printf("Happy\n");
		} else {
			printf("Unhappy\n");
		}
		printf("do you wish to continue? ");
		fgets(input, LEN, stdin);
	}
    return 0;
}
