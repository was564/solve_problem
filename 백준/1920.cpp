#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
	
vector<int> nums;
vector<bool> checkExist;

int main() {
	int N, M;
	int input, findingNum;
	cin >> N;
	for(int i=0; i<N;i++){
		cin >> input;
		nums.push_back(input);
	}
	sort(nums.begin(), nums.end());
	cin >> M;
	for(int i=0;i<M;i++){
		int start = 0;
		int end = nums.size() - 1;
		cin >> findingNum;
		int mid = (end + start) / 2;
		bool isExist = false;
		while(end - start >= 0){
			if(nums[mid] == findingNum){
				checkExist.push_back(true);
				isExist = true;
				break;
			}
			else if(nums[mid] < findingNum) {
				start = mid + 1;
			}
			else if(nums[mid] > findingNum) {
				end = mid - 1;
			}
			
			mid = (end + start) / 2;
		}
		if(!isExist) checkExist.push_back(false);
	}
	
	for(bool isExist : checkExist) {
		if(isExist) cout << "1\n";
		else cout << "0\n";
	}
	
	return 0;
}
