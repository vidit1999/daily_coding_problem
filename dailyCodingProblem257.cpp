#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers out of order, determine the bounds of the smallest
window that must be sorted in order for the entire array to be sorted.
For example, given [3, 7, 5, 6, 9], you should return (1, 3).
*/

pair<int, int> smallestWindow(int arr[], int n){
	int max_seen = INT_MIN, min_seen = INT_MAX;
	int left = -1, right = -1;
	
	for(int i=0; i<n; i++){
		if(arr[i] > max_seen)
			max_seen = arr[i];
		if(max_seen > arr[i])
			right = i;
	}
	
	for(int i=n-1; i>=0; i--){
		if(arr[i] < min_seen)
			min_seen = arr[i];
		if(min_seen < arr[i])
			left = i;
	}
	
	return {left, right};
}

// main function
int main(){
	int arr[] = {3, 7, 5, 6, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	auto ans = smallestWindow(arr, n);
	cout << ans.first << ", " << ans.second << "\n";
	
	return 0;
}