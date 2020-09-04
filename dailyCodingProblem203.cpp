#include <bits/stdc++.h>
using namespace std;

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown
to you beforehand. Find the minimum element in O(log N) time.
You may assume the array does not contain duplicates.

For example, given [5, 7, 10, 3, 4], return 3.
*/

int findMinElem(int arr[], int n){
	int low = 0, high = n-1;
	
	while(low < high){
		int mid = (low + high)/2;
		if(arr[mid] == arr[high])
			high--;
		else if(arr[mid] > arr[high])
			low = mid + 1;
		else
			high = mid;
	}
	
	return arr[high];
}

// main function
int main(){
	int arr[] = {5, 7, 10, 3, 4};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout << findMinElem(arr, n) << "\n";
	return 0;
}