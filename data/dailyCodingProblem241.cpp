#include <bits/stdc++.h>
using namespace std;

/*
In academia, the h-index is a metric used to calculate the impact
of a researcher's papers. It is calculated as follows:

A researcher has index h if at least h of her N papers have h citations each.
If there are multiple h satisfying this formula, the maximum is chosen.

For example, suppose N = 5, and the respective citations of each
paper are [4, 3, 0, 1, 5]. Then the h-index would be 3, since the
researcher has 3 papers with at least 3 citations.

Given a list of paper citations of a researcher, calculate their h-index.
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
	int arr[] = {3,0,6,1,5}; // {4, 3, 0, 1, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << calculateHIndex(arr, n) << "\n";
	return 0;
}