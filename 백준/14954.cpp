#include <stdio.h>
#include <cmath>

int sum(int n) {
	int sum = 0, i = 0, t;
	while (n >= pow(10, i)) {
		t = pow(10, i);
		sum += pow(((n / t) % 10), 2);
		i++;
	}
	return sum;
}

int main() {
	int n, num, c = 0;
	bool flag = true;
	n = pow(5, 2);
	scanf("%d", &n);
	num = n;
	while (flag) {
		num = sum(num);
		if (num == 4) {
			c++;
		}
		if (num == 1) {
			printf("HAPPY");
			break;
		}
		else if (num == n || c == 3) {
			printf("UNHAPPY");
			break;
		}
	}
	return 0;
}