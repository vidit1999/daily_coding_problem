#include <bits/stdc++.h>
using namespace std;

/*
Given a list of integers, write a function that returns the largest
sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5.
[5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?
*/

int maxSum(int arr[], int n){
	int incl = arr[0];
	int excl = 0;
	
	for(int i=1; i<n; i++){
		int excl_new = max(incl, excl);
		incl = excl + arr[i];
		excl = excl_new;
	}
	
	return max(incl, excl);
}

// main function
int main(){
	int arr[] = {2, 4, 6, 2, 5}; // {5, 1, 1, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
    cout << maxSum(arr, n) << "\n"; 
	return 0;
}