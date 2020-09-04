#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers, determine whether it contains a Pythagorean triplet.
Recall that a Pythogorean triplet (a, b, c) is defined by the equation a2+ b2= c2.
*/

// O(n^2) time | O(n) space
bool containPythagirian(int arr[], int n){
	sort(arr, arr+n, greater<int>()); // sort the array in decresing order
	
	for(int i=0;i<n;i++){
		int req_num = arr[i]*arr[i];
		unordered_set<int> uset;
		
		for(int j=i+1;j<n;j++){
			if(uset.find(arr[j]*arr[j]) != uset.end())
				return true;
			uset.insert(req_num - arr[j]*arr[j]);
		}
	}
	return false;
}

// O(n^2) time | O(1) space
bool containPythagirian2(int arr[], int n){
	sort(arr, arr+n, greater<int>());
	
	for(int i=0;i<n;i++){
		int l = i+1;
		int r = n-1;
		while(l < r){
			if(arr[l]*arr[l] + arr[r]*arr[r] == arr[i]*arr[i])
				return true;
			(arr[l]*arr[l] + arr[r]*arr[r] < arr[i]*arr[i])? l++ : r--;
		}
	}
	
	return false;
}

// main function
int main(){
	int arr[] = {3, 4, 7, 6, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	if(containPythagirian2(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}