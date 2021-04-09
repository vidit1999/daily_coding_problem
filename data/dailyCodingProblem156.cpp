#include <bits/stdc++.h>
using namespace std;

/*
Given a positive integer n, find the smallest number of squared integers which sum to n.

For example, given n = 13, return 2 since 13 = 3^2 + 2^2 = 9 + 4.

Given n = 27, return 3 since 27 = 3^2 + 3^2 + 3^2 = 9 + 9 + 9.
*/

// exponential time complexity
int smallestSqIntegerCount(int n){
	if(sqrt(n) == floor(sqrt(n))) return 1;
	
	int ans = n;
	for(int i=1; i*i<=n; i++){
		int sq = i*i;
		ans = min(ans, 1+smallestSqIntegerCount(n-sq));
	}
	
	return ans;
}

// time O(n^2) | space O(n)
int smallestSqIntegerCountDP(int n){
	int dp[n+1];
	
	for(int i=0; i<=n; i++){
		dp[i] = i;
		for(int j=1; j*j<=i; j++){
			dp[i] = min(dp[i], 1+dp[i-j*j]);
		}
	}
	
	return dp[n];
}

// main function
int main(){
	cout << smallestSqIntegerCount(13) << "\n";
	cout << smallestSqIntegerCountDP(27) << "\n";
	cout << smallestSqIntegerCount(36) << "\n";
	cout << smallestSqIntegerCount(3) << "\n";
	return 0;
}