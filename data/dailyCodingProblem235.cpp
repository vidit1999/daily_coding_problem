#include <bits/stdc++.h>
using namespace std;

/*
Given an array of numbers of length N, find both
the minimum and maximum using less than 2 * (N - 2) comparisons.
*/

// first elment is min and second in max
pair<int, int> minMaxArray(int arr[], int n) {
	if(n == 0) return {INT_MAX, INT_MIN};
	
	pair<int, int> ans;
	
	int i=0;
	if(n%2 == 0) {
		if(arr[i] > arr[i+1]){
			ans.first = arr[i+1];
			ans.second = arr[i];
		} else {
			ans.first = arr[i];
			ans.second = arr[i+1];
		}
		i += 2;
	} else {
		ans.first = ans.second = arr[i];
		i += 1;
	}
	
	while(i < n-1) {
		if(arr[i] > arr[i+1]) {
			if(arr[i] > ans.second)
				ans.second = arr[i];
			if(arr[i+1] < ans.first)
				ans.first = arr[i+1];
		} else {
			if(arr[i+1] > ans.second)
				ans.second = arr[i+1];
			if(arr[i] < ans.first)
				ans.first = arr[i];
		}
		i += 2;
	}
	
	return ans;
}

// main function
int main() {
	int arr[] = { 1000, 11, 445, 18, 330, 300 };
	int n = sizeof(arr)/sizeof(arr[0]);
	auto ans = minMaxArray(arr, n);
	cout << ans.first << " -- " << ans.second << "\n";
	return 0;
}