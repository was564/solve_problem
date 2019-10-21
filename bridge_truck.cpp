#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	// 걸린 시간
	int time = 1;
	// 트럭 위치 배열 선언
	vector<int> location;
	// 다리 위에 올라간 총 무게
	int total_weight = 0;
	// 출발하지 않은 트럭 중 제일 앞 자리
	int check_front = 0;
	// 다리 내 제일 앞 트럭
	int check_back = 0;
	// 트럭 위치 초기화
	for (int i = 0; i < truck_weights.size(); i++) {
		location.push_back(-i);
	}

	while (true) {
		if (location.back() >= bridge_length) {
			break;
		}

		// 제일 앞에 있는 트럭 다리 위에 올려도 되는지 체크
		if (check_front >= location.size()) {
			for (int i = 0; i < location.size(); i++) {
				location[i]++;
			}
			time++;
			continue;
		}
		if (total_weight > weight - truck_weights[check_front]) {
			// 안되면 지나간 트럭의 위치 1증가
			for (int i = 0; i <= check_back; i++) {
				location[i]++;
			}

			// 만약 다리 내 맨 앞의 트럭이 빠져 나왔을 때
			if (location[check_back] >= bridge_length) {
				// 다리 무게에 빠져 나온 트럭 무게를 뺌
				// 동시에 다리 맨 앞의 트럭을 갱신
				total_weight -= truck_weights[check_back++];
			}

			time++;
			continue;
		}

		// 되면 모든 트럭 위치 1증가
		for (int i = 0; i < location.size(); i++) {
			location[i]++;
		}
		// 안 지나간 트럭 중 제일 앞 트럭의 무게를 더함
		// 동시에 안 지나간 트럭 중 제일 앞 트럭 갱신
		total_weight += truck_weights[check_front++];
		
		

		// 만약 다리 내 맨 앞의 트럭이 빠져 나왔을 때
		if (location[check_back] >= bridge_length) {
			// 다리 무게에 빠져 나온 트럭 무게를 뺌
			// 동시에 다리 맨 앞의 트럭을 갱신
			total_weight -= truck_weights[check_back++];
		}
		time++;
	}

	return time;
}

int main() {
	int length = 2;
	int	weight = 10;
	vector<int> truck_weights = { 7, 4, 5, 6 };
	cout << solution(length, weight, truck_weights);
	return 0;
}