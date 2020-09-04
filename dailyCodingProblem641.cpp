#include <bits/stdc++.h>
using namespace std;

/*
Given a sorted array, find the smallest positive integer
that is not the sum of a subset of the array.

For example, for the input [1, 2, 3, 10],
you should return 7.

Do this in O(N) time.
*/

int smallestPosInt(int arr[], int n){
	int res = 1;
	
	for(int i=0; i<n && res >= arr[i]; i++){
		res += arr[i];
	}
	
	return res;
}

// main function
int main(){
	int arr[] = {1, 2, 3, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << smallestPosInt(arr, n) << "\n";
	return 0;
}