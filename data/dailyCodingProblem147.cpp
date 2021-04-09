#include <bits/stdc++.h>
using namespace std;

/*
Given a list, sort it using this method: reverse(lst, i, j), which sorts lst from i to j`.
*/

void reverseList(int arr[], int i, int j){
	while(i <= j){
		int temp = arr[i];
		arr[i++] = arr[j];
		arr[j--] = temp;
	}
}

int getMinIndex(int arr[], int start, int n){
	int min_index = start, min_elem = arr[start];
	
	for(int i=start; i<n; i++){
		if(arr[i] < min_elem){
			min_elem = arr[i];
			min_index = i;
		}
	}
	
	return min_index;
}

void sortArray(int arr[], int n){
	int start = 0;
	
	while(start < n){
		int index = getMinIndex(arr, start, n);
		reverseList(arr, start, index);
		start++;
	}
}

void printArray(int arr[], int n){
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

// main function
int main(){
	int arr[] = {2, 4, 3, 6, 10, 5, -1, -2, 0, -5};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	printArray(arr, n);
	sortArray(arr, n);
	printArray(arr, n);
	
	return 0;
}