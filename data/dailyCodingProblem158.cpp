#include <bits/stdc++.h>
#define N 3
#define M 3
using namespace std;

/*
You are given an N by M matrix of 0s and 1s. Starting from the top left corner,
how many ways are there to reach the bottom right corner?

You can only move right and down. 0 represents an empty space
while 1 represents a wall you cannot walk through.

For example, given the following matrix:

[[0, 0, 1],
 [0, 0, 1],
 [1, 0, 0]]
Return two, as there are only two ways to get to the bottom right:

Right, down, down, right
Down, right, down, right

The top left corner and bottom right corner will always be 0.
*/

bool isValid(int i, int j, int mat[N][M]){
	return (
		i >= 0 && i < N &&
		j >= 0 && j < N &&
		!mat[i][j]
	);
}

void wayCountHelper(int i, int j, int& count, int mat[N][M]){
	if(!isValid(i, j, mat)) return;
	
	if(i == N-1 && j == M-1){
		count++;
		return;
	}
	
	mat[i][j] = 1;
	
	if(isValid(i, j+1, mat)) wayCountHelper(i, j+1, count, mat);
	if(isValid(i+1, j, mat)) wayCountHelper(i+1, j, count, mat);
	
	mat[i][j] = 0;
}

int wayCount(int mat[N][M]){
	int count = 0;
	wayCountHelper(0, 0, count, mat);
    return count;
}

// main function
int main(){
	int mat[N][M] = {
		{0, 0, 1},
		{0, 0, 1},
		{1, 0, 0}
	};
	cout << wayCount(mat) << "\n";
	return 0;
}