#include <bits/stdc++.h>
#define N 5
using namespace std;

/*
A knight's tour is a sequence of moves by a knight
on a chessboard such that all squares are visited once.

Given N, write a function to return the number
of knight's tours on an N by N chessboard.
*/

bool isValid(int x, int y, int board[N][N]){
	return (
		x >= 0 and x < N and
		y >= 0 and y < N and
		not board[x][y]
	);
}


int countMoves(int x, int y, int move_count, int dx[], int dy[], int board[N][N]){
	if(move_count == N*N) return 1;
	
	int count = 0;
	for(int i=0; i<8; i++){
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		
		if(isValid(next_x, next_y, board)){
			board[next_x][next_y] = 1;
			count += countMoves(next_x, next_y, move_count+1, dx, dy, board);
			board[next_x][next_y] = 0;
		}
	}
	
	return count;
}

int knightTour(){
	int board[N][N] = {0};
	int count = 0;
	int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
	int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			count += countMoves(i, j, 0, dx, dy, board);
		}
	}
	
	return count;
}

// main function
int main(){
	cout << knightTour() << "\n";
	return 0;
}