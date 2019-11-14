#include<stdio.h>

int N;
int fibonacci(int first, int second) {
	int third, repeat = 4;
	while (N >= repeat) {
		third = first + second;
		first = second;
		second = third;
		repeat += 1;
	}
	return third;
}

int main() {
	int T, count;
	scanf("%d", &T);
	while (T > count) {
		scanf("%d", &N);
		if (N >= 4) {
			printf("%d %d\n", fibonacci(1, 1), fibonacci(1, 2));
		}
		else if (N == 3) {
			printf("1 2\n");
		}
		else if (N == 2) {
			printf("1 1\n");
		}
		else if (N == 1) {
			printf("0 1\n");
		}
		else if (N == 0) {
			printf("1 0\n");
		}
		count += 1;
	}
	return 0;
}

