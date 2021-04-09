#include <bits/stdc++.h>
using namespace std;

/*
Given a multiset of integers, return whether it can be partitioned
into two subsets whose sums are the same.

For example, given the multiset {15, 5, 20, 10, 35, 15, 10},
it would return true, since we can split it up into
{15, 5, 10, 15, 10} and {20, 35}, which both add up to 55.

Given the multiset {15, 5, 20, 10, 35}, it would return false,
since we can't split it up into two subsets that add up to the same sum.
*/

bool isSubsetSumHelper(int arr[], int n, int sum, unordered_map<string, bool>& dp){
	if(sum == 0) return true;
	if(n == 0) return false;
	
	string dp_string = to_string(n) + "$" + to_string(sum);
	
	if(dp.find(dp_string) != dp.end()) return dp[dp_string];
	
	bool ans = isSubsetSumHelper(arr, n-1, sum, dp);
	
	if(arr[n-1] <= sum) ans |= isSubsetSumHelper(arr, n-1, sum-arr[n-1], dp);
	
	dp[dp_string] = ans;
	
	return ans;
}

bool isPossiblePartition(int arr[], int n){
	int sum = accumulate(arr, arr+n, 0);
	
	if(sum&1) return false;
	
	unordered_map<string, bool> dp;
	
	return isSubsetSumHelper(arr, n, sum/2, dp);
}

// main function
int main(){
	int arr[] = {15, 5, 20, 10, 35, 15, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout << boolalpha << isPossiblePartition(arr, n) << "\n";
	
	return 0;
}