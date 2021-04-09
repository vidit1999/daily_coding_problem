#include <bits/stdc++.h>
using namespace std;

/*
Write a function that rotates a list by k elements.
For example, [1, 2, 3, 4, 5, 6] rotated by two becomes
[3, 4, 5, 6, 1, 2]. Try solving this without creating a copy of the list.
*/

void rotateArray(int arr[], int n, int k){
	k %= n;
	reverse(arr, arr+n);
	reverse(arr, arr+n-k);
	reverse(arr+n-k, arr+n);
}

// main function
int main(){
	int arr[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 2;
	
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";
	
	rotateArray(arr, n, k);
	
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";
	
	return 0;
}
