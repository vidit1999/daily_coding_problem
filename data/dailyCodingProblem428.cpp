#include <bits/stdc++.h>
using namespace std;

/*
You have N stones in a row, and would like to create from them a pyramid.
This pyramid should be constructed such that the height of each stone
increases by one until reaching the tallest stone, after which the
heights decrease by one. In addition, the start and end stones of
the pyramid should each be one stone high.

You can change the height of any stone by paying a cost of 1 unit
to lower its height by 1, as many times as necessary. Given this
information, determine the lowest cost method to produce this pyramid.

For example, given the stones [1, 1, 3, 3, 2, 1], the optimal
solution is to pay 2 to create [0, 1, 2, 3, 2, 1].
*/

int pyramidCreation(int arr[], int n){
	int left[n], right[n];
	
	left[0] = min(arr[0], 1);
	right[n-1] = min(arr[n-1], 1);
	
	for(int i=1; i<n; i++){
		left[i] = min(arr[i], 1+min(left[i-1], i));
	}
	
	for(int i=n-2; i>=0; i--){
		right[i] = min(arr[i], 1+min(right[i+1], n-i-1));
	}
	
	int total[n];
	
	for(int i=0; i<n; i++){
		total[i] = min(left[i], right[i]);
	}
	
	int max_index = 0;
	
	for(int i=0; i<n; i++){
		if(total[i] > total[max_index])
			max_index = i;
	}
	
	int cost = 0, height = total[max_index];
	
	for(int i=max_index; i>=0; i--){
		cost += arr[i] - height;
		if(height > 0)
			height--;
	}
	
	height = total[max_index] - 1;
	
	for(int i=max_index+1; i<n; i++){
		cost += arr[i] - height;
		if(height > 0)
			height--;
	}
	
	return cost;
}

// main function
int main(){
	int arr[] = {1, 1, 3, 3, 2, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout << pyramidCreation(arr, n) << "\n";
	return 0;
}