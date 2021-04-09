#include <bits/stdc++.h>
using namespace std;

/*
An sorted array of integers was rotated an unknown number of times.

Given such an array, find the index of the element in the array in
faster than linear time. If the element doesn't exist in the array,
return null.

For example, given the array [13, 18, 25, 2, 8, 10]
and the element 8,
return 4 (the index of 8 in the array).

You can assume all the integers in the array are unique.
*/

int sortedFind(int arr[], int n, int x){
	int low = 0, high = n-1;

	while(high >= low){
		int mid = low + (high-low)/2;
		
		if(arr[mid] == x)
			return mid;

		if(arr[mid] >= arr[low]){
			if(x >= arr[low] && x <= arr[mid])
				high = mid-1;
			else
				low = mid+1;
		}
		else{
			if(x >= arr[mid] && x <= arr[high])
				low = mid+1;
			else
				high = mid-1;
		}
	}

	return -1;
}

// main function
int main(){
	int arr[] = {13, 18, 25, 2, 8, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
	int x = 7;

	cout << sortedFind(arr, n , x) << "\n";

	return 0;
}