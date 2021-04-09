#include <bits/stdc++.h>
using namespace std;

/*
Given a number in the form of a list of digits, return all possible permutations.
For example, given [1,2,3], return [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]].
*/

void permutationsHelper(int arr[], int n, int l, int r, vector<vector<int>>& v){
	if(l == r)
		v.push_back(vector<int>(arr,arr+n));
	else
		for(int i=l;i<=r;i++){
			swap(arr[l], arr[i]);
			permutationsHelper(arr, n, l+1, r, v);
			swap(arr[i], arr[l]);
		}
}

vector<vector<int>> permutations(int arr[], int n){
	vector<vector<int>> v;
	permutationsHelper(arr, n, 0, n-1, v);
	return v;
}

// main function
int main(){
	int arr[] = {1,2,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<vector<int>> ans = permutations(arr, n);
	for(auto it : ans){
		for(auto i : it)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}