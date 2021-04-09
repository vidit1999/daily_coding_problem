#include <bits/stdc++.h>
using namespace std;

/*
There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time.
Given N, write a function that returns the number of unique ways you can climb the staircase.
The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2

What if, instead of being able to climb 1 or 2 steps at a time,
you could climb any number from a set of positive integers X?
For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
*/

// for case of only 1 and 2
int countWays(int N){
	if(N == 0){
		return 1;
	}
	
	if(N < 0){
		return 0;
	}
	
	return countWays(N-1) + countWays(N-2);
}

// for general case of given X
int countWaysUtil(int N, int X[], int n){
	if(N == 0){
		return 1;
	}
	
	if(N < 0){
		return 0;
	}
	
	int count = 0;
	
	for(int i=0; i<n; i++){
		count += countWaysUtil(N-X[i], X, n);
	}
	
	return count;
}

// dp based approach
int countWaysHelper(int N, int X[], int n, unordered_map<int, int>& dp){
	if(N == 0){
		return 1;
	}
	
	if(N < 0){
		return 0;
	}
	
	if(dp.find(N) != dp.end()) return dp[N];
	
	int count = 0;
	
	for(int i=0; i<n; i++){
		count += countWaysUtil(N-X[i], X, n);
	}
	
	dp[N] = count;
	
	return count;  
}

int countWaysDP(int N, int X[], int n){
	unordered_map<int, int> dp;
	return countWaysHelper(N, X, n, dp);
}

// main function
int main(){
	int N = 5;
	int X[] = {1, 2, 3};// {1, 3, 5};
	int n = sizeof(X)/sizeof(X[0]);
	cout << countWaysDP(N, X, n) << "\n";
	return 0;
}