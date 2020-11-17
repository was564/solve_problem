#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main() {
	queue<int> deck;
	int N;
	cin >> N;
	
	for(int i=1;i<=N;i++){
		deck.push(i);
	}
	
	while(deck.front() != deck.back()){
		deck.pop();
		int save;
		save = deck.front();
		deck.pop();
		deck.push(save);
	}
	
	cout << deck.front();
	
	return 0;
}
