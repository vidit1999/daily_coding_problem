#include <bits/stdc++.h>
using namespace std;

/*
Given a sorted array, find the smallest positive integer
that is not the sum of a subset of the array.

For example, for the input [1, 2, 3, 10],
you should return 7.

Do this in O(N) time.
*/

int findSmallestNotPresent(int arr[], int n){
	int ans = 1;
	
	for(int i=0; i<n && arr[i] <= ans; i++)
		ans += arr[i];
	
	return ans;
}

// main function
int main(){
	int arr[] = {1, 2, 3, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout << findSmallestNotPresent(arr, n) << "\n";
	return 0;
}