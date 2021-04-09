#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of length n + 1 whose elements belong to the set {1, 2, ..., n}.
By the pigeonhole principle, there must be a duplicate. Find it in linear time and space.
*/

vector<int> duplicateNumber(vector<int> arr){
	unordered_set<int> seen;
	vector<int> ans;
	
	for(int i : arr){
		if(seen.find(i) != seen.end())
			ans.push_back(i);
		seen.insert(i);
	}
	
	return ans;
}

// main function
int main(){
	vector<int> arr = {1,2,3,4,5,6,7,8,9,9};
	for(int i : duplicateNumber(arr))
		cout << i << "\n";
	return 0;
}