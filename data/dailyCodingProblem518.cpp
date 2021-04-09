#include <bits/stdc++.h>
using namespace std;

/*
Given an array of numbers and a number k, determine if there are three entries in the array
which add up to the specified number k. For example, given [20, 303, 3, 4, 25] and k = 49,
return true as 20 + 4 + 25 = 49.
*/

bool threeSum(vector<int> arr, int sum){
	for(int i=0;i<arr.size()-2;i++){
		unordered_set<int> s;
		int curr_sum = sum - arr[i];
		for(int j=i+1;j<arr.size();j++){
			if(s.find(curr_sum-arr[j]) != s.end())
				return true;
			s.insert(arr[j]);
		}
	}
	return false;
}

// main function
int main(){
	if(threeSum({20, 303, 3, 4, 25}, 49))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}