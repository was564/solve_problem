#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> cards;
vector<int> sums;


void selectCard(
	int M, 
	int countSelectingCard, 
	vector<bool> used,
	int sum);

int main() {
	vector<bool> emptyVector;
	int N, M, input;
	cin >> N >> M;
	for(int i=0; i<N; i++){
		cin >> input;
		cards.push_back(input);
	}
	sort(cards.begin(), cards.end());
	
	selectCard(M, 0, emptyVector, 0);
	
	int max = -1;
	for(int& sum : sums) {
		if(max < sum) {
			max = sum;
		}
	}
	
	cout << max;
	
	return 0;
}

void selectCard(
	int M, 
	int countSelectingCard, 
	vector<bool> used,
	int sum) {
	if(countSelectingCard == 3) {
		sums.push_back(sum);
		return;
	}
	else if(countSelectingCard == 0){
		used.resize(cards.size(), false);
	}
	
	for(int i=0; i<cards.size(); i++) {
		if(used[i]) continue;
		if(cards[i] >  M - sum) return;
		used[i] = true;
		selectCard(M, countSelectingCard+1, used, sum + cards[i]);
		used[i] = false;
	}
}