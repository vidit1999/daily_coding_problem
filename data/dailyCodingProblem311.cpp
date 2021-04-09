#include <bits/stdc++.h>
using namespace std;

/*
Given an unsorted array, in which all elements are distinct, find a "peak" element in O(log N) time.

An element is considered a peak if it is greater than both its left and right neighbors.
It is guaranteed that the first and last elements are lower than all others.
*/

/*
arr[i-1] <= arr[i] => arr[i+1] for 0 < i < n-1
arr[i] >= arr[i+1] for i = 0
arr[i] <= arr[i-1] for i = n-1
*/

int findPeak(vector<int> arr){
	int low = 0, high = arr.size()-1;
	
	while(low <= high){
		int mid = (low + high)/2;
		if(
			(mid == 0 && arr[mid] >= arr[mid+1]) ||
			(mid == arr.size()-1 && arr[mid] >= arr[mid-1]) ||
			(mid > 0 && mid < arr.size()-1 && arr[mid] >= arr[mid-1] && arr[mid] >= arr[mid+1])
		)
			return arr[mid];
		if(mid - 1 >= 0 && arr[mid - 1] > arr[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	
	return -1;
}

// main function
int main(){
	cout << findPeak({8, 9, 10, 2, 5, 6}) << "\n";
	return 0;
}