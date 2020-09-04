#include <bits/stdc++.h>
using namespace std;

/*
You are given an array representing the heights of neighboring buildings on a city street,
from east to west. The city assessor would like you to write an algorithm that returns
how many of these buildings have a view of the setting sun, in order to properly value the street.

For example, given the array [3, 7, 8, 3, 6, 1], you should return 3,
since the top floors of the buildings with heights 8, 6,
and 1 all have an unobstructed view to the west.

Can you do this using just one forward pass through the array?
*/

int countCleanView(int arr[], int n){
	int count = 0;
	int max_so_far = INT_MIN;
	
	for(int i=n-1; i>=0; i--){
		if(arr[i] >= max_so_far){
			count++;
			max_so_far = arr[i];
		}
	}
	
	return count;
}

// main function
int main(){
	int arr[] = {3, 7, 8, 3, 6, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << countCleanView(arr, n) << "\n"; 
	return 0;
}