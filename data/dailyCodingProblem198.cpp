#include <bits/stdc++.h>
using namespace std;

/*
Given a set of distinct positive integers, find the largest subset such that every pair
of elements in the subset (i, j) satisfies either i % j = 0 or j % i = 0.

For example, given the set [3, 5, 10, 20, 21], you should return [5, 10, 20].
Given [1, 3, 6, 24], return [1, 3, 6, 24].
*/

vector<int> largestSubset(vector<int> arr){
	int n = arr.size();
	sort(arr.begin(), arr.end());
	vector<int> div_count(n, 1), prev(n, -1), ans;
	int max_ind = 0;
	
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(arr[i]%arr[j] == 0){
				if(div_count[i] < div_count[j]+1){
					div_count[i] = div_count[j]+1;
					prev[i] = j;
				}
			}
		}
		if(div_count[max_ind] < div_count[i])
			max_ind = i;
	}
	
	int k = max_ind;
	while(k >= 0){
		ans.push_back(arr[k]);
		k = prev[k];
	}
	
	return ans;
}

void testFunc(vector<vector<int>> v){
	for(auto arr : v){
		for(int i : largestSubset(arr))
			cout << i << " ";
		cout << "\n";
	}
}

// main function
int main(){
	testFunc({
		{3, 5, 10, 20, 21},
		{1, 3, 6, 24},
	});
	return 0;
}