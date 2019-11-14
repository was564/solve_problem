#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	int result[10] = { 0, };
	long long value;
	cin >> a >> b >> c;
	value = a * b*c;

	while (value != 0) {
		result[value % 10]++;
		value /= 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << result[i] << endl;
	}

	return 0;
}