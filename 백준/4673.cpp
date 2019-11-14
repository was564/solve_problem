#include <iostream>
using namespace std;

int self_num(int num);

int main() {
	int data[10001] = { 0, };
	for (int i = 1; i <= 10000; i++) {
		data[self_num(i)] = 1;
	}
	for (int i = 1; i <= 10000; i++) {
		if (data[i] == 0) {
			cout << i << endl;
		}
	}

}

int self_num(int num) {
	int sum = num;
	for (int i = 0; i < 5; i++) {
		sum += num % 10;
		num /= 10;
	}
	if (sum > 10000) {
		return 0;
	}
	return sum;
}