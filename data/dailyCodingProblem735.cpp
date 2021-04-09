#include <bits/stdc++.h>
using namespace std;

/*
Given an unsorted array, in which all elements are distinct,
find a "peak" element in O(log N) time.

An element is considered a peak if it is greater than both
its left and right neighbors. It is guaranteed that the
first and last elements are lower than all others.
*/

int findPeak(int arr[], int n, int low, int high){
	int mid = low + (high - low)/2;

	if(
		(mid == 0 || arr[mid] >= arr[mid-1]) &&
		(mid == n-1 || arr[mid] >= arr[mid+1])
	){
		return arr[mid];
	}

	if(mid >= 1 && arr[mid-1] >= arr[mid]){
		return findPeak(arr, n, low, mid-1);
	}

	return findPeak(arr, n, mid+1, high);
}

// main function
int main(){
	int arr[] = {10, 20, 15, 2, 23, 90, 67}; // {5, 10, 20, 15};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << findPeak(arr, n, 0, n-1) << "\n";
	return 0;
}