#include <bits/stdc++.h>
using namespace std;

/*
Given a pivot x, and a list lst, partition the list into three parts.

The first part contains all elements in lst that are less than x
The second part contains all elements in lst that are equal to x
The third part contains all elements in lst that are larger than x
Ordering within a part can be arbitrary.

For example, given x = 10 and lst = [9, 12, 3, 5, 14, 10, 10],
one partition may be [9, 3, 5, 10, 10, 12, 14].
*/

void printList(int arr[], int n){
	for(int i=0;i<n;i++)
		cout << arr[i] << " ";
	cout << "\n";
}

void partitionList(int arr[], int n, int x){
	int start = 0, end = n-1;
	for(int i=0;i<n;i++){
		if(arr[i] < x && start <= i){
			swap(arr[start], arr[i]);
			start++;
		}
		else if(arr[i] > x && end >= i){
			swap(arr[end], arr[i]);
			end--;
		}
	}
}

// main function
int main(){
	int arr[] = {9, 12, 3, 5, 14, 10, 10};
	int n =sizeof(arr)/sizeof(arr[0]);
	int x = 10;
	partitionList(arr, n, x);
	printList(arr, n);
	return 0;
}