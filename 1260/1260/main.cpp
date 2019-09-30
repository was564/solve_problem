#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>

using namespace std;

void searchBFS(int n, vector<int>* list, bool* check, queue<int>& result); // BFS
void searchDFS(int n, vector<int>* list, bool* check, stack<int>& result); // DFS

int main() {
	queue<int> resultBFS; // BFS 출력 순서 결과
	stack<int> resultDFS; // DFS 출력 순서 결과
	int n, m, start; // 정점 갯수, 간선 갯수, 시작지점
	cin >> n >> m >> start;
	vector<int>* list = new vector<int>[n+1]; // 그래프 리스트 선언
	bool* checkBFS = new bool[n + 1]; // BFS 정점 접근했는지 확인하는 배열
	bool* checkDFS = new bool[n + 1]; // DFS ''
	memset(checkBFS, false, sizeof(bool)*(n + 1)); // 배열의 모든 값을 false로 초기화
	memset(checkDFS, false, sizeof(bool)*(n + 1)); // ''


	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		list[u].push_back(v); // u와 v연결
		list[v].push_back(u); // v와 u연결
	}
	for (int i = 0; i <= n; i++) {
		sort(list[i].begin(), list[i].end()); // 모든 리스트 정렬
	}
	searchDFS(start, list, checkDFS, resultDFS); // DFS 탐색
	cout << endl;
	searchBFS(start, list, checkBFS, resultBFS); // BFS 탐색

	delete[] list;
	delete[] checkBFS;
	delete[] checkDFS;
	return 0;
}

void searchBFS(int n, vector<int>* list, bool* check, queue<int>& result) {
	result.push(n); // 루트 노드 큐에 추가
	check[n] = true; // 큐에 다시 못넣게 처리
	for (int i = 0; i < list[n].size(); i++) { // 루트 노드에 연결된 정점들 큐에 추가
		result.push(list[n].at(i)); 
		check[list[n].at(i)] = true; // 큐에 다시 못넣게 처리
	}
	while (!result.empty()) {
		static int value; // 한번만 정의하기 위해 static을 씀
		value = result.front(); // 추출값 저장
		cout << value << " "; // 큐에서 나온 값 출력
		result.pop();

		// 작은값부터 실행해야 하기 때문에 작은 값부터 큐에 넣음
		for (int i = 0; i < list[value].size(); i++) {
			if (!check[list[value].at(i)]) { // 큐에 추가한 적이 없으면
				result.push(list[value].at(i)); // 큐에 추가
				check[list[value].at(i)] = true;
			}
		}
	}
}

void searchDFS(int n, vector<int>* list, bool* check, stack<int>& result) {
	
	result.push(n); // 루트 노드 스택에 추가
	check[n] = true; // 노드 접근 여부를 true로 대입
	while (!result.empty()) {
		static int value; // 한 번만 정의하기 위해 static 사용
		value = result.top(); // 추출값 저장
		cout << value << " ";
		result.pop();

		// 작은값부터 실행해야 하기 때문에 큰 값부터 스택에 넣음
		for (int i = list[value].size() - 1; i >= 0 ; i--) { 
			if (!check[list[value].at(i)]) { // 접근 안했으면 스택에 넣기
				result.push(list[value].at(i));
				check[list[value].at(i)] = true;
			}
		}
	}
}