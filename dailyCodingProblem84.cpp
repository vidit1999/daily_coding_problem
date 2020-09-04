#include <bits/stdc++.h>
#define ROW 11
#define COLUMN 5
using namespace std;

/*
Given a matrix of 1s and 0s, return the number of "islands" in the matrix.
A 1 represents land and 0 represents water, so an island is a group of
1s that are neighboring and their perimiter is surrounded by water.

For example, this matrix has 4 islands.

1 0 0 0 0
0 0 1 1 0
0 1 1 0 0
0 0 0 0 0
1 1 0 0 1
1 1 0 0 1
*/

bool isValid(int x, int y, int mat[ROW][COLUMN]){
	return (
		x >= 0 && x < ROW &&
		y >= 0 && y < COLUMN &&
		mat[x][y]
	);
}

void dfs(int x, int y, int mat[ROW][COLUMN]){
	mat[x][y] = 0;
	
	for(int i=-1; i<=1; i++){
		for(int j=-1; j<=1; j++){
			if(isValid(x+i, y+j, mat)){
				dfs(x+i, y+j, mat);
			}
		}
	}
}

int countIslands(int mat[ROW][COLUMN]){
	int count = 0;
	
	for(int i=0; i<ROW; i++){
		for(int j=0; j<COLUMN; j++){
			if(mat[i][j]){
				count++;
				dfs(i, j, mat);
			}
		}
	}
	
	return count;
}

// main fucntion
int main(){
	int mat[ROW][COLUMN] = {
		{1, 0, 0, 0, 0},
		{0, 0, 1, 1, 0},
		{1, 1, 0, 0, 1},
		{1, 1, 0, 0, 0},
		{0, 1, 0, 0, 1},
		{0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0},
		{1, 1, 0, 0, 1},
		{1, 0, 0, 1, 1},
		{0, 0, 0, 0, 0},
		{1, 0, 1, 0, 1}
	};
	
	cout << countIslands(mat) << "\n";
	
	return 0;
}