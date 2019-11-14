#include <stdio.h>

int main() {
	int N = 1, X, A[10000];
	scanf("%d", &N);
	scanf("%d", &X);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	for (int j = 0; j < N; j++) {
		if (A[j] < X) {
			printf("%d ", A[j]);
		}
	}
	return 0;
}