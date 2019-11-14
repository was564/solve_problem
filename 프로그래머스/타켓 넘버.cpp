#include <vector>
#include <iostream>

using namespace std;

int countTarget(vector<int> numbers, int index, int preNum, int target) {
	// Ÿ�� ������ ����
	int count = 0;

	// numbers �������� ������ �Լ� ����
	if (index >= numbers.size()) {
		return 0;
	}

	// ��� numbers�� ���� ���ϰų� ���� �� �� Ȯ��
	if (index == numbers.size() - 1) {
		if (preNum + numbers[index] == target
			|| preNum - numbers[index] == target) {
			// Ÿ�� ���� ������ count ���� ����
			count++;
		}
	}

	// count�� ������ ���� �ε����� ���� ��츦 Ȯ��
	return count
		+ countTarget(numbers, index + 1, preNum + numbers[index], target)
		+ countTarget(numbers, index + 1, preNum - numbers[index], target);
}

int solution(vector<int> numbers, int target) {
	// �ʱ� ���� �Լ��� ����
	return countTarget(numbers, 1, numbers[0], target)
		+ countTarget(numbers, 1, -numbers[0], target);
}

int main() {
	vector<int> numbers = { 1, 1, 1, 1, 1 };
	cout << solution(numbers, 3);
	return 0;
}