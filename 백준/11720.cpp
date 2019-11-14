#include <stdio.h>

int main() {
	int N, X = 0, sum = 0;
	char num[10000];

	scanf("%d", &N);
	scanf("%s", &num);

	for (int i = 0; i < N; i++) {
		X = num[i];
		sum += X - 48;
	}
	printf("%d", sum);
	return 0;
}