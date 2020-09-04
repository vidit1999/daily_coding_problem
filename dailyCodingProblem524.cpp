#include <bits/stdc++.h>
using namespace std;

/*
For example, given the array [34, -50, 42, 14, -5, 86], the maximum sum would be 137,
since we would take elements 42, 14, -5, and 86.

Given the array [-5, -1, -8, -9], the maximum sum would be 0, since we would not take any elements.
*/

int maxSum(vector<int> arr){
	int max_ending_here = 0;
	int max_so_far = 0;
	
	for(int i : arr){
		max_ending_here = max(0, max_ending_here+i);
		max_so_far = max(max_so_far, max_ending_here);
	}
	
	return max_so_far;
}

// main function
int main(){
	cout << maxSum({34, -50, 42, 14, -5, 86}) << "\n";
	cout << maxSum({-5, -1, -8, -9}) << "\n";
	return 0;
}