#include <vector>
#include <iostream>

using namespace std;

int countTarget(vector<int> numbers, int index, int preNum, int target) {
	int count = 0;
	if (index >= numbers.size()) {
		return 0;
	}
	if (index == numbers.size() - 1) {
		if (preNum + numbers[index] == target
			|| preNum - numbers[index] == target) {
			count++;
		}
	}
	return count
		+ countTarget(numbers, index + 1, preNum + numbers[index], target)
		+ countTarget(numbers, index + 1, preNum - numbers[index], target);
}

int solution(vector<int> numbers, int target) {
	return countTarget(numbers, 1, numbers[0], target)
		+ countTarget(numbers, 1, -numbers[0], target);
}

int main() {
	vector<int> numbers = { 1, 1, 1, 1, 1 };
	cout << solution(numbers, 3);
	return 0;
}