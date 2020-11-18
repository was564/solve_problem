#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Member {
	int old;
	string name;
	Member(int& old, string& name) : old(old), name(name) {}
};

bool compareOld(const Member& i, const Member& j) {
	return (i.old<j.old);
}

int main() {
	vector<Member> members;
	int N, old;
	string name;
	cin >> N;
	for(int i=0; i<N;i++) {
		cin >> old >> name;
		members.push_back(Member(old, name));
	}
	
	stable_sort(members.begin(), members.end(), compareOld);
	
	for(Member& member : members) {
		cout << member.old << " " << member.name << "\n";
	}
	
	return 0;
}