#include <bits/stdc++.h>
using namespace std;

/*
Given a list of integers S and a target number k, write a function that returns a
subset of S that adds up to k. If such a subset cannot be made, then return null.

Integers can appear more than once in the list.
You may assume all numbers in the list are positive.

For example, given S = [12, 1, 61, 5, 9, 2] and k = 24,
return [12, 9, 2, 1] since it sums up to 24.
*/

bool isSubsetSum(
	int arr[], int n, int k,
	vector<int> v, vector<int>& ans,
	unordered_map<string, bool>& dp
){
    string dp_string = to_string(n) + "|" + to_string(k);

	if(k == 0){
		ans = v;
        dp[dp_string] = true;
		return true;
	}
	
	if(n == 0){
        dp[dp_string] = false;
        return false;
    }

	if(dp.find(dp_string) != dp.end()) return dp[dp_string];
	
	dp[dp_string] = isSubsetSum(arr, n-1, k, v, ans, dp);
	
	if(arr[n-1] > k || dp[dp_string]) return dp[dp_string];
	
	v.push_back(arr[n-1]);
	
	dp[dp_string] |= isSubsetSum(arr, n-1, k-arr[n-1], v, ans, dp);
	
	return dp[dp_string];
}

vector<int> subsetSumArray(int arr[], int n, int k){
	vector<int> ans;
	unordered_map<string, bool> dp;
	isSubsetSum(arr, n, k, {}, ans, dp);
	return ans;
}

// main function
int main(){
	int arr[] = {12, 1, 61, 5, 9, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 24;

	for(int i : subsetSumArray(arr, n, k)){
		cout << i << " ";
	}
	cout << "\n";
	
	return 0;
}