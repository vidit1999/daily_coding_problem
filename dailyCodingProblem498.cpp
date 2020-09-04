#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers out of order, determine the bounds of the smallest window
that must be sorted in order for the entire array to be sorted.
For example, given [3, 7, 5, 6, 9], you should return (1, 3)
*/

pair<int ,int> windowRange(vector<int> arr){
	int s=0, e=arr.size()-1;
	
	for(;s<arr.size()-2;s++){
		if(arr[s] > arr[s+1])
			break;
	}
	
	if(s == arr.size()-1)
		return {0, 0};
	
	for(;e>=1;e--){
		if(arr[e] < arr[e-1])
			break;
	}
	
	int max = arr[s], min = arr[s];
	
	for(int i=s+1;i<=e;i++){
		if(arr[i] > max)
			max = arr[i];
		if(arr[i] < min)
			min = arr[i];
	}
	
	for(int i=0;i<s;i++){
		if(arr[i] > min){
			s = i;
			break;
		}
	}
	
	for(int i=arr.size()-1;i>e;i--){
		if(arr[i] < max){
			e = i;
			break;
		}
	}

	return {s, e};
}

// main function
int main(){
	pair<int, int> ans = windowRange({3, 7, 5, 6, 9});
	cout << ans.first << " -- " << ans.second << "\n";
	return 0;
}