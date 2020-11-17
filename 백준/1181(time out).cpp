#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int solve();
	
int main() {
	int T = 1;
	vector<int> answers;
	
	//cin >> T;
	for(int t = 0; t < T; t++){
		answers.push_back(solve());
	}
	
	for(auto answer : answers) {
		//cout << answer << endl;
	}
}

int solve() {
	vector<string> words;
	string word;
	int N;
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> word;
		words.push_back(word);
	}
	
	for(int i=0; i<words.size(); i++){ // 단어 길이 단위로 정렬
		int minLengthWordIndex = -1; // 길이가 제일 짧은 단어 위치
		int minWordLength = 52; // 제일 짧은 단어의 길이
		for(int j=i; j<words.size(); j++){
			if(minWordLength > words[j].size()) {
				minWordLength = words[j].size();
				minLengthWordIndex = j;
			}
		}
		swap(words[i], words[minLengthWordIndex]);
	}
	
	for(string answer : words) {
		cout << answer << endl;
	}
	cout << endl;
	
	for(int i=0;i<words.size(); i++) { // 철자 단위로 정렬
		bool isFinal = false;
		int wordLength = words[i].size();
		int sameWordLengthIndex;
		for(int j=i; j<words.size(); j++){
			if(wordLength != words[j].size()){
				// 길이가 같은 단어들의 마지막 위치에 다음 위치를 저장
				sameWordLengthIndex = j;
				break;
			}
			else if(sameWordLengthIndex == words.size() - 1){
				isFinal = true;
			}
		}
		int frontWordIndex = i;
		for(int j=i; j<sameWordLengthIndex; j++){
			for(int k=j; k<sameWordLengthIndex; k++){
				for(int l=0; l<wordLength; l++){
					if(words[frontWordIndex][l] == words[k][l]) 
						continue;
					else if(words[frontWordIndex][l] > words[k][l]) {
						frontWordIndex = k;
					}
					break;
				}
			}
			swap(words[j], words[frontWordIndex]);
		}
		i = sameWordLengthIndex - 1; // 다음 단어 길이 선택
		if(isFinal) break;
	}
	
	string checkingSameWord = "";
	for(string answer : words) {
		if(checkingSameWord == answer) continue; // 겹치는거 있으면 스킵
		checkingSameWord = answer;
		cout << answer << endl;
	}
	
	
	
	return 0;
}
