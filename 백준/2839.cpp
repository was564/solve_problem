#include <stdio.h>

int main() {
	int a, i;
	scanf("%d", &a);

	for (i = 0; i >= 0; i++) {

		if (a < 3 * i) {
			printf("-1");
			break;
		}
		else if ((a - (3 * i)) % 5 == 0) {
			printf("%d", i + (a - (3 * i)) / 5);
			break;
		}
	}
}