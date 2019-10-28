#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	// �ɸ� �ð�
	int time = 1;
	// Ʈ�� ��ġ �迭 ����
	vector<int> location;
	// �ٸ� ���� �ö� �� ����
	int total_weight = 0;
	// ������� ���� Ʈ�� �� ���� �� �ڸ�
	int check_front = 0;
	// �ٸ� �� ���� �� Ʈ��
	int check_back = 0;
	// Ʈ�� ��ġ �ʱ�ȭ
	for (int i = 0; i < truck_weights.size(); i++) {
		location.push_back(-i);
	}

	while (true) {
		// �� �ڿ� Ʈ���� �ٸ����� ������ ��
		if (location.back() >= bridge_length) {
			break;
		}
		// ������� ���� Ʈ���� ���� ���
		if (check_front >= location.size()) {
			// ��� Ʈ���� ��ġ 1 ����
			for (int i = 0; i < location.size(); i++) {
				location[i]++;
			}
			time++;
			continue;
		}
		// ���� �տ� �ִ� Ʈ�� �ٸ� ���� �÷��� �Ǵ��� üũ
		// �ȵǸ� ������ Ʈ���� ��ġ 1 ����
		if (total_weight > weight - truck_weights[check_front]) {
			for (int i = 0; i <= check_front - 1; i++) {
				location[i]++;
			}

			// ���� �ٸ� �� �� ���� Ʈ���� ���� ������ ��
			if (location[check_back] >= bridge_length) {
				// �ٸ� ���Կ� ���� ���� Ʈ�� ���Ը� ��
				// ���ÿ� �ٸ� �� ���� Ʈ���� ����
				total_weight -= truck_weights[check_back++];
			}

			time++;
			continue;
		}

		// �Ǹ� ��� Ʈ�� ��ġ 1����
		for (int i = 0; i < location.size(); i++) {
			location[i]++;
		}
		// �� ������ Ʈ�� �� ���� �� Ʈ���� ���Ը� ����
		// ���ÿ� �� ������ Ʈ�� �� ���� �� Ʈ�� ����
		total_weight += truck_weights[check_front++];



		// ���� �ٸ� �� �� ���� Ʈ���� ���� ������ ��
		if (location[check_back] >= bridge_length) {
			// �ٸ� ���Կ� ���� ���� Ʈ�� ���Ը� ��
			// ���ÿ� �ٸ� �� ���� Ʈ���� ����
			total_weight -= truck_weights[check_back++];
		}
		time++;
	}

	return time;
}

int main() {
	int bridge_length = 10;
	int weight = 8;
	vector<int> truck_weights = {8, 2, 6, 3, 2};
	cout << solution(bridge_length, weight, truck_weights);
	return 0;
}