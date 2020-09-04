#include <bits/stdc++.h>
using namespace std;

/*
Given a number in the form of a list of digits,
return all possible permutations.

For example, given [1,2,3], return
[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]].
*/

void getPermHelper(vector<int> arr, int l, int r, vector<vector<int>>& all_perms){
	if(l == r){
		all_perms.push_back(arr);
		return;
	}
	
	for(int i=l; i<=r; i++){
		swap(arr[l], arr[i]);
		getPermHelper(arr, l+1, r, all_perms);
		swap(arr[l], arr[i]);
		
	}
}

vector<vector<int>> getPermutations(vector<int> arr){
	vector<vector<int>> all_perms;
	getPermHelper(arr, 0, arr.size()-1, all_perms);
	return all_perms;
}

// main function
int main(){
	for(auto perms : getPermutations({1, 2, 3})){
		for(int i : perms)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}