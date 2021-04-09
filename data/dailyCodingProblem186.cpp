#include <bits/stdc++.h>
using namespace std;

/*
Given an array of positive integers, divide the array into two subsets such that the
difference between the sum of the subsets is as small as possible.

For example, given [5, 10, 15, 20, 25], return the sets {10, 25} and {5, 15, 20},
which has a difference of 5, which is the smallest possible difference.
*/

pair<pair<vector<int>, vector<int>>, int> minSubsetSumHelper(
	int& sum,
	vector<int>& arr,
	int index,
	int subset_sum1,
	int subset_sum2,
	pair<vector<int>, vector<int>> subsets
){
	if(index < 0){
		return {
			subsets,
			abs(subset_sum1-subset_sum2)
		};
	}
	
	vector<int> v1 = subsets.first, v2 = subsets.second;
	
	v1.push_back(arr[index]);
	v2.push_back(arr[index]);
	
	auto ans1 = minSubsetSumHelper(sum, arr, index-1, subset_sum1+arr[index], subset_sum2, {v1, subsets.second});
	auto ans2 = minSubsetSumHelper(sum, arr, index-1, subset_sum1, subset_sum2+arr[index], {subsets.first, v2});
	
	return (ans1.second < ans2.second)? ans1 : ans2;
}

pair<vector<int>, vector<int>> minSubsetSum(vector<int> arr){
	int sum = accumulate(arr.begin(), arr.end(), 0);
    int n = arr.size();
	auto ans = minSubsetSumHelper(sum, arr, n-1, 0, 0, {{}, {}});
	return ans.first;
}

// main function
int main(){
	auto ans = minSubsetSum({5, 10, 15, 20, 25});
	for(int i : ans.first)
		cout << i << " ";
	cout << "\n";
	for(int i : ans.second)
		cout << i << " ";
	cout << "\n";
	return 0;
}