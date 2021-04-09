#include <bits/stdc++.h>
using namespace std;

/*
Suppose an array sorted in ascending order is rotated at some pivot
unknown to you beforehand. Find the minimum element in O(log N) time.
You may assume the array does not contain duplicates.

For example, given [5, 7, 10, 3, 4], return 3.
*/

int minElement(int arr[], int low, int high){
	if(high < low) return arr[0];
	
	if(high == low) return arr[low];
	
	int mid = low + (high-low)/2;
	
	if(mid < high && arr[mid] > arr[mid+1]) return arr[mid+1];
	if(mid > low && arr[mid] < arr[mid-1]) return arr[mid];
	
	if(arr[high] > arr[mid])
		return minElement(arr, low, mid-1);
	return minElement(arr, mid+1, high);
}

// main function
int main(){
	int arr[] = {5, 7, 10, 3, 4};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << minElement(arr, 0, n-1);
	return 0;
}