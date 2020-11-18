#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

vector<string> pss;
vector<bool> checkVps;

bool solve(string& ps);

int main() {
	int N;
	string input;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> input;
		pss.push_back(input);
	}
	
	for(string ps : pss) {
		checkVps.push_back(solve(ps));
	}
	
	for(bool isVps : checkVps) {
		if(isVps) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}

bool solve(string& ps) {
	stack<bool> processing;
	for(int i=0; i<ps.size(); i++){
		if(ps[i] == '(')
			processing.push(true);
		else if(ps[i] == ')'){
			if(processing.empty()) 
				return false;
			processing.pop();
		}
	}
	if(!processing.empty()) return false;
	return true;
}