#include <iostream>
using namespace std;

int main() {
	int n, score[1001], max = 0;
	float avg = 0;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> score[i];
		if (max < score[i]) {
			max = score[i];
		}
		avg += score[i];
	}
	avg = (float)avg * 100 / (max*n);
	cout << avg;

	return 0;
}