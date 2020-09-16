#include <bits/stdc++.h>
using namespace std;

/*
The power set of a set is the set of all its subsets.
Write a function that, given a set,
generates its power set.

For example, given the set {1, 2, 3}, it should return
{{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.

You may also use a list or array to represent a set.
*/

void powerSetHelper(int index, int& n, vector<int> pset, vector<int>& arr, vector<vector<int>>& power_set){
	if(index == n){
		power_set.push_back(pset);
		return;
	}
	
	powerSetHelper(index+1, n, pset, arr, power_set);
	pset.push_back(arr[index]);
	powerSetHelper(index+1, n, pset, arr, power_set);
}

vector<vector<int>> powerSet(vector<int> arr){
	int n = arr.size();
	vector<vector<int>> ans;
	powerSetHelper(0, n, {}, arr, ans);
	return ans;
}

// main function
int main(){
	for(auto v : powerSet({1, 2, 3})){
		for(int i : v){
			cout << i << " ";
		}
		cout << "\n";
	}
	return 0;
}