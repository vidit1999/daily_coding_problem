#include <bits/stdc++.h>
using namespace std;

/*
Given an array of positive integers, divide the array into two subsets such
that the difference between the sum of the subsets is as small as possible.

For example, given [5, 10, 15, 20, 25], return the sets {10, 25} and {5, 15, 20},
which has a difference of 5, which is the smallest possible difference.
*/

// helper function for minSubsetSum
void minSumSubsetHelper(
	int arr[],
	int index, int calc_sum1,
	int calc_sum2, int& min_diff,
	vector<int>& v1, vector<int>& v2,
	pair<vector<int>, vector<int>>& ans
){
	if(index == 0){
		int diff = abs(calc_sum1 - calc_sum2);
		if(diff < min_diff){
			ans.first = v1;
			ans.second = v2;
			min_diff = diff;
		}
		return;
	}
	
	v1.push_back(arr[index-1]);
	minSumSubsetHelper(arr, index-1, calc_sum1+arr[index-1], calc_sum2, min_diff, v1, v2, ans);
	v1.pop_back();

	v2.push_back(arr[index-1]);
	minSumSubsetHelper(arr, index-1, calc_sum1, calc_sum2+arr[index-1], min_diff, v1, v2, ans);
	v2.pop_back();
}

// returns the two subsets
pair<vector<int>, vector<int>> minSumSubset(int arr[], int n){
	vector<int> v1, v2;
	pair<vector<int>, vector<int>> ans;
	int min_diff = INT_MAX;

	minSumSubsetHelper(arr, n, 0, 0, min_diff, v1, v2, ans);

	return ans;
}

//helper function of minSubsetSumDiff
int minSubsetSumDiffHelper(
	int arr[], int index, int calc_sum,
	int& sum, unordered_map<string, int>& dp
){
	if(index == 0){
		return abs(calc_sum - (sum - calc_sum));
	}

	string to_find = to_string(index) + "$" + to_string(calc_sum);
	
	if(dp.find(to_find) != dp.end()){
		return dp[to_find];
	}

	int ans = min(
		minSubsetSumDiffHelper(arr, index-1, calc_sum+arr[index-1], sum, dp),
		minSubsetSumDiffHelper(arr, index-1, calc_sum, sum, dp)
	);

	dp[to_find] = ans;

	return ans;
}


// to only get the difference
int minSubsetSumDiff(int arr[], int n){
	unordered_map<string, int> dp;
	int sum = accumulate(arr, arr+n, 0);
	return minSubsetSumDiffHelper(arr, n, 0, sum, dp);
}

// main function
int main(){
	int arr[] = {5, 10, 15, 20, 25};
	int n = sizeof(arr)/sizeof(arr[0]);
	auto ans = minSumSubset(arr, n);

	cout << minSubsetSumDiff(arr, n) << "\n";

	for(int i : ans.first){
		cout << i << " ";
	}
	cout << "\n";

	for(int i : ans.second){
		cout << i << " ";
	}
	cout << "\n";
	return 0;
}