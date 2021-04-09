#include <bits/stdc++.h>
using namespace std;

/*
A wall consists of several rows of bricks of various integer lengths and uniform height.
Your goal is to find a vertical line going from the top to the bottom of the wall
that cuts through the fewest number of bricks. If the line goes through the edge
between two bricks, this does not count as a cut.

For example, suppose the input is as follows, where values in each
row represent the lengths of bricks in that row:

[[3, 5, 1, 1],
 [2, 3, 3, 2],
 [5, 5],
 [4, 4, 2],
 [1, 3, 3, 3],
 [1, 1, 6, 1, 1]]
The best we can we do here is to draw a line after the eighth brick,
which will only require cutting through the bricks in the third and fifth row.

Given an input consisting of brick lengths for each row such as the one above,
return the fewest number of bricks that must be cut to create a vertical line.
*/

int minCutNeeded(vector<vector<int>> wall){
	unordered_map<int, int> umap;
	int max_amount = 0;
	
	for(auto row : wall){
		int sum = 0;
		for(int i=0;i<row.size()-1;i++){
			sum += row[i];
			umap[sum]++;
		}
	}
	
	for(auto it : umap)
		max_amount = max(max_amount, it.second);
	
	return wall.size() - max_amount;
}

// main function
int main(){
	vector<vector<int>> wall = {
		{3, 5, 1, 1},
		{2, 3, 3, 2},
		{5, 5},
		{4, 4, 2},
		{1, 3, 3, 3},
		{1, 1, 6, 1, 1}
	};
	
	vector<vector<int>> wall2 = {
		{1,2,2,1},
        {3,1,2},
        {1,3,2},
        {2,4},
        {3,1,2},
		{1,3,1,1}
	};
	
	cout << minCutNeeded(wall) << "\n";
	cout << minCutNeeded(wall2) << "\n";
	return 0;
}