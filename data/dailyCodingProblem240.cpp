#include <bits/stdc++.h>
using namespace std;

/*
There are N couples sitting in a row of length 2 * N.
They are currently ordered randomly, but would like to rearrange
themselves so that each couple's partners can sit side by side.

What is the minimum number of swaps necessary for this to happen?
*/

int minSwapsUtil(int arr[], int pairs[], int index[], int i, int n){
	// base case if i > n return 0
	if(i > n) return 0;
	
	// if arr[i] and arr[i+1] no need to do anything
	if(arr[i+1] == pairs[arr[i]])
		return minSwapsUtil(arr, pairs, index, i+2, n);
	
	// get the pair of arr[i]
	// swap arr[i+1] with pair of arr[i]
	// change the index array
	// calculate the min swaps
	int index_of_arr_i_pair = index[pairs[arr[i]]];
	swap(arr[i+1], arr[index_of_arr_i_pair]);
	index[arr[i+1]] = index_of_arr_i_pair, index[arr[index_of_arr_i_pair]] = i+1;
	int a = minSwapsUtil(arr, pairs, index, i+2, n);
	
	// swap them back to bring the original configaration
	// change the index array back
	swap(arr[i+1], arr[index_of_arr_i_pair]);
	index[arr[i+1]] = i+1, index[arr[index_of_arr_i_pair]] = index_of_arr_i_pair;
	
	// get the pair of arr[i+1]
	// swap arr[i] with pair of arr[i+1]
	// change the index array
	// calculate the min swaps
	int index_of_arr_next_pair = index[pairs[arr[i+1]]];
	swap(arr[i], arr[index_of_arr_next_pair]);
	index[arr[i]] = index_of_arr_next_pair, index[arr[index_of_arr_next_pair]] = i;
	int b = minSwapsUtil(arr, pairs, index, i+2, n);
	
	// swap them back to bring original configaration
	// change index array back
	swap(arr[i], arr[index_of_arr_next_pair]);
	index[arr[i]] = i, index[arr[index_of_arr_next_pair]] = index_of_arr_next_pair;
	
	// return minimum of calculatation + 1
	return 1 + min(a,b);
}

int minSwaps(int arr[], int pairs[], int n){
	int index[2*n+1];
	for(int i=1; i<=n; i++)
		index[arr[i]] = i;
	
	return minSwapsUtil(arr, pairs, index, 1, 2*n);
}

// main function
int main(){
	int arr[] = {0, 3, 5, 6, 4, 1, 2};
	int pairs[] = {0, 3, 6, 1, 5, 4, 2};
	int m = sizeof(arr)/sizeof(arr[0]);
	int n = m/2;
	
	cout << minSwaps(arr, pairs, n) << "\n";
	return 0;
}