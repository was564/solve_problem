#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<int> nums;
	int countPrimeNum = 0;
	int N, input;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> input;
		nums.push_back(input);
	}
	
	for(int& num : nums){
		if(num == 1) continue;
		bool isPrimeNum = true;
		for(int i=2;i<num;i++){
			if(num % i == 0) {
				isPrimeNum = false;
				break;
			}
		}
		if(isPrimeNum) countPrimeNum++;
	}
	
	cout << countPrimeNum;
	
	return 0;
}
