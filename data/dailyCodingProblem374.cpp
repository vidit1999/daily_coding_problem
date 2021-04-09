#include <bits/stdc++.h>
using namespace std;

/*
Given a sorted array arr of distinct integers, return the lowest index i for which arr[i] == i.
Return null if there is no such index.

For example, given the array [-5, -3, 2, 3], return 2 since arr[2] == 2.
Even though arr[3] == 3, we return 2 since it's the lowest index.
*/

int indexEqValue(vector<int> arr){
	int low = 0, high = arr.size();
	
	while(low <= high){
		int mid = (low + high)/2;
		
		if(arr[mid] == mid) return mid;
		else if(arr[mid] < mid) low = mid + 1;
		else high = mid - 1;
	}
	
	return -1;
}

// main function
int main(){
	cout << indexEqValue({-5, -3, 2, 3}) << "\n";
	cout << indexEqValue({-10, -1, 0, 3, 10, 11, 30, 50, 100}) << "\n";
	return 0;
}