#include <stdio.h>
#include <string.h>

int main() {
	int line[10002], n, x1, x2, i, k, max = 0, min = 10000, result = 0;
	memset(line, 0, sizeof(line));
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d %d", &x1, &x2);
		if (x2 > max) {
			max = x2;
		}
		if (x1 < min) {
			min = x1;
		}
		for (k = x1; k < x2; k++) {
			line[k] = 1;
		}
	}
	max += 1;
	for (i = min; i <= max; i++) {
		result += line[i];
	}
	printf("%d", result);

	return 0;
}