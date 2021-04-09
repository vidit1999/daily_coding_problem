#include <bits/stdc++.h>
using namespace std;

/*
Given an array of strictly the characters 'R', 'G', and 'B',
segregate the values of the array so that all the Rs come first,
the Gs come second, and the Bs come last. You can only swap elements of the array.

Do this in linear time and in-place.

For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'],
it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].
*/

void sortCharArray(char arr[], int n){
	int start = 0;
	
	for(int i=0; i<n; i++){
		if(arr[i] == 'R'){
			swap(arr[start++], arr[i]);
		}
	}
	
	for(int i=start; i<n; i++){
		if(arr[i] == 'G'){
			swap(arr[start++], arr[i]);
		}
	}
}

// main function
int main(){
	char arr[] = {'G', 'B', 'R', 'R', 'B', 'R', 'G'};
	int n =  sizeof(arr)/sizeof(arr[0]);
	sortCharArray(arr, n);
	
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";
	
	return 0;
}