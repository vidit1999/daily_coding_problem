#include <bits/stdc++.h>
using namespace std;

/*
A permutation can be specified by an array P, where P[i] represents
the location of the element at i in the permutation. For example,
[2, 1, 0] represents the permutation where elements at the index
0 and 2 are swapped.

Given an array and a permutation, apply the permutation to the array.
For example, given the array ["a", "b", "c"] and the permutation
[2, 1, 0], return ["c", "b", "a"].
*/

vector<string> permutationArray(vector<string> arr, vector<int> perm){
	int n = arr.size();
	
	for(int i=0; i<n; i++){
		int next = i;
		
		while(perm[next] >= 0){
			swap(arr[i], arr[perm[next]]);
			int temp = perm[next];
			perm[next] -= n;
			next = temp;
		}
	}
	
	return arr;
}

// main function
int main(){
	vector<string> arr = {"a", "b", "c"};
	vector<int> perm = {2, 1, 0};
	
	for(string s : permutationArray(arr, perm))
		cout << s << " ";
	cout << "\n";
	
	return 0;
}