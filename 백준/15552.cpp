#include <iostream>

int main() {
	unsigned int count;
	scanf("%d", &count);
	int a, b;
	for (int i = 0; i < count; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}

	return 0;
}