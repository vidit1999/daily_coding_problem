#include <bits/stdc++.h>
using namespace std;

/*
There are N couples sitting in a row of length 2 * N.
They are currently ordered randomly, but would like to
rearrange themselves so that each couple's partners
can sit side by side.

What is the minimum number of swaps necessary
for this to happen?
*/

int countSwapsHelper(
	int i, int& n, vector<int>& arr,
	unordered_map<int, int>& pairs,
	unordered_map<int, int>& indices
){
	if(i > n){
		return 0;
	}
	
	// already pair nothing to do
	if(pairs[arr[i]] == arr[i+1]){
		return countSwapsHelper(i+2, n, arr, pairs, indices);
	}
	
	// first part calculation
	int first_pair_index = indices[arr[i]];
	int second_index = i+1;
	
	swap(arr[second_index], arr[first_pair_index]);
	indices[first_pair_index] = second_index;
	indices[second_index] = first_pair_index;
	
	int ans1 = countSwapsHelper(i+2, n, arr, pairs, indices);
	
	swap(arr[second_index], arr[first_pair_index]);
	indices[first_pair_index] = second_index;
	indices[second_index] = first_pair_index;
	
	
	// second part calculation
	int second_pair_index = indices[arr[i+1]];
	int first_index = i;
	
	swap(arr[first_index], arr[second_pair_index]);
	indices[first_index] = second_pair_index;
	indices[second_pair_index] = first_index;
	
	int ans2 = countSwapsHelper(i+2, n, arr, pairs, indices);
	
	swap(arr[first_index], arr[second_pair_index]);
	indices[first_index] = second_pair_index;
	indices[second_pair_index] = first_index;
	
	// return result
	return 1+min(ans1, ans2);
}

int countSwaps(int n, unordered_map<int, int> pairs, vector<int> arr){
	unordered_map<int, int> indices;
	
	for(int i=0; i<arr.size(); i++){
		indices[arr[i]] = i;
	}
	
	return countSwapsHelper(0, n, arr, pairs, indices);
}

// main function
int main(){
	int n = 3;
	unordered_map<int, int> pairs = {{1, 3}, {2, 6}, {4, 5}};
	vector<int> arr = {3, 5, 6, 4, 1, 2};
	
	cout << countSwaps(n, pairs, arr) << "\n";
	
	return 0;
}