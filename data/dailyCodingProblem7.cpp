#include <bits/stdc++.h>
using namespace std;

/*
Given the mapping a = 1, b = 2, ... z = 26, and an encoded message,
count the number of ways it can be decoded.

For example, the message '111' would give 3,
since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable.
For example, '001' is not allowed.
*/

int numWays(string num, int n){
	int count[n+1];
	count[0] = count[1] = 1;
	
	for(int i=2; i<=n; i++){
		count[i] = 0;
		
		if(num[i-1] > '0'){
			count[i] += count[i-1];
		}
		
		if(num[i-2] == '1' || (num[i-2] == '2' && num[i-1] < '7')){
			count[i] += count[i-2];
		}
	}
	
	return count[n];
}

// main function
int main(){
	cout << numWays("111", 3) << "\n";
	cout << numWays("1234", 4) << "\n";
	return 0;
}