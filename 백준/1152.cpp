#include <stdio.h>

int main() {
	int check = 0, word = 0;
	char sent[1000001];
	fgets(sent, 1000000, stdin);

	for (int i = 0; i < 1000001; i++) {
		if (65 <= sent[i] && sent[i] <= 90) {
			check = 1;
		}
		else if (97 <= sent[i] && sent[i] <= 122) {
			check = 1;
		}
		else {
			if (check == 1) {
				word += 1;
			}
			check = 0;
			if (sent[i] == '\n') {
				break;
			}
		}
	}
	printf("%d", word);

	return 0;
}