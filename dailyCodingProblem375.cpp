#include <bits/stdc++.h>
using namespace std;

/*
The h-index is a metric used to measure the impact and productivity
of a scientist or researcher.

A scientist has index _h_ if _h_ of their _N_ papers have at least
_h_ citations each, and the other N - h papers have no more than _h_
citations each. If there are multiple possible values for _h_,
the maximum value is used.

Given an array of natural numbers, with each value representing
the number of citations of a researcher's paper, return the
h-index of that researcher.

For example, if the array was:

[4, 0, 0, 2, 3]

This means the researcher has 5 papers with 4, 1, 0, 2, and 3
citations respectively. The h-index for this researcher is 2,
since they have 2 papers with at least 2 citations and the
remaining 3 papers have no more than 2 citations.
*/

int calculateHIndex(int arr[], int n){
	int h_index = 0;
	
	sort(arr, arr+n, greater<int>());
	
	for(int i=0; i<n; i++){
		if(arr[i] <= i+1){
			h_index = max(h_index, arr[i]);
		}
	}
		
	return h_index;
}

// main function
int main(){
	int arr[] = {4, 0, 0, 2, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << calculateHIndex(arr, n) << "\n";
	return 0;
}