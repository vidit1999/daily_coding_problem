#include <bits/stdc++.h>
using namespace std;

/*
You are given a list of N numbers, in which each number is located at most k
places away from its sorted position. For example, if k = 1, a given element
at index 4 might end up at indices 3, 4, or 5.

Come up with an algorithm that sorts this list in O(N log k) time.
*/

void sortList(int arr[], int n, int k){
	priority_queue<int, vector<int>, greater<int>> pq(arr, arr+k+1);
	
	int index = 0;
	
	for(int i=k+1; i<n; i++){
		arr[index++] = pq.top();
		pq.pop();
		pq.push(arr[i]);
	}
	
	while(!pq.empty()){
		arr[index++] = pq.top();
		pq.pop();
	}
}

// main function
int main(){
	int arr[] = {2, 6, 3, 12, 56, 8};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	
	sortList(arr, n, k);
	
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << "\n";
	
	return 0;
}