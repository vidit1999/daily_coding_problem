#include <bits/stdc++.h>
#define MAX 100
using namespace std;

/*
Write a program to determine how many distinct ways there are to create a max heap
from a list of N given integers.

For example, if N = 3, and our integers are [1, 2, 3], there are two ways, shown below.

  3      3
 / \    / \
1   2  2   1
*/

int dp[MAX], nck[MAX][MAX], Log2[MAX];

int choose(int n, int k){
	if(k > n) return 0;
	if(n <= 1 || k == 0) return 1;
	
	if(nck[n][k] != -1) return nck[n][k];
	nck[n][k] = choose(n-1, k-1) + choose(n-1, k);
	return nck[n][k];
}

int getLeft(int n){
	if(n == 1) return 0;
	
	int h = Log2[n];
	int numh = (1 << h);
	int p = n - (numh - 1);
	
	if(p >= numh/2)
		return numh-1;
	else
		return numh - 1 - (numh/2 - p);
}

int numHeaps(int n){
	if(n <= 1)
		return 1;
	if(dp[n] != -1)
		return dp[n];
	
	int left = getLeft(n);
	dp[n] = choose(n-1, left)*numHeaps(left)*numHeaps(n-1-left);
	return dp[n];
}

int solve(int n){
	for(int i=0;i<=n;i++){
		dp[i] = -1;
		for(int j=0;j<=n;j++)
			nck[i][j] = -1;
	}
	
	int currPower2 = 1, currLog2 = -1;
	
	for(int i=1;i<=n;i++){
		if(currPower2 == i){
			currLog2++;
			currPower2 *= 2;
		}
		Log2[i] = currLog2;
	}
	
	return numHeaps(n);
}

// main function
int main(){
	cout << solve(3) << "\n";
	cout << solve(10) << "\n";
	return 0;
}