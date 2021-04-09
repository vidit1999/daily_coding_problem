#include <bits/stdc++.h>
using namespace std;

/*
We can determine how "out of order" an array A is by counting the number of inversions it has.
Two elements A[i] and A[j] form an inversion if A[i] > A[j] but i < j. That is, a smaller
element appears after a larger element.

Given an array, count the number of inversions it has. Do this faster than O(N^2) time.

You may assume each element in the array is distinct.

For example, a sorted list has zero inversions. The array [2, 4, 1, 3, 5] has three
inversions: (2, 1), (4, 1), and (4, 3). The array [5, 4, 3, 2, 1] has ten inversions:
every distinct pair forms an inversion.
*/

int inversionCount(int arr[], int n){
	int count = 0 ;
	set<int> s;
	
	for(int i=n-1; i>=0; i--){
		auto it = s.insert(arr[i]).first;
		count += distance(s.begin(), it);
	}
	
	return count;
}

// main function
int main(){
	int arr[] = {2, 4, 1, 3, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout << inversionCount(arr, n) << "\n";
	
	return 0;
}