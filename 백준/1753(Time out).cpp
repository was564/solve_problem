#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> answers; // 최단 거리
vector<bool> accessible;

void dfs(int vertexIndex, vector<bool> visited, int sum);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int V, E, K, u, v, w;
	// pair first : next Vertex, second : weight
	cin >> V >> E;
	graph.resize(V+1);
	answers.resize(V+1, V*10 + 1);
	accessible.resize(V+1, false);
	cin >> K;
	for(int i=0; i<E;i++) {
		cin >> u >> v >> w;
		graph[u].push_back(pair<int, int>(v, w));
	}
	
	vector<bool> visited;
	visited.resize(V+1, false);
	
	dfs(K, visited, 0);
	
	for(int i=1; i<V+1; i++){
		if(!accessible[i]) {
			cout << "INF\n";
			continue;
		}
		cout << answers[i] << "\n";
	}
	
	return 0;
}

void dfs(int vertexIndex, vector<bool> visited, int sum) {
	if(visited[vertexIndex]) return;
	visited[vertexIndex] = true;
	accessible[vertexIndex] = true;
	if(sum < answers[vertexIndex]) {
		answers[vertexIndex] = sum;
	}
	
	for(pair<int, int>& nextVertex : graph[vertexIndex]){
		dfs(nextVertex.first, visited, sum+nextVertex.second);
	}
}