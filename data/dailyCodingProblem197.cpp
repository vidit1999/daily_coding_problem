#include <bits/stdc++.h>
using namespace std;

/*
Given an array and a number k that's smaller than the length of the array,
rotate the array to the right k elements in-place.
*/

void rotateArray(int arr[], int n, int k){
	reverse(arr, arr+n); // reverse the whole array
	reverse(arr, arr+k); // reverse the first k elements
	reverse(arr+k, arr+n); // reverse the last n-k elements
}

// main function
int main(){
	int arr[] = {-1,-100,3,99};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 2;
	rotateArray(arr, n, k);
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";
	return 0;
}