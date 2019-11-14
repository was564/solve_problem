#include <stdio.h>

int main() {
	int a, b, c, d;
	scanf("%d", &a);

	for (b = 1; b <= a; b++) {
		for (d = b; d <= 0; d++) {
			printf(" ");
		}
		for (c = a; c >= b; c--) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}