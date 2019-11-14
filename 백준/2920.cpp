#include <iostream>
using namespace std;

int main() {
	int input[9] = { 0, };
	int num, des = 0, asc = 0;

	for (int i = 1; i < 9; i++) {
		cin >> num;
		input[i] = num;
	}

	for (int i = 1; i < 9; i++) {
		if (input[i] == i) {
			asc++;
		}
		else if (input[i] == 9 - i) {
			des++;
		}
	}
	if (asc == 8) {
		cout << "ascending" << endl;
	}
	else if (des == 8) {
		cout << "descending" << endl;
	}
	else {
		cout << "mixed" << endl;
	}

	return 0;
}