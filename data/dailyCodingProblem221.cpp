#include <bits/stdc++.h>
using namespace std;

/*
Let's define a "sevenish" number to be one which is either a power of 7,
or the sum of unique powers of 7. The first few sevenish numbers are
1, 7, 8, 49, and so on. Create an algorithm to find the nth sevenish number.
*/

int sevenishNum(int n){
	int power = 0;
	vector<int> pow7;
	
	while(pow7.size() <= n){
		int size = pow7.size();
		int next_power = pow(7, power++);
		pow7.push_back(next_power);
		
		for(int i=0; i<size; i++){
			pow7.push_back(next_power + pow7[i]);
		}
	}
	
	return pow7[n-1];
}

// main function
int main(){
	for(int i=1; i<=5; i++){
		cout << sevenishNum(i) << "\n";
	}
	return 0;
}