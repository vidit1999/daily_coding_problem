#include <bits/stdc++.h>
using namespace std;

#define ROW 4
#define COL 5

/*
In linear algebra, a Toeplitz matrix is one in which the elements
on any given diagonal from top left to bottom right are identical.

Here is an example:

1 2 3 4 8
5 1 2 3 4
4 5 1 2 3
7 4 5 1 2

Write a program to determine whether a given input is a Toeplitz matrix.
*/

bool isToeplitz(int mat[ROW][COL]){
	for(int i=0; i<ROW; i++){
		int j = 0, k = i, check = mat[i][j];
		
		while(k < ROW && j < COL){
			if(mat[k++][j++] != check)
				return false;
		}
	}
	
	for(int j=0; j<COL; j++){
		int i = 0, k = j, check = mat[i][j];
		
		while(i < ROW && k < COL){
			if(mat[i++][k++] != check)
				return false;
		}
	}
	
	return true;
}

// main function
int main(){
	int mat[ROW][COL] = {
		{1, 2, 3, 4, 8},
		{5, 1, 2, 3, 4},
		{4, 5, 1, 2, 3},
		{7, 4, 5, 1, 2},
	};
	
	cout << isToeplitz(mat) << "\n";
	
	return 0;
}