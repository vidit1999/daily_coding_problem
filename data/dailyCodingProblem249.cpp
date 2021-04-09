#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers, find the maximum XOR of any two elements.
*/

int maxXor(int arr[], int n){
	int max_xor = 0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++)
			max_xor = max(max_xor, arr[i]^arr[j]);
	}
	return max_xor;
}

// main function
int main(){
	int arr[] = {25, 10, 2, 8, 5, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout << maxXor(arr, n) << "\n";
	return 0;
}