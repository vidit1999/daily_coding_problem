#include <bits/stdc++.h>
using namespace std;

/*
A fixed point in an array is an element whose value is equal to its index.
Given a sorted array of distinct elements, return a fixed point, if one exists.
Otherwise, return False.

For example, given [-6, 0, 2, 40], you should return 2.
Given [1, 5, 7, 8], you should return False.
*/

int fixedPoint(int arr[], int n){
	int low = 0, high = n-1;
	
	while(low <= high){
		int mid = low + (high - low)/2;
		if(arr[mid] == mid)
			return mid;
		else if(arr[mid] > mid)
			high = mid - 1;
		else
			low = mid + 1;
	}
	
	return -1;
}

// main function
int main(){
	int arr[] = {-10, -1, 0, 3, 10, 11, 30, 50, 100};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << fixedPoint(arr, n) << "\n";
	return 0;
}