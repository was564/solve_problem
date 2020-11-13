#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int solve();
int compareBoard(
	char exampleBoard[][8][8],
	vector<string>& board,
	const int& x, 
	const int& y
);
	
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
	const char WHITE = 'W', BLACK = 'B'; // 색깔 정의
	int N, M;
	cin >> M >> N;
	vector<string> board; // M*N 크기의 보드
	char exampleBoard[2][8][8] = {
		{
			{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
			{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
			{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
			{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
			{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
			{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
			{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
			{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}
		},
		{
			{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
			{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
			{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
			{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
			{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
			{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
			{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
			{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}
		}
	};
	board.resize(M);
	string input;
	
	for(int i=0; i < M; i++){
		cin >> input;
		board[i] = input;
	}
	
	int minChanging = 64;
	for(int y=0; y<M - 7; y++){
		for(int x=0; x<N - 7; x++){
			// 비교가 가능한 좌표들을 전부다 비교하여 바뀐 수를 저장
			int changing = compareBoard(exampleBoard, board, x, y);
			if (minChanging > changing){
				minChanging = changing; // 그 중에 최저
			}
		}
	}
	
	cout << minChanging;
	
	return 0;
}

int compareBoard(
	char exampleBoard[][8][8], 
	vector<string>& board, 
	const int& x,
	const int& y) {
	int minChanging = 64;
	for(int index = 0; index<2;index++){ // 모든 예제판
		int changing = 0;
		for(int i=y; i<y + 8; i++){
			for(int j=x; j<x + 8; j++){
				if(board[i][j] != exampleBoard[index][i - y][j - x]){
					changing++; // 틀린게 있으면 바뀐거 하나씩 업
				}
			}
		}
		if(minChanging > changing) {
			minChanging = changing; // 그 중에 최저
		}
	}
	
	return minChanging;
}
