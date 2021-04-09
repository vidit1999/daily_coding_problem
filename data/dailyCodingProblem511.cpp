#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of integers, where each element represents the maximum
number of steps that can be jumped going forward from that element.
Write a function to return the minimum number of jumps you must take
in order to get from the start to the end of the array.

For example, given [6, 2, 4, 0, 5, 1, 1, 4, 2, 9], you should return 2,
as the optimal solution involves jumping from 6 to 5, and then from 5 to 9.
*/

// O(^2) solution
int minJumps(int arr[], int n){
	if(n == 0 || arr[0] == 0)
		return INT_MAX;
	
	int jumps[n];
	jumps[0] = 0;
	
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(i <= j+arr[j] && jumps[j] != INT_MAX){
				jumps[i] = min(jumps[i], jumps[j]+1);
				break;
			}
		}
	}
	
	return jumps[n-1];
}

// O(n) solution
int minJumps2(int arr[], int n){
	if(n <= 1)
		return 0;
	if(arr[0] == 0)
		return -1;
	
	int maxReach = arr[0];
	int step = arr[0];
	int jump = 1;
	
	for(int i=1;i<n;i++){
		if(i == n-1)
			return jump;
		maxReach = max(maxReach, i + arr[i]);
		step--;
		
		if(step == 0){
			if(i >= maxReach)
				return -1;
			jump++;
			step = maxReach - i;
		}
	}
	
	return -1;
}


// main function
int main(){
	int arr[] = {6, 2, 4, 0, 5, 1, 1, 4, 2, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << minJumps2(arr, n) << "\n";
	return 0;
}