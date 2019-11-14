#include <stdio.h>

int main() {
	int  T, a, b, a_sum, b_sum;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		a_sum = 0;
		b_sum = 0;
		scanf("%d %d", &a, &b);
		if (a == 1) {
			a_sum = 5000000;
		}
		else if (a >= 2 && a <= 3) {
			a_sum = 3000000;
		}
		else if (a >= 4 && a <= 6) {
			a_sum = 2000000;
		}
		else if (a >= 7 && a <= 10) {
			a_sum = 500000;
		}
		else if (a >= 11 && a <= 15) {
			a_sum = 300000;
		}
		else if (a >= 16 && a <= 21) {
			a_sum = 100000;
		}
		if (b == 1) {
			b_sum = 5120000;
		}
		else if (b >= 2 && b <= 3) {
			b_sum = 2560000;
		}
		else if (b >= 4 && b <= 7) {
			b_sum = 1280000;
		}
		else if (b >= 8 && b <= 15) {
			b_sum = 640000;
		}
		else if (b >= 16 && b <= 31) {
			b_sum = 320000;
		}
		printf("%d\n", a_sum + b_sum);
	}
	return 0;
}