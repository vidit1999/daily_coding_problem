#include <bits/stdc++.h>
using namespace std;

/*
Given a sorted list of integers of length N, determine if an element x
is in the list without performing any multiplication, division, or bit-shift operations.

Do this in O(log N) time.
*/

int divideBy2(int number){
	int quotient = 0;
	while(number >= 2){
		number -= 2;
		quotient++;
	}
	return quotient;
}

bool isPresent(int arr[], int n, int x){
	int low = 0, high = n-1;
	
	while(low <= high){
		int mid = divideBy2(low+high);
		if(arr[mid] == x)
			return true;
		else if(arr[mid] > x)
			high = mid - 1;
		else
			low = mid + 1;
	}
	
	return false;
}

// main function
int main(){
	int arr[] = {12, 23, 10, 23, 45, 67};
	int n = sizeof(arr)/sizeof(arr[0]);
	if(isPresent(arr, n, 15))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}