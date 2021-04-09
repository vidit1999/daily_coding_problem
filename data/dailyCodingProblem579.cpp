#include <bits/stdc++.h>
using namespace std;

/*
Starting from 0 on a number line, you would like to make a series of jumps that lead to the integer N.

On the ith jump, you may move exactly i places to the left or right.

Find a path with the fewest number of jumps required to get from 0 to N.
*/

int getSum(int n){
	return n*(n+1)/2;
}

int countJumps(int n){
	n = abs(n);
	int ans = 0;
	
	while(getSum(ans) < n || (getSum(ans) - n) & 1) ans++;
	
	return ans;
}

// main function
int main(){
	cout << countJumps(9) << "\n";
	return 0;
}