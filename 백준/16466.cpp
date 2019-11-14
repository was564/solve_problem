#include <stdio.h>
#include <string.h>

int main() {
	int n, ticket, check[1000002];
	memset(check, 0, sizeof(check));
	check[0] = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &ticket);
		if (ticket > 1000000) {
			continue;
		}
		check[ticket] = 1;
	}

	for (int i = 1; i < 1000000; i++) {
		if (check[i] == 0) {
			printf("%d", i);
			break;
		}
	}

	return 0;
}