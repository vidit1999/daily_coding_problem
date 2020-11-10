#include <bits/stdc++.h>
using namespace std;

#define M 4
#define N 5

/*
In linear algebra, a Toeplitz matrix is one in which the elements on
any given diagonal from top left to bottom right are identical.

Here is an example:

1 2 3 4 8
5 1 2 3 4
4 5 1 2 3
7 4 5 1 2

Write a program to determine whether a
given input is a Toeplitz matrix.
*/

bool checkDiagonal(int mat[M][N], int x, int y){
	for(int i=x, j=y; i<M && j<N; i++, j++){
		if(mat[i][j] != mat[x][y]){
			return false;
		}
	}
	return true;
}

bool checkToeplitz(int mat[M][N]){
	for(int j=0; j<N; j++){
		if(!checkDiagonal(mat, 0, j))
			return false;
	}
	
	for(int i=0; i<M; i++){
		if(!checkDiagonal(mat, i, 0))
			return false;
	}
	
	return true;
}

// main function
int main(){
	int mat[M][N] = {
		{1, 2, 3, 4, 8},
		{5, 1, 2, 3, 4},
		{4, 5, 1, 2, 3},
		{7, 4, 5, 1, 2},
	};
	
	cout << checkToeplitz(mat) << "\n";
	
	return 0;
}