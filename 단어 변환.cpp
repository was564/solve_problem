#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

void createGraph(vector<string> words, vector<list<int>>& graph) {
	for (int i = 0; i < words.size(); i++) {

	}
}

int solution(string begin, string target, vector<string> words){
	// ���� ���� ���� Ƚ�� (answer)
	int min = 0;

	// target�� words�ȿ� �ִ��� Ȯ��
	bool flag = true;
	for (string temp : words) {
		if (temp == target) {
			flag = false;
			break;
		}
	}
	// ������ 0 ���
	if (flag) {
		return 0;
	}

	// �ܾ �ߺ����� �ٲ������ Ȯ��
	bool* check = new bool[words.size()];
	for (int i = 0; i < words.size(); i++) {
		check[i] = false;
	}

	vector<list<int>> graph;

	delete[] check;
}

int main() {
	string begin = "hit";
	string target = "cog";
	vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };
	cout << solution(begin, target, words);
	return 0;
}