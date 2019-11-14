#include <stdio.h>

int main() {
	int k, N;
	scanf("%d", &N);
	for (k = 1; k < N; k++) {
		if (1 + k + k * k == N) {
			printf("%d", k);
		}
	}
}