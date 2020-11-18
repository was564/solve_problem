#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solve();

int main() {
	vector<int> answers;
	int T;
	cin >> T;
	for(int i=0; i<T; i++) {
		answers.push_back(solve());
	}
	
	for(int& answer : answers) {
		cout << answer << "\n";
	}
	
	return 0;
}

int solve() {
	int H, W, N;
	int Y, X, answer;
	cin >> H >> W >> N;
	if(N % H == 0) {
		Y = H;
		X = N/H;
	}
	else {
		Y = N % H;
		X = N/H + 1;
	}
	answer = X + Y*100;
	return answer;
}