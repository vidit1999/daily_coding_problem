#include <bits/stdc++.h>
#define M 6
#define N 5
using namespace std;

/*
Given a matrix of 1s and 0s, return the number of "islands" in the matrix.
A 1 represents land and 0 represents water, so an island is a group of
1s that are neighboring whose perimeter is surrounded by water.

For example, this matrix has 4 islands.

1 0 0 0 0
0 0 1 1 0
0 1 1 0 0
0 0 0 0 0
1 1 0 0 1
1 1 0 0 1
*/

bool isValid(int i, int j){
	return (
		i >= 0 &&
		i < M &&
		j >= 0 &&
		j < N
	);
}

void dfsUtil(int row, int col, int mat[M][N]){
	mat[row][col] = 0;
	
	for(int i=-1; i<=1; i++){
		for(int j=-1; j<=1; j++){
			if(isValid(row+i, col+j) && mat[row+i][col+j] == 1)
				dfsUtil(row+i, col+j, mat);
		}
	}
}


int numberIslands(int mat[M][N]){
	int island_count = 0;
	
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if(mat[i][j] == 1){
				cout << i << ", " << j << "\n";
				island_count++;
				dfsUtil(i, j, mat);
			}
		}
	}
	
	return island_count;
}

// main function
int main(){
	int mat[M][N] = {
		{1, 0, 0, 0, 0},
		{0, 0, 1, 1, 0},
		{0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0},
		{1, 1, 0, 0, 1},
		{1, 1, 0, 0, 1}
	};
	
	cout << numberIslands(mat) << "\n";
	return 0;
}