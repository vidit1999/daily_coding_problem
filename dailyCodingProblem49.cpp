#include <bits/stdc++.h>
using namespace std;

/*
Given an array of numbers, find the maximum sum of any
contiguous subarray of the array.

For example, given the array [34, -50, 42, 14, -5, 86],
the maximum sum would be 137,
since we would take elements 42, 14, -5, and 86.

Given the array [-5, -1, -8, -9], the maximum sum would be 0,
since we would not take any elements.

Do this in O(N) time.
*/

int maxSumContig(int arr[], int n){
	int max_so_far = 0, max_ending_here = 0;
	
	for(int i=0; i<n; i++){
		max_ending_here += arr[i];
		
		if(max_ending_here < 0)
			max_ending_here = 0;
		else if(max_so_far < max_ending_here){
			max_so_far = max_ending_here;
		}
	}
	
	return max_so_far;
}

// main function
int main(){
	int arr[] = {34, -50, 42, 14, -5, 86}; // {-5, -1, -8, -9};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << maxSumContig(arr, n) << "\n";
	return 0;
}