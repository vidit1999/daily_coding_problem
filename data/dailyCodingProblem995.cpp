#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers, return a new array such that each element
at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be
[120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
*/

vector<int> productArray(vector<int> arr){
	if(arr.size() == 1) return {0};
	
	vector<int> product(arr.size(), 1); // initialize the product array with 1's
	int temp = arr[0];
	
	for(int i=1;i<arr.size();i++){
		product[i] *= temp;
		temp *= arr[i];
	}
	
	temp = arr[arr.size()-1];
	
	for(int i=arr.size()-2;i>=0;i--){
		product[i] *= temp;
		temp *= arr[i];
	}
	
	return product;
}

// main function
int main(){
	for(int i : productArray({3, 2, 1}))
		cout << i << " ";
	cout << "\n";
	return 0;
}