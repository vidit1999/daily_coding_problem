#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of arrays of integers, where each array
corresponds to a row in a triangle of numbers.
For example, [[1], [2, 3], [1, 5, 1]] represents the triangle:

  1
 2 3
1 5 1

We define a path in the triangle to start at the top and go down
one row at a time to an adjacent value, eventually ending with
an entry on the bottom row.
For example, 1 -> 3 -> 5.
The weight of the path is the sum of the entries.

Write a program that returns the weight of the maximum weight path.
*/

int maxSumPathHelper(int i, int j, int& n, vector<vector<int>>& arr, unordered_map<string, int>& dp){
	if(i == n){
		return 0;
	}
	
	string find_string = to_string(i) + "$" + to_string(j);
	
	if(dp.find(find_string) != dp.end()) return dp[find_string];
	
	dp[find_string] = arr[i][j] + max(maxSumPathHelper(i+1, j, n, arr, dp), maxSumPathHelper(i+1, j+1, n, arr, dp));
	
	return dp[find_string];
}

int maxSumPath(vector<vector<int>>& arr){
	int n = arr.size();
	unordered_map<string, int> dp;
	return maxSumPathHelper(0, 0, n, arr, dp);
}

// main function
int main(){
	vector<vector<int>> arr = {{1}, {2, 3}, {1, 5, 1}};
	cout << maxSumPath(arr) << "\n";
	return 0;
}