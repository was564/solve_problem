#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {
	map<string, int> commands;
	commands["push"] = 0;
	commands["pop"] = 1;
	commands["size"] = 2;
	commands["empty"] = 3;
	commands["top"] = 4;
	stack<int> stack;
	vector<int> outputs;
	int N, inputNum;
	string inputCommand;
	cin >> N;
	for(int i=0; i<N; i++) {
		cin >> inputCommand;
		switch(commands[inputCommand]){
			case 0:
				cin >> inputNum;
				stack.push(inputNum);
				break;
			case 1:
				if(stack.empty()) outputs.push_back(-1); 
				else {
					outputs.push_back(stack.top());
					stack.pop();
				}
				break;
			case 2:
				outputs.push_back(stack.size());
				break;
			case 3:
				if(stack.empty()) outputs.push_back(1);
				else outputs.push_back(0);
				break;
			case 4:
				if(stack.empty()) outputs.push_back(-1);
				else outputs.push_back(stack.top());
		}
	}
	
	for(int& output : outputs) {
		cout << output << "\n";
	}
	
	return 0;
}