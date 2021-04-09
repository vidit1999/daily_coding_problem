#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers in which two elements appear exactly
once and all other elements appear exactly twice,
find the two elements that appear only once.
*/

pair<int, int> findAppearTwice(int arr[], int n){
	int xor_res = 0, set_bit;
	int x = 0, y = 0;
	
	for(int i=0; i<n; i++) xor_res ^= arr[i];
	
	set_bit = xor_res & ~(xor_res - 1);
	
	for(int i=0; i<n; i++){
		if(arr[i] & set_bit) x ^= arr[i];
		else y ^= arr[i];
	}
	
	return {x, y};
}

// main function
int main(){
	int arr[] = {4, 2, 4, 5, 2, 3, 3, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	auto ans = findAppearTwice(arr, n);
	cout << ans.first << ", " << ans.second << "\n";
	return 0;
}