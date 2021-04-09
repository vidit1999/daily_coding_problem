#include <bits/stdc++.h>
using namespace std;

/*
Given a multiset of integers, return whether it
can be partitioned into two subsets whose sums are the same.

For example, given the multiset {15, 5, 20, 10, 35, 15, 10},
it would return true, since we can split it up into
{15, 5, 10, 15, 10} and {20, 35}, which both add up to 55.

Given the multiset {15, 5, 20, 10, 35}, it would return false,
since we can't split it up into two subsets that add up to the same sum.
*/

bool subsetPartition(int arr[], int n){
	int sum = accumulate(arr, arr+n, 0);
	
	if(sum%2 != 0) return false;
	
	bool partition[sum/2+1][n+1];
	
	for(int i=0; i<=n; i++){
		partition[0][i] = true;
	}
	
	for(int i=1; i<=sum/2+1; i++){
		partition[i][0] = false;
	}
	
	for(int i=1; i<=sum/2+1; i++){
		for(int j=1; j<=n; j++){
			partition[i][j] = partition[i][j-1];
			if(i >= arr[j-1])
				partition[i][j] = partition[i][j-1] || partition[i-arr[j-1]][j-1];
		}
	}
	
	return partition[sum/2][n];
}

// main function
int main(){
	int arr[] = {15, 5, 20, 10, 35, 15, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout << subsetPartition(arr, n) << "\n";
	
	return 0;
}