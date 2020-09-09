#include <bits/stdc++.h>
using namespace std;

#define N 5
#define M 6

/*
Let A be an N by M matrix in which every row and every column is sorted.

Given i1, j1, i2, and j2, compute the number of elements of M smaller
than M[i1, j1] and larger than M[i2, j2].

For example, given the following matrix:

[[1, 3, 7, 10, 15, 20],
 [2, 6, 9, 14, 22, 25],
 [3, 8, 10, 15, 25, 30],
 [10, 11, 12, 23, 30, 35],
 [20, 25, 30, 35, 40, 45]]

And i1 = 1, j1 = 1, i2 = 3, j2 = 3, return 15 as there are 15 numbers
in the matrix smaller than 6 or greater than 23.
*/

int countSmallerGreater(int matrix[N][M], int i1, int j1, int i2, int j2){
	int count = 0;
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if((matrix[i][j] < matrix[i1][j1]) || (matrix[i][j] > matrix[i2][j2]))
				count++;
		}
	}
	
	return count;
}

// main function
int main(){
	int matrix[N][M] = {
		{1, 3, 7, 10, 15, 20},
		{2, 6, 9, 14, 22, 25},
		{3, 8, 10, 15, 25, 30},
		{10, 11, 12, 23, 30, 35},
		{20, 25, 30, 35, 40, 45}
	};
	
	int i1 = 1, j1 = 1, i2 = 3, j2 = 3;
	
	cout << countSmallerGreater(matrix, i1, j1, i2, j2) << "\n";
	
	return 0;
}