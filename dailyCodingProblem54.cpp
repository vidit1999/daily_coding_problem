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

bool isRowSafe(int grid[N][N], int row, int num){
	for(int col=0; col<N; col++){
		if(grid[row][col] == num)
			return false;
	}
	return true;
}

bool isColumnSafe(int grid[N][N], int col, int num){
	for(int row=0; row<N; row++){
		if(grid[row][col] == num)
			return false;
	}
	return true;
}

bool isBoxSafe(int grid[N][N], int box_start_row, int box_start_col, int num){
	for(int row=0; row<3; row++){
		for(int col=0; col<3; col++){
			if(grid[row+box_start_row][col+box_start_col] == num)
				return false;
		}
	}
	return true;
}

bool isSafe(int grid[N][N], int row, int col, int num){
	return (
		isRowSafe(grid, row, num) &&
		isColumnSafe(grid, col, num) &&
		isBoxSafe(grid, row - row%3, col - col%3, num) &&
		grid[row][col] == BLANK
	);
}

bool blankPoint(int grid[N][N], int& row, int& col){
	for(row=0; row<N; row++){
		for(col=0; col<N; col++){
			if(grid[row][col] == BLANK)
				return true;
		}
	}
	return false;
}

bool SudokuSolver(int grid[N][N]){
	int row, col;
	
	if(!blankPoint(grid, row, col)) return true;
	
	for(int num=1; num<=9; num++){
		if(isSafe(grid, row, col, num)){
			grid[row][col] = num;
			if(SudokuSolver(grid))
				return true;
			grid[row][col] = BLANK;
		}
	}
	
	return false;
}

void printGrid(int grid[N][N]){
	for(int row=0; row<9; row++){
		for(int col=0; col<9; col++){
			cout << grid[row][col] << " ";
		}
		cout << "\n";
	}
}

// main function
int main(){
	int grid[N][N] = {
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
	
	SudokuSolver(grid);
	
	printGrid(grid);
	
	return 0;
}