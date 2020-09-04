#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers, return a new array such that each element at index i of
the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be
[120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
*/

vector<int> productArray(vector<int> arr){
	int n = arr.size(), prod = 1;
	vector<int> ans(n);
	
	for(int i=n-1; i>=0; i--){
		ans[i] = prod;
		prod *= arr[i];
	}
	
	prod = 1;
	
	for(int i=0; i<n; i++){
		ans[i] = prod*ans[i];
		prod *= arr[i];
	}
	
	return ans;
}

// main function
int main(){
	for(int i : productArray({1, 2, 3, 4, 5}))
		cout << i << "\n";
	return 0;
}