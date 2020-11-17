#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> nums;
vector<bool> checkSame;

int main() {
	string input;
	while (true){
		cin >> input;
		if(input == "0") break;
		nums.push_back(input);
	}
	
	for(string& num : nums) {
		bool isSame = true;
		for(int i=0; i<num.size()/2;i++){
			if(num[i] != num[num.size() - i - 1]) {
				checkSame.push_back(false);
				isSame = false;
				break;
			}
		}
		if(isSame) checkSame.push_back(true);
	}
	
	for(bool isSame : checkSame) {
		if(isSame) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	
	return 0;
}
