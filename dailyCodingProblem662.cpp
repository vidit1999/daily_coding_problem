#include <bits/stdc++.h>
using namespace std;

/*
Given n numbers, find the greatest common denominator between them.

For example, given the numbers [42, 56, 14], return 14.
*/

int gcd(int a, int b){
	if(a == 0)
		return b;
	return gcd(b%a, a);
}

int gcdArr(int arr[], int n){
	int ans = arr[0];

	for(int i=1; i<n; i++){
		ans = gcd(ans, arr[i]);
		if(ans == 1) return 1;
	}

	return ans;
}

// main function
int main(){
	int arr[] = {42, 56, 14};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << gcdArr(arr, n) << "\n";
	return 0;
}