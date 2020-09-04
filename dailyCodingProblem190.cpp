#include <bits/stdc++.h>
using namespace std;

/*
Given a circular array, compute its maximum subarray sum in O(n) time.

For example, given [8, -1, 3, 4], return 15 as we choose the numbers
3, 4, and 8 where the 8 is obtained from wrapping around.

Given [-4, 5, 1, 0], return 6 as we choose the numbers 5 and 1.
*/

int kadane(int arr[], int n){
	int curr_max = arr[0];
	int max_so_far = arr[0];
	
	for(int i=1; i<n; i++){
		curr_max = max(arr[i], curr_max+arr[i]);
		max_so_far = max(max_so_far, curr_max);
	}
	
	return max_so_far;
}

int maxSubCircular(int arr[], int n){
	int max_kadane = kadane(arr, n);
	int sum = 0;
	
	for(int i=0; i<n; i++){
		sum += arr[i];
		arr[i] = -arr[i];
	}
	
	int max_wrap_sum = sum + kadane(arr, n);
	
	return max(max_wrap_sum, max_kadane);
}

// main function
int main(){
	int arr[] = {-4, 5, 1, 0};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << maxSubCircular(arr, n) << "\n";
	return 0;
}