#include <iostream>
using namespace std;

int main() {
	int c, n, score[1001], i, j, k, check;
	float avg, ratio;

	cin >> c;
	for (i = 1; i <= c; i++) {
		avg = 0, check = 0;
		cin >> n;
		for (j = 1; j <= n; j++) {
			cin >> score[j];
			avg += score[j];
		}
		avg = (float)avg / n;
		for (k = 1; k <= n; k++) {
			if (score[k] > avg) {
				check += 1;
			}
		}
		ratio = (float)check * 100 / n;
		cout << fixed;
		cout.precision(3);
		cout << ratio << "%\n";
	}

	return 0;
}