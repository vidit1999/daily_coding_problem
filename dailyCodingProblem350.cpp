#include <bits/stdc++.h>
using namespace std;

/*
Write a program that determines the smallest
number of perfect squares that sum up to N.

Here are a few examples:

Given N = 4, return 1 (4)
Given N = 17, return 2 (16 + 1)
Given N = 18, return 2 (9 + 9)

*/

int countSmallestSqHelper(int n, unordered_map<int, int>& dp){
	if(sqrt(n) == floor(sqrt(n))){
		return 1;
	}
	
	if(dp.find(n) != dp.end()) return dp[n];
	
	int ans = n;
	
	for(int i = 1; i*i <= n; i++){
		ans = min(ans, 1+countSmallestSqHelper(n-i*i, dp));
	}
	
	dp[n] = ans;
	
	return ans;
}

int countSmallestSq(int n){
	if(n < 0) return 0;
	
	unordered_map<int, int> dp;
	return countSmallestSqHelper(n, dp);
}

// main function
int main(){
	cout << countSmallestSq(4) << "\n";
	cout << countSmallestSq(17) << "\n";
	cout << countSmallestSq(18) << "\n";
	cout << countSmallestSq(6) << "\n";
	return 0;
}