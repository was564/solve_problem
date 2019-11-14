#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char word[100];
	int check[26];
	memset(check, -1, sizeof(check));

	cin >> word;
	for (int i = 0; i < 100; i++) {
		if (word[i] == '\0') {
			break;
		}
		for (int alpha = 0; alpha < 26; alpha++) {
			if (word[i] == 'a' + alpha && check[alpha] == -1) {
				check[alpha] = i;
			}
			if (word[i] == 'a' + alpha) {
				break;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << check[i] << ' ';
	}

	return 0;
}