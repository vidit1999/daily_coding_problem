#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers, find the first missing positive integer
in linear time and constant space. In other words,
find the lowest positive integer that does not exist in the array.
The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2.
The input [1, 2, 0] should give 3.

You can modify the input array in-place.
*/

int moveNegLeft(int arr[], int n){
	int j=0;

	for(int i=0; i<n; i++){
		if(arr[i] <= 0){
			swap(arr[i], arr[j]);
			j++;
		}
	}

	return j;
}

int findMissingPositive(int arr[], int n){
	for(int i=0; i<n; i++){
		if((abs(arr[i])-1 < n) && (arr[abs(arr[i])-1] > 0)){
			arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
		}
	}

	for(int i=0; i<n; i++){
		if(arr[i] > 0){
			return i+1;
		}
	}

	return n+1;
}

int firstMissingPositive(int arr[], int n){
	int shift = moveNegLeft(arr, n);
	return findMissingPositive(arr+shift, n-shift);
}

// main function
int main(){
	int arr[] = {1, 2, 0};// {3, 4, -1, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << firstMissingPositive(arr, n) << "\n";
	return 0;
}