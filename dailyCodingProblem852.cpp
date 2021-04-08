#include <bits/stdc++.h>
using namespace std;

/*
Given a circular array, compute its maximum subarray sum in O(n) time.
A subarray can be empty, and in this case the sum is 0.
For example, given [8, -1, 3, 4], return 15 as we choose
the numbers 3, 4, and 8 where the 8 is obtained from wrapping around.

Given [-4, 5, 1, 0], return 6 as we choose the numbers 5 and 1.
*/

// maximum sum contigious subarray in a normal array
int kadane(int arr[], int n){
	int maxEnd = 0, maxSoFar = 0;
	for(int i=0;i<n;i++){
		maxEnd += arr[i];
		if(maxEnd < 0)
			maxEnd = 0;
		else if(maxSoFar < maxEnd)
			maxSoFar = maxEnd;
	}
	return maxSoFar;
}

// maximum sum subarray in circular array
// calculate first maximum sum contigious subarray using kadane's algorithm
// then reverse the sign of each element and again calculate maximum sum using kadane's algorithm
// then return the max of first sum and (sum of whole array + secondsum)
int maxSumCircular(int arr[], int n){
	int maxKadane = kadane(arr, n);
	int arrSum = 0;
	for(int i=0;i<n;i++){
		arrSum += arr[i];
		arr[i] = -arr[i];
	}
	int maxWrap = arrSum + kadane(arr, n);
	return max(maxWrap, maxKadane);
}

// main function
int main(){
	int arr[] = {-4, 5, 1, 0};
	int n =sizeof(arr)/sizeof(arr[0]);
	cout << maxSumCircular(arr, n) << "\n";
	return 0;
}