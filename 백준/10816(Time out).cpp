#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<int> cards;
	vector<int> findNums;
	vector<int> answers;
	int N, M, input;
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> input;
		cards.push_back(input);
	}
	cin >> M;
	for(int i=0;i<M; i++) {
		cin >> input;
		findNums.push_back(input);
	}
	
	sort(cards.begin(), cards.end());
	
	for(int& findNum : findNums){
		int mid, start, end;
		start = 0;
		end = cards.size() - 1;
		mid = (start + end) / 2;
		while(end >= start) {
			if(cards[mid] == findNum) break;
			else if(cards[mid] < findNum) {
				start = mid + 1;
			}
			else if(cards[mid] > findNum) {
				end = mid - 1;
			}
			mid = (start + end) / 2;
		}
		if(end < start) {
			answers.push_back(0);
			continue;
		}
		int downCount = 0;
		for(int i=mid - 1;i>=0; i--){
			if(cards[i] == findNum){
				downCount++;
			}
			else{
				break;
			}
		}
		int upCount = 0;
		for(int i=mid + 1;i<cards.size(); i++){
			if(cards[i] == findNum){
				upCount++;
			}
			else{
				break;
			}
		}
		answers.push_back(1 + upCount + downCount);
	}
	
	for(int& answer : answers) {
		cout << answer << " ";
	}
	
	return 0;
}
