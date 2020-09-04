#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers and a number k, where 1 <= k <= length of the array,
compute the maximum values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3,
we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)

Do this in O(n) time and O(k) space. You can modify the input array
in-place and you do not need to store the results. You can simply print them out as you compute them.
*/

void printKWindow(int arr[], int n, int k){
	deque<int> dq;
	
	int i = 0;
	
	for(; i<k; i++){
		while(!dq.empty() && arr[i] > arr[dq.back()]){
			dq.pop_back();
		}
		
		dq.push_back(i);
	}
	
	for(; i<n; i++){
		cout << arr[dq.front()] << "\n";
		
		while(!dq.empty() && dq.front() <= i - k){
			dq.pop_front();
		}
		
		while(!dq.empty() && arr[i] > arr[dq.back()]){
			dq.pop_back();
		}
		
		dq.push_back(i);
	}
	
	cout << arr[dq.front()] << "\n";
}

// main function
int main(){
	int arr[] = {10, 5, 2, 7, 8, 7};
	int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
	printKWindow(arr, n, k);
	return 0;
}