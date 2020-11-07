#include <bits/stdc++.h>
using namespace std;

/*
Given an N by M matrix consisting only of 1's and 0's,
find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

[[1, 0, 0, 0],
 [1, 0, 1, 1],
 [1, 0, 1, 1],
 [0, 1, 0, 0]]

Return 4.
*/

int maxAreaHist(vector<int>& arr, int n){
	stack<int> s;
	int max_area = 0;
	int i = 0;
	
	while(i < n){
		if(s.empty() || arr[s.top()] <= arr[i])
			s.push(i++);
		else{
			int t = s.top(); s.pop();
			max_area = max(
				max_area,
				arr[t]*((s.empty())? i : i-s.top()-1)
			);
		}
	}
	
	while(!s.empty()){
		int t = s.top(); s.pop();
		max_area = max(
			max_area,
			arr[t]*((s.empty())? i : i-s.top()-1)
		);
	}
	
	return max_area;
}

int maxAreaRectangle(vector<vector<int>> mat){
	if(mat.empty()) return 0;
	
	int n = mat[0].size();
	int ans = maxAreaHist(mat[0], n);
	
	for(int i=1; i<mat.size(); i++){
		for(int j=0; j<n; j++){
			mat[i][j] += mat[i-1][j];
		}
		ans = max(ans, maxAreaHist(mat[i], n));
	}
	
	return ans;
}

// main function
int main(){
	vector<vector<int>> mat = {
		{1, 0, 0, 0},
		{1, 0, 1, 1},
		{1, 0, 1, 1},
		{0, 1, 0, 0},
	};
	
	cout << maxAreaRectangle(mat) << "\n";
	
	vector<vector<int>> arr = {
		{0, 1, 1, 0},
		{1, 1, 1, 1},
		{1, 1, 1, 1},
		{1, 1, 0, 0},
	};
	
	cout << maxAreaRectangle(arr) << "\n";
	
	return 0;
}