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
	cout << endl;
	searchBFS(start, list, checkBFS, resultBFS); // BFS Ž��

	delete[] list;
	delete[] checkBFS;
	delete[] checkDFS;
	return 0;
}

void searchBFS(int n, vector<int>* list, bool* check, queue<int>& result) {
	result.push(n); // ��Ʈ ��� ť�� �߰�
	check[n] = true; // ť�� �ٽ� ���ְ� ó��
	for (int i = 0; i < list[n].size(); i++) { // ��Ʈ ��忡 ����� ������ ť�� �߰�
		result.push(list[n].at(i)); 
		check[list[n].at(i)] = true; // ť�� �ٽ� ���ְ� ó��
	}
	while (!result.empty()) {
		static int value; // �ѹ��� �����ϱ� ���� static�� ��
		value = result.front(); // ���Ⱚ ����
		cout << value << " "; // ť���� ���� �� ���
		result.pop();

		// ���������� �����ؾ� �ϱ� ������ ���� ������ ť�� ����
		for (int i = 0; i < list[value].size(); i++) {
			if (!check[list[value].at(i)]) { // ť�� �߰��� ���� ������
				result.push(list[value].at(i)); // ť�� �߰�
				check[list[value].at(i)] = true;
			}
		}
	}
}

void searchDFS(int n, vector<int>* list, bool* check, stack<int>& result) {
	
	result.push(n); // ��Ʈ ��� ���ÿ� �߰�
	check[n] = true; // ��� ���� ���θ� true�� ����
	while (!result.empty()) {
		static int value; // �� ���� �����ϱ� ���� static ���
		value = result.top(); // ���Ⱚ ����
		cout << value << " ";
		result.pop();

		// ���������� �����ؾ� �ϱ� ������ ū ������ ���ÿ� ����
		for (int i = list[value].size() - 1; i >= 0 ; i--) { 
			if (!check[list[value].at(i)]) { // ���� �������� ���ÿ� �ֱ�
				result.push(list[value].at(i));
				check[list[value].at(i)] = true;
			}
		}
	}
}