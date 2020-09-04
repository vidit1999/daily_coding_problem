#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers, find the first missing positive integer in linear time
and constant space. In other words, find the lowest positive integer that does not
exist in the array. The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2.
The input [1, 2, 0] should give 3.

You can modify the input array in-place.
*/

int lowestMissingPosInt(int arr[], int n){
	int end = 0, res = 1;
	
	for(int i=0; i<n; i++){
		if(arr[i] > 0){
			swap(arr[end++], arr[i]);
		}
	}
	
	for(int i=0; i<end; i++){
		if(abs(arr[i])-1 < end && arr[abs(arr[i]) - 1] > 0){
			arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
		}
	}
	
	for(int i=0; i<end; i++){
		if(arr[i] > 0)
			return i+1;
	}
	
	return end+1;
}

// main function
int main(){
	int arr[] = {1, 2, 0}; // {3, 4, -1, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout << lowestMissingPosInt(arr, n) << "\n";
	
	return 0;
}