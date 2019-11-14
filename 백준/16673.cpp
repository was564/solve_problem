#include <stdio.h>

int main() {
	int c, k, p, result = 0;
	scanf("%d %d %d", &c, &k, &p);
	for (int i = 1; i <= c; i++) {
		result += k * i + p * i*i;
	}
	printf("%d", result);

	return 0;
}