#include <bits/stdc++.h>
#define R 4
#define C 4
using namespace std;

/*
You are given a 2D matrix of 1s and 0s where 1 represents land and 0 represents water.

Grid cells are connected horizontally orvertically (not diagonally).
The grid is completely surrounded by water, and there is exactly one island
(i.e., one or more connected land cells).

An island is a group is cells connected horizontally or vertically, but not diagonally.
There is guaranteed to be exactly one island in this grid, and the island doesn't
have water inside that isn't connected to the water around the island. Each cell has a side length of 1.

Determine the perimeter of this island.

For example, given the following matrix:

[[0, 1, 1, 0],
[1, 1, 1, 0],
[0, 1, 1, 0],
[0, 0, 1, 0]]

Return 14.
*/

int countOneNeighbour(int mat[R][C], int i, int j){
	int count = 0;
	
	if(i > 0 && mat[i-1][j]) count++;
	if(j > 0 && mat[i][j-1]) count++;
	if(i < R-1 && mat[i+1][j]) count++;
	if(j < C-1 && mat[i][j+1]) count++;
	
	return count;
}

int perimeterCount(int mat[R][C]){
	int perimeter = 0;
	
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(mat[i][j])
				perimeter += (4 - countOneNeighbour(mat, i, j));
		}
	}
	
	return perimeter;
}

// main function
int main(){
	int mat[R][C] = {
		{0, 1, 1, 0},
		{1, 1, 1, 0},
		{0, 1, 1, 0},
		{0, 0, 1, 0}
	};
	
	cout << perimeterCount(mat) << "\n";
	return 0;
}