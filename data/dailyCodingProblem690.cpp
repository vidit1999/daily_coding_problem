#include <bits/stdc++.h>
using namespace std;

/*
Given an array of numbers, find the length of the longest increasing subsequence in the array.
The subsequence does not necessarily have to be contiguous.

For example, given the array [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15],
the longest increasing subsequence has length 6: it is 0, 2, 6, 9, 11, 15.
*/

int longestIncresingSubSeq(int arr[], int n){
	int lis[n];
	
	for(int i=0; i<n; i++){
		lis[i] = 1;
		for(int j=0; j<i; j++){
			if(arr[i] > arr[j] && lis[i] < lis[j]+1){
				lis[i] = lis[j]+1;
			}
		}
	}
	
	return *max_element(lis, lis+n);
}

// main function
int main(){
	int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << longestIncresingSubSeq(arr, n) << "\n";
	return 0;
}