#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> words;

bool compareWord(const string& a, const string& b) {
	if(a.size() == b.size()){
		return a<b;
	}
	else{
		return (a.size() < b.size());
	}
}

int main() {
	int N;
	string input;
	cin >> N;
	
	for(int i=0;i<N;i++){
		cin >> input;
		words.push_back(input);
	}
	
	sort(words.begin(), words.end(), compareWord);
	
	string checkWord = "";
	for(string& word : words) {
		if(checkWord == word){
			continue;
		}
		checkWord = word;
		cout << word << endl;
	}
	
	return 0;
}
