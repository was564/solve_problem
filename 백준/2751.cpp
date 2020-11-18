#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<int> nums;
	int N, input;
	cin >> N;
	for(int i=0; i<N;i++){
		cin >> input;
		nums.push_back(input);
	}
	
	sort(nums.begin(), nums.end());
	
	for(int& num : nums) {
		cout << num << "\n";
	}
	
	return 0;
}