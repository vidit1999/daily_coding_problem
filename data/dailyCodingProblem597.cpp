#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers, determine whether it contains a Pythagorean triplet.
Recall that a Pythogorean triplet (a, b, c) is defined by the equation a2+ b2= c2.
*/

// O(n^2) time | O(n) space
bool pythagoreanTriplet(int arr[], int n){
	sort(arr, arr+n, greater<int>()); // sort the array in decresing order
	
	for(int i=0; i<n; i++){
		int required_sum = arr[i]*arr[i];
		unordered_set<int> uset;
		
		for(int j=i+1; j<n; j++){
			if(uset.find(arr[j]*arr[j]) != uset.end())
				return true;
			uset.insert(required_sum-arr[j]*arr[j]);
		}
	}
	
	return false;
}

// O(n^2) time | O(1) space
bool isPythagorean(int arr[], int n){
	sort(arr, arr+n, greater<int>()); // sort the array in decresing order
	
	for(int i=0; i<n; i++){
		int required_sum = arr[i]*arr[i];
		int low = i+1, high = n-1;
		while(low < high){
			int sum = arr[low]*arr[low] + arr[high]*arr[high];
			if(sum == required_sum)
				return true;
			else if(sum > required_sum)
				low++;
			else
				high--;
		}
	}
	
	return false;
}

// main function
int main(){
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int n = sizeof(arr)/sizeof(arr[0]);
	if(isPythagorean(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}