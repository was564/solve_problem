#include <iostream>
using namespace std;

int main() {
	char str[81];
	int count, score, result;

	cin >> count;
	for (int i = 0; i < count; i++) {
		score = 1, result = 0;
		cin >> str;
		for (unsigned int index = 0; str[index] != '\0'; index++) {
			if (str[index] == 'O') {
				result += score++;
			}
			else if (str[index] == 'X') {
				score = 1;
			}
		}
		cout << result << endl;
	}

	return 0;
}