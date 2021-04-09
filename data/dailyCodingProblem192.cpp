#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of nonnegative integers. Let's say you start
at the beginning of the array and are trying to advance to the end.
You can advance at most, the number of steps that you're currently on.
Determine whether you can get to the end of the array.

For example, given the array [1, 3, 1, 2, 0, 1], we can go from
indices 0 -> 1 -> 3 -> 5, so return true.

Given the array [1, 2, 1, 0, 0], we can't reach the end,
so return false.
*/

bool isEndReachableHelper(int arr[], int reachable[], int n, int curr){
	if(reachable[curr] != -1) return reachable[curr];
	
	if(curr == n-1) return true; // we have reached the end
	
	// we have not reached the end but current position is 0
	// so we cannot move forward
	// so return false
	if(arr[curr] == 0){
		reachable[curr] = 0;
		return false;
	}
	
	for(int i=1; i<=arr[curr]; i++){
		if(curr + i < n && isEndReachableHelper(arr, reachable, n, curr+i)){
			reachable[curr] = 1;
			return true;
		}
	}
	
	reachable[curr] = 0;
	return false;
}

bool isEndReachable(int arr[], int n){
	int reachable[n];
	for(int i=0; i<n; i++) reachable[i] = -1;
	
	return isEndReachableHelper(arr, reachable, n, 0);
}

// main function
int main(){
	int arr[] = {1, 2, 1, 0, 0};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	if(isEndReachable(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}