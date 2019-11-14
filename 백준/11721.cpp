#include <stdio.h>

int main() {
	char N[100];

	scanf("%s", N);

	for (int i = 1; i <= 100; i++) {
		if (N[i - 1] == '\0') break;
		printf("%c", N[i - 1]);
		if (i % 10 == 0) printf("\n");
	}
	return 0;
}