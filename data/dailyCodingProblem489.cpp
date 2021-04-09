#include <bits/stdc++.h>
using namespace std;

/*
Given an array of elements, return the length of the
longest subarray where all its elements are distinct

For example, given the array [5, 1, 3, 5, 2, 3, 4, 1],
return 5 as the longest subarray of distinct elements is [5, 2, 3, 4, 1].
*/

int longestSubarray(vector<int> arr){
	unordered_map<int, int> hashMap;
	int j, i=0, max_size=0;
	for(j=0;j<arr.size();j++){
		if(hashMap.find(arr[j]) != hashMap.end())
			i = max(i, hashMap[arr[j]]+1);
		hashMap[arr[j]] = j;
		max_size = max(max_size, j-i);
	}
	return max(max_size, j-i);
}

// main function
int main(){
	cout << longestSubarray({5, 1, 3, 5, 2, 3, 4, 1}) << "\n";
	return 0;
}