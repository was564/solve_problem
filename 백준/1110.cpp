#include <stdio.h>

int main() {
	int input, first, second, num, count;
	scanf("%d", &input);

	num = -1;
	count = 0;

	first = (input / 10 + input % 10) % 10;
	second = input % 10;
	while (num != input) {
		num = first + 10 * second;
		first = (num / 10 + num % 10) % 10;
		second = num % 10;
		count += 1;
	}
	printf("%d", count);
}