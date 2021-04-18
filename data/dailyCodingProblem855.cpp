#include <iostream>
#include <vector>
using namespace std;

#define N 8
#define QUEEN 1
#define BLANK 0

/*
You have an N by N board. Write a function that, given N,
returns the number of possible arrangements of the board where
N queens can be placed on the board without threatening each other,
i.e. no two queens share the same row, column, or diagonal.
*/

bool checkCol(vector<vector<int>>& board, int row, int col){
    for(int i=row-1; i>=0; i--){
        if(board[i][col] == QUEEN){
            return false;
        }
    }
    return true;
}

bool checkUpperDiags(vector<vector<int>>& board, int row, int col){
    // check queen present in left upper diagonal
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
        if(board[i][j] == QUEEN){
            return false;
        }
    }

    // check queen present in right upper diagonal
    for(int i=row-1, j=col+1; i>=0 && j<N; i--, j++){
        if(board[i][j] == QUEEN){
            return false;
        }
    }

    return true;
}

bool checkPlaceSafe(vector<vector<int>>& board, int row, int col){
    return checkCol(board, row, col) && checkUpperDiags(board, row, col);
}

bool placeQueens(vector<vector<int>>& board, int row=0){
    // queens are placed in all rows return true
    if(row == N) return true;

    for(int col=0; col<N; col++){
        if(board[row][col] == BLANK && checkPlaceSafe(board, row, col)){

            // place queen
            // if works then return true
            // else backtrack
            board[row][col] = QUEEN;

            if(placeQueens(board, row+1)){
                return true;
            }

            board[row][col] = BLANK;
        }
    }

    return false;
}


// main function
int main(){
    vector<vector<int>> board(N, vector<int>(N, BLANK));
    
    if(!placeQueens(board)){
        cout << "No safe formation possible\n";
    } else {
        cout << "Safe Formation:\n";
        for(auto& v : board){
            for(int i : v){
                cout << i << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}