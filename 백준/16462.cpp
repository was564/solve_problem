#include <stdio.h>
#include <string.h>

int main() {
	char score[4];
	int n, qi[1000], end, count, input, total = 0, print;
	memset(qi, 0, sizeof(qi));
	float avg;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", score);
		for (int j = 0; j < 4; j++) {
			if (score[j] == '\0') {
				end = j;
				break;
			}
			else if (score[j] == '0' || score[j] == '6' || score[j] == '9') {
				score[j] = '9';
			}
		}
		count = 1;
		input = 0;
		for (int j = end - 1; j >= 0; j--) {
			input += (score[j] - '0')*count;
			count *= 10;
		}
		if (input > 100) {
			qi[i] = 100;
		}
		else {
			qi[i] = input;
		}
	}

	for (int i = 0; i < n; i++) {
		total += qi[i];
	}
	avg = (float)total / (float)n;
	if ((int)(avg * 10) % 10 >= 5) {
		print = avg + 1;
	}
	else {
		print = avg;
	}
	printf("%d", print);

	return 0;
}