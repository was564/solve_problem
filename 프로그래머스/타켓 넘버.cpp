#include <vector>
#include <iostream>

using namespace std;

int countTarget(vector<int> numbers, int index, int preNum, int target) {
	// 타켓 숫자의 갯수
	int count = 0;

	// numbers 갯수보다 작으면 함수 종료
	if (index >= numbers.size()) {
		return 0;
	}

	// 모든 numbers의 값을 더하거나 빼을 때 값 확인
	if (index == numbers.size() - 1) {
		if (preNum + numbers[index] == target
			|| preNum - numbers[index] == target) {
			// 타겟 값과 같으면 count 갯수 증가
			count++;
		}
	}

	// count의 갯수와 다음 인덱스와 다음 경우를 확인
	return count
		+ countTarget(numbers, index + 1, preNum + numbers[index], target)
		+ countTarget(numbers, index + 1, preNum - numbers[index], target);
}

int solution(vector<int> numbers, int target) {
	// 초기 값을 함수로 실행
	return countTarget(numbers, 1, numbers[0], target)
		+ countTarget(numbers, 1, -numbers[0], target);
}

int main() {
	vector<int> numbers = { 1, 1, 1, 1, 1 };
	cout << solution(numbers, 3);
	return 0;
}