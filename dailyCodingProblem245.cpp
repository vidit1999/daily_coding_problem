#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of integers, where each element represents the maximum number of
steps that can be jumped going forward from that element. Write a function to return
the minimum number of jumps you must take in order to get from the start to the end of the array.

For example, given [6, 2, 4, 0, 5, 1, 1, 4, 2, 9], you should return 2,
as the optimal solution involves jumping from 6 to 5, and then from 5 to 9.
*/

int minJumpsToEnd(int arr[], int n){
	if(n == 0 || arr[0] == 0) return INT_MAX;
	
	int jumps[n];
	jumps[0] = 0;
	
	for(int i=1; i<n; i++){
		jumps[i] = INT_MAX;
		for(int j=0; j<i; j++){
			if(i <= j + arr[j] && jumps[j] != INT_MAX){
				jumps[i] = min(jumps[i], jumps[j]+1);
				break;
			}
		}
	}
	
	return jumps[n-1];
}

// main function
int main(){
	int arr[] = {1, 3, 6, 1, 0, 9};// {6, 2, 4, 0, 5, 1, 1, 4, 2, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout << minJumpsToEnd(arr, n) << "\n";
	
	return 0;
}