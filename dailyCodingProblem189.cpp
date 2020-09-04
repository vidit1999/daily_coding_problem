#include <bits/stdc++.h>
using namespace std;

/*
Given an array of elements, return the length of the longest
subarray where all its elements are distinct.

For example, given the array [5, 1, 3, 5, 2, 3, 4, 1],
return 5 as the longest subarray of distinct elements is [5, 2, 3, 4, 1].
*/

int longestSubarrayDistinct(int arr[], int n){
	int start = 0, max_len = 0;
	unordered_map<int, int> seen;
	
	for(int i=0; i<n; i++){
		if(seen.find(arr[i]) != seen.end()){
			int last_seen = seen[arr[i]];
			if(last_seen >= start){
				int length = start - i;
				max_len = max(max_len, length);
				start = last_seen + 1;
			}
		}
		else{
			seen[arr[i]] = i;
		}
	}
	
	return max_len;
}

// main function
int main(){
	int arr[] = {5, 1, 3, 5, 2, 3, 4, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << longestSubarrayDistinct(arr, n) << "\n";
	return 0;
}