#include <bits/stdc++.h>
using namespace std;

/*
Describe an algorithm to compute the longest
increasing subsequence of an array of numbers in O(n log n) time.
*/

// DP based solution using O(n^2) time
int longestIncresingSub(int arr[], int n){
	int lis[n]; // lis[i] stores length of lis ending with arr[i]
	lis[0] = 1;
	
	for(int i=1;i<n;i++){
		lis[i] = 1;
		for(int j=0; j<i; j++){
			if(arr[i] > arr[j] && lis[i] < lis[j]+1)
				lis[i] = lis[j]+1;
		}
	}
	return *max_element(lis, lis+n);
}

/*
arr = [10, 22, 9, 33, 21, 50, 41, 60]
ind = [0, 1, 2, 3, 4, 5, 6, 7]
After sorting
arr = [9, 10, 21, 22, 33, 41, 50, 60]
ind = [2, 0, 4, 1, 3, 6, 5, 7]

[50, 3, 10, 7, 40, 80]
*/

int longestIncresingSub2(vector<int> arr){
	if(arr.size() <= 1)
		return arr.size();
	
	vector<int> tail(arr.size(), 0);
	int length = 1;
	tail[0] = arr[0];
	
	for(int i=1; i<arr.size(); i++){
		auto b = tail.begin(), e = tail.begin() + length;
		auto it = lower_bound(b, e, arr[i]);
		
		if(it == e)
			tail[length++] = arr[i];
		else
			*it = arr[i];
	}
	return length;
}

// main function
int main(){
	int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	int n =sizeof(arr)/sizeof(arr[0]);
	// cout << longestIncresingSub(arr, n) << "\n";
	cout << longestIncresingSub2({10, 22, 9, 33, 21, 50, 41, 60}) << "\n";
	return 0;
}