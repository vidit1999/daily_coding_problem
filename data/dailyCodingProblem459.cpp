#include <bits/stdc++.h>
using namespace std;

/*
Write a program that determines the smallest number of perfect squares that sum up to N.

Here are a few examples:

Given N = 4, return 1 (4)
Given N = 17, return 2 (16 + 1)
Given N = 18, return 2 (9 + 9)
*/

int getMinSquares(int n){
	int dp[n+1];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	
	for(int i=4;i<=n;i++){
		dp[i] = i;
		
		for(int x=1;x<=ceil(sqrt(i));x++){
			int temp = x*x;
			if(temp > i)
				break;
			else
				dp[i] = min(dp[i], 1+dp[i-temp]);
		}
	}
	
	return dp[n];
}

// main function
int main(){
	cout << getMinSquares(4) << "\n";
	cout << getMinSquares(17) << "\n";
	cout << getMinSquares(18) << "\n";
	return 0;
}