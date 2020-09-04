#include <bits/stdc++.h>
#define MAX_SIZE 100
using namespace std;

/*
Given a list of numbers L, implement a method sum(i, j) which
returns the sum from the sublist L[i:j] (including i, excluding j).

For example, given L = [1, 2, 3, 4, 5], sum(1, 3)
should return sum([2, 3]), which is 5.

You can assume that you can do some pre-processing.
sum() should be optimized over the pre-processing step.
*/

int prearr[MAX_SIZE];

void preprocess(int arr[], int n){
	for(int i=1; i<=n; i++) prearr[i] = arr[i-1] + prearr[i-1];
}

int sum(int i, int j, int n){
	if(
		i < 0 || i > n ||
		j < 0 || j > n ||
		i > j
	)
		return -1;
	return prearr[j] - prearr[i];
}

// main function
int main(){
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	preprocess(arr, n);
	
	cout << sum(1, 3, n) << "\n";
	cout << sum(0, 4, n) << "\n";
	cout << sum(-1, 2, n) << "\n";
	cout << sum(1, 5, n) << "\n";
	cout << sum(1, 6, n) << "\n";
	return 0;
}