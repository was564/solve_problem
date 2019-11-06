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
	// 제일 적게 돌은 횟수 (answer)
	int min = 0;

	// target이 words안에 있는지 확인
	bool flag = true;
	for (string temp : words) {
		if (temp == target) {
			flag = false;
			break;
		}
	}
	// 없으면 0 출력
	if (flag) {
		return 0;
	}

	// 단어가 중복으로 바뀌었는지 확인
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