#include <bits/stdc++.h>
using namespace std;

/*
Given a list of integers, return the largest product
that can be made by multiplying any three integers.

For example, if the list is [-10, -10, 5, 2],
we should return 500, since that's -10 * -10 * 5.

You can assume the list has at least three integers.
*/

int largestProduct(int arr[], int n){
	int max_first = INT_MIN, max_second = INT_MIN, max_third = INT_MIN;
	int min_first = INT_MAX, min_second = INT_MAX;
	
	for(int i=0; i<n; i++){
		if(arr[i] >= max_first){
			max_third = max_second;
			max_second = max_first;
			max_first = arr[i];
		}
		else if(arr[i] >= max_second){
			max_third = max_second;
			max_second = arr[i];
		}
		else if(arr[i] >= max_third){
			max_third = arr[i];
		}
		
		if(arr[i] <= min_first){
			min_second = min_first;
			min_first = arr[i];
		}
		else if(arr[i] <= min_second){
			min_second = arr[i];
		}
	}
	
	return max(
		(min_first*min_second*max_first),
		(max_first*max_second*max_third)
	);
}

// main function
int main(){
	int arr[] = {-10, -10, 5, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout << largestProduct(arr, n) << "\n";
	
	return 0;
}