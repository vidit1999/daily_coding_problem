#include <bits/stdc++.h>
using namespace std;

/*
Given an array of numbers N and an integer k, your task is to split N into
k partitions such that the maximum sum of any partition is minimized.
Return this sum.

For example, given N = [5, 1, 2, 7, 3, 4] and k = 3, you should return 8,
since the optimal partition is [5, 1, 2], [7], [3, 4].
*/

bool checkMid(int arr[], int n, int k, int mid){
	int count = 0, sum = 0;
	
	for(int i=0; i<n; i++){
		if(arr[i] > mid) return false;
		sum += arr[i];
		
		if(sum > mid){
			count++;
			sum = arr[i];
		}
	}
	
	if(++count <= k) return true;
	
	return false;
}

int splitMinMaxSum(int arr[], int n, int k){
	int start = 1, end;
	for(int i=0; i<n; i++)
		end += arr[i];
	
	int ans = 0;
	
	while(start <= end){
		int mid = (start + end)/2;
		
		if(checkMid(arr, n, k, mid)){
			ans = mid;
			end = mid-1;
		}
		else{
			start = mid+1;
		}
	}
	
	return ans;
}

// main function
int main(){
	int arr[] = {5, 1, 2, 7, 3, 4};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	
	cout << splitMinMaxSum(arr, n, k) << "\n";
	return 0;
}