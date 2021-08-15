#include <bits/stdc++.h>
#define N 3
using namespace std;

/*
A knight's tour is a sequence of moves by a knight on a
chessboard such that all squares are visited once.

Given N, write a function to return the number
of knight's tours on an N by N chessboard.
*/

bool isValid(int pos_x, int pos_y, int board[N][N]){
	return (pos_x >= 0 && pos_x < N && pos_y >= 0 && pos_y < N && !board[pos_x][pos_y]);
}

vector<pair<int, int>> validMoves(int pos_x, int pos_y, int board[N][N]){
	int dx[] = {-1, 1, 2, 2, 1, -1, -2, -2};
	int dy[] = {2, 2, 1, -1, -2, -2, -1, 1};
	vector<pair<int, int>> moves;
	
	for(int i=0; i<8; i++){
		if(isValid(pos_x+dx[i], pos_y+dy[i], board))
			moves.push_back({pos_x+dx[i], pos_y+dy[i]});
	}
	
	return moves;
}

int knightTourUtil(int board[N][N], queue<pair<int, int>>& q){
	if(q.size() == N*N)
		return 1;
	else{
		int count = 0;
		auto last_pos = q.front();
		for(auto it : validMoves(last_pos.first, last_pos.second, board)){
			q.push({it.first, it.second});
			board[it.first][it.second] = true;
			count += knightTourUtil(board, q);
			q.pop();
			board[it.first][it.second] = false;
		}
		return count;
	}
}

int knightTour(){
	
	int count = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int board[N][N];
			for(int i=0; i<N; i++){
				for(int j=0; j<N; j++){
					board[i][j] = false;
				}
			}
            queue<pair<int,int>> q({{i, j}});
			count += knightTourUtil(board, q);
		}
	}
	
	return count;
}

// main function
int main(){
    cout << knightTour() << "\n";
	return 0;
}