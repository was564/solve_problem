#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
	int num1, num2, temp;
	int gcd, lcm;
	cin >> num1 >> num2;
	if(num1 < num2) {
		swap(num1, num2);
	}
	
	int a, b;
	a= num1;
	b= num2;
	
	while(b != 0){
		temp = a%b;
		a = b;
		b = temp;
	}
	
	gcd = a;
	lcm = (int)num1*(num2/gcd);
	
	cout << gcd << "\n" << lcm;
	
	return 0;
}
