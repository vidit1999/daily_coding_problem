#include <bits/stdc++.h>
using namespace std;

/*
A permutation can be specified by an array P, where P[i] represents the location of the element at i
in the permutation. For example, [2, 1, 0] represents the permutation where elements at the index 0
and 2 are swapped.

Given an array and a permutation, apply the permutation to the array. For example,
given the array ["a", "b", "c"] and the permutation [2, 1, 0], return ["c", "b", "a"].
*/

void applyPerm(vector<string>& arr, vector<int> perm){
	vector<string> temp(perm.size());
	
	for(int i=0;i<perm.size();i++)
		temp[i] = arr[perm[i]];
	
	for(int i=0;i<perm.size();i++)
		arr[i] = temp[i];
}

// main function
int main(){
	vector<string> arr = {"a", "b", "c"};
	vector<int> perm = {2, 1, 0};
	
	applyPerm(arr, perm);
	
	for(string s : arr)
		cout << s << "\n";
	return 0;
}