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
	queue<int> resultBFS; // BFS ��� ���� ���
	stack<int> resultDFS; // DFS ��� ���� ���
	int n, m, start; // ���� ����, ���� ����, ��������
	cin >> n >> m >> start;
	vector<int>* list = new vector<int>[n+1]; // �׷��� ����Ʈ ����
	bool* checkBFS = new bool[n + 1]; // BFS ���� �����ߴ��� Ȯ���ϴ� �迭
	bool* checkDFS = new bool[n + 1]; // DFS ''
	memset(checkBFS, false, sizeof(bool)*(n + 1)); // �迭�� ��� ���� false�� �ʱ�ȭ
	memset(checkDFS, false, sizeof(bool)*(n + 1)); // ''


	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		list[u].push_back(v); // u�� v����
		list[v].push_back(u); // v�� u����
	}
	for (int i = 0; i <= n; i++) {
		sort(list[i].begin(), list[i].end()); // ��� ����Ʈ ����
	}
	searchDFS(start, list, checkDFS, resultDFS); // DFS Ž��
	searchBFS(start, list, checkBFS, resultBFS); // BFS Ž��
	
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
	if (check[n]) { // ���� ���� Ȯ��
		return;
	}
	check[n] = true; // �ѹ� �� ���� ���ϰ� ó��
	for (int i = 0; i < list[n].size(); i++) { // ��� ���� ����
		if (!check[list[n].at(i)]) { // ���� ���� ���� Ȯ��
			result.push(list[n].at(i)); // �����(ť)�� ����
		}
	}
	for (int i = 0; i < list[n].size(); i++) { // ��� ���� ����
		if (!check[list[n].at(i)]) { // ���� ���� ���� Ȯ��
			searchBFS(list[n].at(i), list, check, result); 
			  // ��� �������� �ٽ� BFS�� Ž��
		}
	}
}

void searchDFS(int n, vector<int>* list, bool* check, stack<int>& result) {
	// ������ BFS�� ����
	if (check[n]) {
		return;
	}
	check[n] = true;
	for (int i = 0; i < list[n].size(); i++) {
		if (!check[list[n].at(i)]) {
			result.push(list[n].at(i));
			searchDFS(list[n].at(i), list, check, result);
			// �ش� �������� �ٽ� DFS�� Ž��
		}
	}
}