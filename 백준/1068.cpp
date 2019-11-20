#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void removeFunc(int removeNum, vector<pair<int, vector<int>>>& graph);

int main() {
	// 그래프 선언
	// 모든 노드의 정보를 가질 예정
	vector<pair<int, vector<int>>> graph;
	int n;
	cin >> n;
	// 그래프 만드는 작업
	for (int i = 0; i < n; i++) {
		// 노드 생성
		pair<int, vector<int>> node;
		// 자식 노드들의 리스트
		vector<int> childNode;
		// 노드의 키값 대입
		node.first = i;
		node.second = childNode;
		graph.push_back(node);
	}

	int parentNum, root;
	for (int i = 0; i < n; i++) {
		cin >> parentNum;
		// 루트 노드이면
		if (parentNum == -1) {
			// 저장
			root = i;
			continue;
		}
		
		// 부모 노드에 자식 노드 대입
		graph.at(parentNum).second.push_back(i);
	}
	
	int removeNum;
	cin >> removeNum;
	// 삭제 함수
	removeFunc(removeNum, graph);
	
	// 리프 노드 탐색
	int leafNodeCount = 0;
	for (int i = 0; i < n; i++) {
		// 삭제된 노드면 건너뛰기
		if (graph.at(i).first == -1) { continue; }
		
		// 자식 노드가 이미 지워진 노드라면 리프 노드
		if (graph.at(i).second.size() == 1) {
			if (graph.at(i).second.back() == removeNum) {
				graph.at(i).second.pop_back();
				leafNodeCount++;
			}
		}

		// 자식 노드가 없으면 리프 노드
		else if (graph.at(i).second.size() == 0) {
			leafNodeCount++;
		}
	}

	cout << leafNodeCount;

	return 0;
}

void removeFunc(int removeNum, vector<pair<int, vector<int>>>& graph) {
	// 지우고 싶은 노드 삭제
	// vector 안에서는 공백으로 남아야 index가 유지 되기 때문에 -1로 지정
	graph.at(removeNum).first = -1;
	// 자식 노드가 없다면 끝
	if (graph.at(removeNum).second.size() == 0) { return; }
	// 자식 노드의 자식 노드들도 삭제
	for (int removeNode : graph.at(removeNum).second) {
		removeFunc(removeNode, graph);
	}
}