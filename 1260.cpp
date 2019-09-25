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
	searchBFS(start, list, checkBFS, resultBFS); // BFS 탐색
	
	for (int i = 0; i < resultDFS.size(); i++) {
		cout << resultDFS.top() << " ";
		resultDFS.pop();
	}
	cout << endl;
	for (int i = 0; i < resultBFS.size(); i++) {
		cout << resultBFS.front() << " ";
		resultBFS.pop();
	}

	delete[] list;
	delete[] checkBFS;
	delete[] checkDFS;
	return 0;
}

void searchBFS(int n, vector<int>* list, bool* check, queue<int>& result){
	if (check[n]) { // 접근 여부 확인
		return;
	}
	check[n] = true; // 한번 더 접근 못하게 처리
	for (int i = 0; i < list[n].size(); i++) { // 모든 간선 보기
		if (!check[list[n].at(i)]) { // 정점 접근 여부 확인
			result.push(list[n].at(i)); // 결과값(큐)에 넣음
		}
	}
	for (int i = 0; i < list[n].size(); i++) { // 모든 간선 보기
		if (!check[list[n].at(i)]) { // 정점 접근 여부 확인
			searchBFS(list[n].at(i), list, check, result); 
			  // 모든 정점에서 다시 BFS로 탐색
		}
	}
}

void searchDFS(int n, vector<int>* list, bool* check, stack<int>& result) {
	// 설명은 BFS와 같음
	if (check[n]) {
		return;
	}
	check[n] = true;
	for (int i = 0; i < list[n].size(); i++) {
		if (!check[list[n].at(i)]) {
			result.push(list[n].at(i));
			searchDFS(list[n].at(i), list, check, result);
			// 해당 정점에서 다시 DFS로 탐색
		}
	}
}