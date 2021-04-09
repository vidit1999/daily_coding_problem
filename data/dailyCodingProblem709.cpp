#include <bits/stdc++.h>
using namespace std;

#define N 3
#define M 3
/*
You are given an N by M matrix of 0s and 1s.
Starting from the top left corner, how many
ways are there to reach the bottom right corner?

You can only move right and down. 0 represents
an empty space while 1 represents a wall you
cannot walk through.

For example, given the following matrix:

[[0, 0, 1],
 [0, 0, 1],
 [1, 0, 0]]

Return two, as there are only two ways
to get to the bottom right:

Right, down, down, right
Down, right, down, right

The top left corner and bottom right
corner will always be 0.
*/

int countPathsHelper(int mat[M][N], int i, int j, int count[M][N]){
	if(i == M-1 && j == N-1){
		return 1;
	}
	
	if(count[i][j] != -1){
		return count[i][j];
	}
	
	int ans = 0;
	
	if(i+1 < M && mat[i+1][j] == 0){
		ans += countPathsHelper(mat, i+1, j, count);
	}
	
	if(j+1 < N && mat[i][j+1] == 0){
		ans += countPathsHelper(mat, i, j+1, count);
	}
	
	count[i][j] = ans;
	
	return ans;
}

int countPaths(int mat[M][N]){
	int count[M][N];
	memset(count, -1, sizeof(count));
	return countPathsHelper(mat, 0, 0, count);
}

// main function
int main(){
	int mat[M][N] = {
		{0, 0, 1},
		{0, 0, 1},
		{1, 0, 0}
	};
	
	cout << countPaths(mat) << "\n";
	
	return 0;
}