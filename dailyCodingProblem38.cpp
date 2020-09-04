#include <bits/stdc++.h>
using namespace std;

#define N 8

/*
You have an N by N board. Write a function that, given N,
returns the number of possible arrangements of the board
where N queens can be placed on the board without
threatening each other, i.e. no two queens share
the same row, column, or diagonal.
*/

bool isSafe(int board[N][N], int row, int col){
    for(int i=0; i<col; i++){
        if(board[row][i])
            return false;
    }

    for(int i=row, j=col; i>=0 && j >=0; i--, j--){
        if(board[i][j])
            return false;
    }

    for(int i=row, j=col; i<N && j>=0; i++, j--){
        if(board[i][j])
            return false;
    }

    return true;
}

void nQueenHelper(int col, int& count, int board[N][N]){
    if(col >= N){
        count++;
        return;
    }

    for(int i=0; i<N; i++){
        if(isSafe(board, i, col)){
            board[i][col] = 1;
            nQueenHelper(col+1, count, board);
            board[i][col] = 0;
        }
    }
}

int nQueen(int board[N][N]){
    int count = 0;
    nQueenHelper(0, count, board);
    return count;
}

// main function
int main(){
    int board[N][N];
    memset(board, 0, sizeof(board));
    cout << nQueen(board) << "\n";
	return 0;
}