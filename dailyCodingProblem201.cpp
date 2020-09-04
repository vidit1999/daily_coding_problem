#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of arrays of integers, where each array corresponds
to a row in a triangle of numbers. For example, [[1], [2, 3], [1, 5, 1]]
represents the triangle:

  1
 2 3
1 5 1

We define a path in the triangle to start at the top and go down one
row at a time to an adjacent value, eventually ending with an entry
on the bottom row. For example, 1 -> 3 -> 5. The weight of the path
is the sum of the entries.

Write a program that returns the weight of the maximum weight path.
*/

int maxPathSum(vector<vector<int>> arr){
	if(arr.empty()) return -1;
	
	int n = arr.size();
	
	for(int i=n-2; i>=0; i--){
		for(int j=0; j<arr[i].size(); j++){
			arr[i][j] += max(arr[i+1][j], arr[i+1][j+1]);
		}
	}
	
	return arr[0][0];
}

// main function
int main(){
	vector<vector<int>> arr = {{1}, {2, 3}, {1, 5, 1}};
	cout << maxPathSum(arr) << "\n";
	return 0;
}