#include <bits/stdc++.h>
using namespace std;

/*
The power set of a set is the set of all its subsets.
Write a function that, given a set, generates its power set.

For example, given the set {1, 2, 3}, it should
return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.

You may also use a list or array to represent a set.
*/

vector<vector<int>> powerSets(int arr[], int n){
	vector<vector<int>> ans(1<<n);
	
	for(int i=0; i<(1<<n); i++){
		for(int j=0; j<n; j++){
			if(i & (1 << j))
				ans[i].push_back(arr[j]);
		}
	}
	
	return ans;
}

// main function
int main(){
	int arr[] = {1, 2, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	for(auto v : powerSets(arr, n)){
		for(int i : v)
			cout << i << " ";
		cout << "\n";
	}
	
	return 0;
}