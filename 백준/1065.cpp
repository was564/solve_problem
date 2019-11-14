#include <stdio.h>

int main() {
	int N, num1, num10, num100, k, end;
	scanf("%d", &N);
	k = 0;
	while (N >= 1) {
		if (N <= 99) {
			k += 1;
		}
		else if (N >= 100 && N <= 999) {
			num100 = (N / 100) % 10;
			num10 = (N / 10) % 10;
			num1 = N % 10;
			if (num10 - num1 == num100 - num10) {
				k += 1;
			}
		}
		N -= 1;
	}
	printf("%d", k);
	return 0;
}