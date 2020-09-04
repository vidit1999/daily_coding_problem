#include <bits/stdc++.h>
using namespace std;

/*
Given an integer list where each number represents the number of hops you can make,
determine whether you can reach to the last index starting at index 0.

For example, [2, 0, 1, 0] returns true while [1, 1, 0, 1] returns false.
*/

bool isEndReachableHelper(int arr[], int& n, int index, unordered_set<int>& unreachable){
	// if we know that from this node we cannot reach end then return false
	if(unreachable.find(index) != unreachable.end()) return false;
	
	// reached the end so return true
	if(index == n-1) return true;
	
	// not reached end, but arr[index] is 0 then return false
	if(arr[index] == 0){
		unreachable.insert(index);
		return false;
	}
	
	// check for all possible reachable indices
	for(int i=1; i<=arr[index]; i++){
		if(index + i < n && isEndReachableHelper(arr, n, index+i, unreachable))
			return true;
	}
	
	unreachable.insert(index);
	return false;
}

bool isEndReachable(int arr[], int n){
	unordered_set<int> unreachable; // contains indices from which we cannot reach to the end
	return isEndReachableHelper(arr, n, 0, unreachable);
}

// main function
int main(){
	int arr[] = {2, 0, 1, 0}; // {1, 1, 0, 1}
	int n = sizeof(arr)/sizeof(arr[0]);
	
	if(isEndReachable(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}