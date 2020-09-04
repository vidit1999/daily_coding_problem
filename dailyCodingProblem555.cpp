#include <bits/stdc++.h>
using namespace std;

/*
An sorted array of integers was rotated an unknown number of times.
Given such an array, find the index of the element in the array in faster than linear time.
If the element doesn't exist in the array, return null.
For example, given the array [13, 18, 25, 2, 8, 10] and the element 8, return 4 (the index of 8 in the array).
You can assume all the integers in the array are unique.
*/

int findElement(vector<int> arr, int number){
	int low = 0, high = arr.size()-1;
	
	while(low <= high){
		int mid = (low + high)/2;
		if(arr[mid] == number)
			return mid;
		
		if(arr[mid] > arr[low]){
			if(number >= arr[low] && number < arr[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
		else{
			if(number > arr[mid] && number <= arr[high])
				low = mid + 1;
			else
				high = mid - 1;
		}
	}
	
	return -1;
}

// main function
int main(){
	cout << findElement({13, 18, 25, 2, 8, 10}, 8) << "\n";
	return 0;
}