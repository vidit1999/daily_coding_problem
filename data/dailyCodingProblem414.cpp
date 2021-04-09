#include <bits/stdc++.h>
#define N 4
using namespace std;

/*
You have an N by N board. Write a function that, given N, returns the number of possible arrangements
of the board where N queens can be placed on the board without threatening each other,
i.e. no two queens share the same row, column, or diagonal.
*/

bool isSafeToPlace(int x, int y, int board[N][N]){
	// check this column on the upper side
	for(int i=0; i<x; i++)
		if(board[i][y])
			return false;
	// check for right diagonal
	for(int i=x, j=y; i>=0 & j<N; i--, j++)
		if(board[i][j])
			return false;
	
	for(int i=x, j=y; i>=0 & j>=0; i--, j--)
		if(board[i][j])
			return false;
	return true;
}

bool queensPositions(int board[N][N], int row){
	if(row >= N) return true;
	
	for(int i=0;i<N;i++){
		if(isSafeToPlace(row, i, board)){
			board[row][i] = 1;
			if(queensPositions(board, row+1)) return true;
			board[row][i] = 0;
		}
	}
	
	return false;
}

// main function
int main(){
	int board[N][N] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};
	
	if(!queensPositions(board, 0))
		cout << "No solution exists\n";
	else{
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++)
				cout << board[i][j] << " ";
			cout << "\n";
		}
	}
	return 0;
}