#include <bits/stdc++.h>
using namespace std;

/*
Given a list, sort it using this method: reverse(lst, i, j),
which reverses lst from i to j.
*/

void reverseList(int arr[], int i, int j){
	while(i <= j){
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;
		j--;
	}
}

int findMinIndex(int arr[], int n, int start){
	int index = start, min_elem = INT_MAX;
	
	for(int i=start; i<n; i++){
		if(min_elem > arr[i]){
			index = i;
			min_elem = arr[i];
		}
	}
	
	return index;
}

void sortArray(int arr[], int n){
	int start = 0;
	
	while(start < n){
		int min_index = findMinIndex(arr, n, start);
		reverseList(arr, start, min_index);
		start++;
	}
}

// main function
int main(){
	int arr[] = {3, 4, 2, 6, 10, 5, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << "\n";
	
	sortArray(arr, n);
	
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
	cout << "\n";
	return 0;
}