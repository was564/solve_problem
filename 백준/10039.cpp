#include <iostream>
using namespace std;

int main() {
	int score[5], sum = 0, avg;

	for (int i = 0; i < 5; i++) {
		cin >> score[i];
		if (score[i] < 40) {
			score[i] = 40;
		}
		sum += score[i];
	}

	avg = sum / 5;
	cout << avg << endl;

	return 0;
}