#include <bits/stdc++.h>
#define ROW 3
#define COLUMN 4
using namespace std;

/*
You are given a 2-d matrix where each cell represents number of coins in that cell.
Assuming we start at matrix[0][0], and can only move right or down,
find the maximum number of coins you can collect by the bottom right corner.

For example, in this matrix

0 3 1 1
2 0 0 4
1 5 3 1

The most we can collect is
0 + 2 + 1 + 5 + 3 + 1 = 12 coins.
*/

int maxCoins(int mat[ROW][COLUMN]){
	for(int i=1; i<COLUMN; i++) mat[0][i] += mat[0][i-1];
	for(int i=1; i<ROW; i++) mat[i][0] += mat[i-1][0];
	
	for(int i=1; i<ROW; i++){
		for(int j=1; j<COLUMN; j++){
			mat[i][j] = mat[i][j] + max(mat[i-1][j], mat[i][j-1]);
		}
	}
	
	return mat[ROW-1][COLUMN-1];
}

// main function
int main(){
	int mat[ROW][COLUMN] = {
		{0, 3, 1, 1},
		{2, 0, 0, 4},
		{1, 5, 3, 1}
	};
	
	cout << maxCoins(mat) << "\n";
	return 0;
}