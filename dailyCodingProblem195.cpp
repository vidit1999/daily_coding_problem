#include <bits/stdc++.h>
#define ROW 5
#define COLUMN 6
using namespace std;

/*
Given i1, j1, i2, and j2, compute the number of elements of M
smaller than M[i1, j1] and larger than M[i2, j2].

For example, given the following matrix:

[[1, 3, 7, 10, 15, 20],
 [2, 6, 9, 14, 22, 25],
 [3, 8, 10, 15, 25, 30],
 [10, 11, 12, 23, 30, 35],
 [20, 25, 30, 35, 40, 45]]

And i1 = 1, j1 = 1, i2 = 3, j2 = 3, return 15 as there are 15
numbers in the matrix smaller than 6 or greater than 23.
*/

int countNumber(int mat[ROW][COLUMN], int i1, int j1, int i2, int j2){
	int num1 = max(mat[i1][j1], mat[i2][j2]), num2 = min(mat[i1][j1], mat[i2][j2]);
	int count = 0;
	
	for(int i=0; i<ROW; i++){
		for(int j=0; j<COLUMN; j++){
			if(mat[i][j] < num1 && mat[i][j] > num2)
				count++;
		}
	}
	
	return count;
}

// main funtion
int main(){
	int mat[ROW][COLUMN] = {
		{1, 3, 7, 10, 15, 20},
		{2, 6, 9, 14, 22, 25},
		{3, 8, 10, 15, 25, 30},
		{10, 11, 12, 23, 30, 35},
		{20, 25, 30, 35, 40, 45}
	};
	
	cout << countNumber(mat, 1, 1, 3, 3) << "\n";
	return 0;
}