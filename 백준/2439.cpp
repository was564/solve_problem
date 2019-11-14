#include <stdio.h>

int main() {
	int a, b, c, d;
	scanf("%d", &a);

	for (b = 1; b <= a; b++) {
		for (d = a - b - 1; d >= 0; d--) {
			printf(" ");
		}
		for (c = 1; c <= b; c++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}