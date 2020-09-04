#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of nonnegative integers.
Let's say you start at the beginning of the array and are trying to advance to the end.
You can advance at most, the number of steps that you're currently on.
Determine whether you can get to the end of the array.

For example, given the array [1, 3, 1, 2, 0, 1],
we can go from indices 0 -> 1 -> 3 -> 5, so return true.

Given the array [1, 2, 1, 0, 0],
we can't reach the end, so return false.
*/

bool isReachable(int arr[], int n){
	if(n > 1 && arr[0] == 0)
		return false;
	
	bool jump[] = { false };
	jump[0] = true;
	
	for(int i=0;i<n;i++){
		if(jump[i] && arr[i] > 0){
			for(int j=1;j<=arr[i];j++){
				if(arr[i] + j < n)
					jump[arr[i] + j] = true;
			}
		}
	}
	
	return jump[n-1];
}

// main function
int main(){
	int arr[] = {1, 2, 1, 0, 0};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	if(isReachable(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}