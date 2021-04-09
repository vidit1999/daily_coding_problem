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
	int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
	int min1 = INT_MAX, min2 = INT_MAX;
	
	for(int i=0; i<n; i++){
		if(arr[i] >= max1){
			max3 = max2;
			max2 = max1;
			max1 = arr[i];
		}
		else if(arr[i] >= max2){
			max3 = max2;
			max2 = arr[i];
		}
		else if(arr[i] >= max3){
			max3 = arr[i];
		}
		
		if(arr[i] <= min1){
			min2 = min1;
			min1 = arr[i];
		}
		else if(arr[i] <= min2){
			min2 = arr[i];
		}
	}
	
	return max(max1*max2*max3, max1*min1*min2);
}

// main function
int main(){
	int arr[] = {-10, -10, 5, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << largestProduct(arr, n) << "\n";
	return 0;
}