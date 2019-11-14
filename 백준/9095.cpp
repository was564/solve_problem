#include <iostream>

using namespace std;

int check(int n);

int main() {
	int t, n;
	int arr[12];
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << check(n) << endl;
	}

	return 0;
}

int check(int n) {
	if (n >= 3) {
		return check(n - 1) + check(n - 2) + check(n - 3);
	}
	else if (n == 2) {
		return check(n - 1) + check(n - 2);
	}
	else if (n == 1) {
		return check(n - 1);
	}
	else if (n == 0) {
		return 1;
	}
}