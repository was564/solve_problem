#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

bool solveProblem(int a, int b, int c);

int main() {

	vector<bool> answers;
	int a=-1, b=-1, c=-1;
	cin >> a >> b >> c;
	while (a != 0 || b != 0 || c != 0) {
		answers.push_back(solveProblem(a, b, c));
		cin >> a >> b >> c;
	}
	
	for (bool answer : answers) {
		if (answer) { cout << "right" << "\n"; }
		else { cout << "wrong" << "\n"; }
	}

	return 0;
}

bool solveProblem(int a, int b, int c) {
	int hyp;
	hyp = max(max(a, b), max(b, c));
	if (2 * pow(hyp, 2) == pow(a, 2) + pow(b, 2) + pow(c, 2))
		return true;
	return false;
}