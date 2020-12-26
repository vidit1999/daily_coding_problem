#include <bits/stdc++.h>
using namespace std;

/*
In front of you is a row of N coins, with values v1, v1, ..., vn.

You are asked to play the following game. You and an opponent take
turns choosing either the first or last coin from the row, removing
it from the row, and receiving the value of the coin.

Write a program that returns the maximum amount of money you can
win with certainty, if you move first, assuming your opponent plays optimally.
*/

int maxAmountWinHelper(
	int arr[], int first, int last,
	int sum, unordered_map<string, int>& dp
){
	if(first > last){
		return 0;
	}

	if(first == last){
		return arr[first];
	}

	string find_str = to_string(first) + "$" + to_string(last);
	
	if(dp.find(find_str) == dp.end()){
		dp[find_str] =  max(
			sum - maxAmountWinHelper(arr, first+1, last, sum - arr[first], dp),
			sum - maxAmountWinHelper(arr, first, last-1, sum - arr[last], dp)
		);
	}

	return dp[find_str];
}

int maxAmountWin(int arr[], int n){
	int sum = accumulate(arr, arr+n, 0);
	unordered_map<string, int> dp;
	return maxAmountWinHelper(arr, 0, n-1, sum, dp);
}

// main function
int main(){
	int arr[] = {20, 30, 2, 2, 2, 10}; // {8, 15, 3, 7}, {2, 2, 2, 2}
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << maxAmountWin(arr, n) << "\n";
	return 0;
}