#include <bits/stdc++.h>
using namespace std;

/*
Given an array of numbers and an index i, return the index of
the nearest larger number of the number at index i, where distance is measured in array indices.

For example, given [4, 1, 3, 5, 6] and index 0, you should return 3.

If two distances to larger numbers are the equal, then return
any one of them. If the array at i doesn't have a nearest larger integer, then return null.

Follow-up: If you can preprocess the array, can you do this in constant time?
*/

int closestDistance(int arr[], int n, int index){
	int left = index, right = index;
	
	while(left > 0 || right < n-1){
		left--; right++;
		if(left >= 0 && arr[left] > arr[index]) return left;
		if(right < n && arr[right] > arr[index]) return right;
	}
	
	return -1;
}

// main function
int main(){
	int arr[] = {4, 1, 3, 5, 6};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout << closestDistance(arr, n, 0) << "\n";
	cout << closestDistance(arr, n, 1) << "\n";
	cout << closestDistance(arr, n, 2) << "\n";
	cout << closestDistance(arr, n, 3) << "\n";
	cout << closestDistance(arr, n, 4) << "\n";

	return 0;
}