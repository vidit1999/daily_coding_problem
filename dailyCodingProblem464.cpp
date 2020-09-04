#include <bits/stdc++.h>
using namespace std;

/*
Given a set of distinct positive integers, find the largest subset such
that every pair of elements in the subset (i, j) satisfies either i % j = 0 or j % i = 0.

For example, given the set [3, 5, 10, 20, 21], you should return [5, 10, 20].
Given [1, 3, 6, 24], return [1, 3, 6, 24].
*/

// O(n^2)
vector<int> findLargest(int arr[], int n){
	sort(arr, arr+n); // O(nlogn)
	vector<int> divCount(n, 1);
	vector<int> res;
	int max_index = n-1;
	int max_size_subset = divCount[n-1];
	
	// O(n^2)
	for(int i=n-2;i>=0;i--){
		for(int j=i+1;j<n;j++){
			if(arr[j] % arr[i] == 0){
				divCount[i]++;
			}
			
			// get the maximum size subset and the index
			if(max_size_subset < divCount[i]){
				max_index = i;
				max_size_subset = divCount[i];
			}
		}
	}
	
	// O(n)
	int min_elem_of_subset = arr[max_index];
	for(int i=max_index;i<n;i++){
		if(arr[i] % min_elem_of_subset == 0)
			res.push_back(arr[i]);
	}
	
	return res;
}

// main function
int main(){
	int arr[] = {1, 3, 6, 24};
	int m =sizeof(arr)/sizeof(arr[0]);
	vector<int> res = findLargest(arr, m);
	for(int i : res)
		cout << i << "\n";
	return 0;
}