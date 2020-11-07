#include <iostream>
#include <vector>

using namespace std;

int solve();
void getTotalBuildTime(
	int point, 
	const vector<vector<int>>& graph,
	vector<int>& buildTime,
	vector<int>& totalBuildTime);

int main() {
	int T;
	vector<int> answers;
	
	cin >> T;
	for(int t = 0; t < T; t++){
		answers.push_back(solve());
	}
	
	for(int answer : answers) {
		cout << answer << endl;
	}
}

int solve() {
	int N, K, D, X, Y, W;
	vector<int> buildTime; // 건설시간을 담은 배열
	vector<vector<int>> graph; // 그래프, 각 건물을 지을 수 있는 조건을 담아놓은 배열
	vector<int> totalBuildTime; // 모든 조건을 만족하며 건물을 지을 때 걸리는 최대 시간
	
	cin >> N >> K;
	totalBuildTime.resize(N, -1);
	graph.resize(N);
	for(int n=0; n<N; n++){
		cin >> D;
		buildTime.push_back(D);
	}
	
	for(int k=0; k<K; k++){
		cin >> X >> Y;
		graph[Y - 1].push_back(X - 1);
	}
	cin >> W;
	
	getTotalBuildTime(W - 1, graph, buildTime, totalBuildTime);
	
	return totalBuildTime[W - 1];
}

void getTotalBuildTime( // 해당 건물을 짓는데 걸리는 최대시간
	int point,
	const vector<vector<int>>& graph,
	vector<int>& buildTime,
	vector<int>& totalBuildTime) {
	if(graph[point].size() == 0){ // 그냥 지을 수 있는 건물이면
		totalBuildTime[point] = buildTime[point]; // 해당 건물 짓는 시간이 최대 시간
		return;
	}
	int maxBuildingTime = -1; // 해당 건물을 짓는데 걸리는 최대시간
	for(int subBuilding : graph[point]) {
		if(totalBuildTime[subBuilding] == -1) { // 하위 건물들의 건설 최대 시간을 모르면
			getTotalBuildTime(subBuilding, graph, buildTime, totalBuildTime); // 구함
		}
		// 다른 하위 건물들보다 건설 시간이 더 느리면 최대 시간 갱신
		if(maxBuildingTime < totalBuildTime[subBuilding]) {
			maxBuildingTime = totalBuildTime[subBuilding];
		}
	}
	// 해당 건물의 최대 시간은 하위 건물 건설 최대시간에서 해당 건물의 건설 시간의 합
	totalBuildTime[point] = maxBuildingTime + buildTime[point];
}
