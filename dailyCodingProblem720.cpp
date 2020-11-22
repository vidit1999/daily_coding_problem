#include <bits/stdc++.h>
using namespace std;

#define N 9
#define BLANK 0

/*
Sudoku is a puzzle where you're given a partially-filled 9 by 9 grid with digits.
The objective is to fill the grid with the constraint that every row, column,
and box (3 by 3 subgrid) must contain all of the digits from 1 to 9.

Implement an efficient sudoku solver.
*/

bool isSafe(int board[N][N], int row, int col, int num){
	// check if row is safe
	for(int i=0; i<N; i++){
		if(board[row][i] == num){
			return false;
		}
	}

	// check if column is safe
	for(int i=0; i<N; i++){
		if(board[i][col] == num){
			return false;
		}
	}

	// check if small matrix is safe or not
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(board[i + row - row%3][j + col - col%3] == num){
				return false;
			}
		}
	}

	return true;
}

bool sudokuSolveHelper(int board[N][N], int row, int col){
	if(row == N-1 && col == N){
		return true;
	}

	if(col == N){
		col = 0;
		row++;
	}

	if(board[row][col] != BLANK){
		return sudokuSolveHelper(board, row, col+1);
	}

	for(int i=1; i<=9; i++){
		if(isSafe(board, row, col, i)){
			board[row][col] = i;
			if(sudokuSolveHelper(board, row, col+1)){
				return true;
			}
			board[row][col] = BLANK;
		}
	}

	return false;
}

void sudokuSolve(int board[N][N]){
	if(!sudokuSolveHelper(board, 0, 0)){
		cout << "No solution exists.";
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

// main function
int main(){
	int board1[N][N] = {
		{3, 0, 6, 5, 0, 8, 4, 0, 0},
		{5, 2, 0, 0, 0, 0, 0, 0, 0},
		{0, 8, 7, 0, 0, 0, 0, 3, 1},
		{0, 0, 3, 0, 1, 0, 0, 8, 0},
		{9, 0, 0, 8, 6, 3, 0, 0, 5},
		{0, 5, 0, 0, 9, 0, 6, 0, 0},
		{1, 3, 0, 0, 0, 0, 2, 5, 0},
		{0, 0, 0, 0, 0, 0, 0, 7, 4},
		{0, 0, 5, 2, 0, 6, 3, 0, 0}
	};

	sudokuSolve(board1); cout << "\n";

	int board2[N][N] = {
		{3, 1, 6, 5, 7, 8, 4, 9, 2},
		{5, 2, 9, 1, 3, 4, 7, 6, 8},
		{4, 8, 7, 6, 2, 9, 5, 3, 1},
		{2, 6, 3, 0, 1, 5, 9, 8, 7},
		{9, 7, 4, 8, 6, 0, 1, 2, 5},
		{8, 5, 1, 7, 9, 2, 6, 4, 3},
		{1, 3, 8, 0, 4, 7, 2, 0, 6},
		{6, 9, 2, 3, 5, 1, 8, 7, 4},
		{7, 4, 5, 0, 8, 6, 3, 1, 0}
	};

	sudokuSolve(board2); cout << "\n";

	return 0;
}