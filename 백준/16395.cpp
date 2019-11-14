#include <stdio.h>

int bc(int n, int k);

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	printf("%d", bc(n - 1, k - 1));

	return 0;
}

int bc(int n, int k) {
	if (n == 1 || k == 0) {
		return 1;
	}
	else if (n == k) {
		return 1;
	}
	else {
		return bc(n - 1, k - 1) + bc(n - 1, k);
	}
}