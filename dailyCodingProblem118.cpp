#include <bits/stdc++.h>
using namespace std;

/*
Given a sorted list of integers, square the
elements and give the output in sorted order.

For example, given [-9, -2, 0, 2, 3],
return [0, 4, 4, 9, 81].
*/

void sortedSquare(int arr[], int n){
	int temp[n];
	
	int i = 0, start = 0, end = n-1;
	
	while(start <= end){
		if(arr[start]*arr[start] >= arr[end]*arr[end]){
            temp[i++] = arr[start]*arr[start];
            start++;
        }
        else{
            temp[i++] = arr[end]*arr[end];
            end--;
        }
	}
	
	reverse(temp, temp+n);
	
	for(i=0; i<n; i++) arr[i] = temp[i];
}

// main function
int main(){
	int arr[] = {-9, -2, 0, 2, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	sortedSquare(arr, n);
	
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";
	return 0;
}