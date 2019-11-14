#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
	int num, equal = 0, check_equal, digit = 1;
	int check[5];
	memset(check, 0, sizeof(check));
	scanf("%d", &num);
	for (int i = 10; i <= 1000000000; i *= 10) {
		if (num - i < 0) {
			break;
		}
		digit += 1;
	}

	if (num % 10 == 2) {
		check[0] += 1;
	}
	else if (num % 10 == 0) {
		check[1] += 1;
	}
	else if (num % 10 == 1) {
		check[2] += 1;
	}
	else if (num % 10 == 8) {
		check[3] += 1;
	}
	else {
		check[4] += 1;
	}
	for (int i = 100; i <= pow(10, digit); i *= 10) {
		if ((num%i) / (i / 10) == 2) {
			check[0] += 1;
		}
		else if ((int)(num%i) / (i / 10) == 0) {
			check[1] += 1;
		}
		else if ((int)(num%i) / (i / 10) == 1) {
			check[2] += 1;
		}
		else if ((int)(num%i) / (i / 10) == 8) {
			check[3] += 1;
		}
		else {
			check[4] += 1;
		}
	}

	if (check[4] > 0) {
		printf("0");
		return 0;
	}
	else {
		check_equal = check[0];
		for (int i = 0; i < 4; i++) {
			if (check[i] != check_equal) {
				equal = 1;
			}
			if (check[i] > 0) {
				continue;
			}
			printf("1");
			return 0;
		}
	}
	if (equal == 0) {
		printf("8");
		return 0;
	}
	else {
		printf("2");
		return 0;
	}

	return 0;
}