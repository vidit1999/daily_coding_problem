#include <bits/stdc++.h>
using namespace std;

/*
Given a list of numbers and a number k, return
whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17,
return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
*/

bool twoSumArray(int arr[], int n, int k){
	unordered_set<int> seen;
	
	for(int i=0; i<n; i++){
		if(seen.find(arr[i]) != seen.end()){
			return true;
		}
		seen.insert(k - arr[i]);
	}
	
	return false;
}

// main function
int main(){
	int arr[] = {10, 15, 3, 7};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 17;
	
	cout << boolalpha << twoSumArray(arr, n, k) << "\n";
	
	return 0;
}