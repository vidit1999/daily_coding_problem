#include <bits/stdc++.h>
#define N 3
using namespace std;

/*
Given an N by N matrix, rotate it by 90 degrees clockwise.

For example, given the following matrix:

[[1, 2, 3],
 [4, 5, 6],
 [7, 8, 9]]
you should return:

[[7, 4, 1],
 [8, 5, 2],
 [9, 6, 3]]
Follow-up: What if you couldn't use any extra space?
*/

void transpose(int mat[N][N]){
	for(int i=0; i<N; i++){
		for(int j=i; j<N; j++)
			swap(mat[i][j], mat[j][i]);
	}
}

void reverseRow(int mat[N][N]){
	for(int i=0; i<N; i++){
		int j=0, k=N-1;
		while(j <= k){
			swap(mat[i][j++], mat[i][k--]);
		}
	}
}

void rotateMaitrix(int mat[N][N]){
	transpose(mat);
	reverseRow(mat);
}

// main function
int main(){
	int mat[N][N] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	
	rotateMaitrix(mat);
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++)
			cout << mat[i][j] << " ";
		cout << "\n";
	}
	return 0;
}