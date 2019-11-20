#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void removeFunc(int removeNum, vector<pair<int, vector<int>>>& graph);

int main() {
	// �׷��� ����
	// ��� ����� ������ ���� ����
	vector<pair<int, vector<int>>> graph;
	int n;
	cin >> n;
	// �׷��� ����� �۾�
	for (int i = 0; i < n; i++) {
		// ��� ����
		pair<int, vector<int>> node;
		// �ڽ� ������ ����Ʈ
		vector<int> childNode;
		// ����� Ű�� ����
		node.first = i;
		node.second = childNode;
		graph.push_back(node);
	}

	int parentNum, root;
	for (int i = 0; i < n; i++) {
		cin >> parentNum;
		// ��Ʈ ����̸�
		if (parentNum == -1) {
			// ����
			root = i;
			continue;
		}
		
		// �θ� ��忡 �ڽ� ��� ����
		graph.at(parentNum).second.push_back(i);
	}
	
	int removeNum;
	cin >> removeNum;
	// ���� �Լ�
	removeFunc(removeNum, graph);
	
	// ���� ��� Ž��
	int leafNodeCount = 0;
	for (int i = 0; i < n; i++) {
		// ������ ���� �ǳʶٱ�
		if (graph.at(i).first == -1) { continue; }
		
		// �ڽ� ��尡 �̹� ������ ����� ���� ���
		if (graph.at(i).second.size() == 1) {
			if (graph.at(i).second.back() == removeNum) {
				graph.at(i).second.pop_back();
				leafNodeCount++;
			}
		}

		// �ڽ� ��尡 ������ ���� ���
		else if (graph.at(i).second.size() == 0) {
			leafNodeCount++;
		}
	}

	cout << leafNodeCount;

	return 0;
}

void removeFunc(int removeNum, vector<pair<int, vector<int>>>& graph) {
	// ����� ���� ��� ����
	// vector �ȿ����� �������� ���ƾ� index�� ���� �Ǳ� ������ -1�� ����
	graph.at(removeNum).first = -1;
	// �ڽ� ��尡 ���ٸ� ��
	if (graph.at(removeNum).second.size() == 0) { return; }
	// �ڽ� ����� �ڽ� ���鵵 ����
	for (int removeNode : graph.at(removeNum).second) {
		removeFunc(removeNode, graph);
	}
}