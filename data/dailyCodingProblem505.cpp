#include <bits/stdc++.h>
using namespace std;

/*
Given an array and a number k that's smaller than the length of the array,
rotate the array to the right k elements in-place.
*/

void rotate_arr(int arr[], int n, int k){
	for(int j=1;j<=k;j++){
		int temp = arr[n - 1];
		for (int i = n - 1; i > 0; i--) 
			arr[i] = arr[i - 1];  
		arr[0] = temp; 
	}
}


// main function
int main(){
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	
	rotate_arr(arr, n, k);
	for(int i=0;i<n;i++)
		cout << arr[i] << " ";
	cout << "\n";
	return 0;
}