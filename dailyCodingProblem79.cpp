#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers, write a function to determine whether the array
could become non-decreasing by modifying at most 1 element.

For example, given the array [10, 5, 7], you should return true,
since we can modify the 10 into a 1 to make the array non-decreasing.

Given the array [10, 5, 1], you should return false, since we
can't modify any one element to get a non-decreasing array.
*/

bool nonDecreasingByOne(vector<int> arr){
	if(arr.size() <= 1) return true;
	
	int modify_count = 0;
	
	if(arr[0] > arr[1]){
		arr[0] = arr[1]/2;
		modify_count++;
	}
	
	for(int i=1; i<arr.size()-1; i++){
		if(
			(arr[i] > arr[i+1] && arr[i] > arr[i-1]) ||
			(arr[i] < arr[i+1] && arr[i] < arr[i-1])
		){
			arr[i] = (arr[i+1 + arr[i-1]])/2;
			modify_count++;
		}
	}
	
	return modify_count <= 1;
}

// main function
int main(){
	cout << boolalpha << nonDecreasingByOne({10, 5, 7}) << "\n";
	cout << boolalpha << nonDecreasingByOne({10, 5, 1}) << "\n";
	return 0;
}