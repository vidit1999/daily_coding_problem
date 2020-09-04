#include <bits/stdc++.h>
#define BOARD_SIZE 8
using namespace std;

/*
You are presented with an 8 by 8 matrix representing the positions of pieces on a chess board.
The only pieces on the board are the black king and various white pieces.
Given this matrix, determine whether the king is in check.

For details on how each piece moves, see here.

For example, given the following matrix:

...K....
........
.B......
......P.
.......R
..N.....
........
.....Q..

You should return True, since the bishop is attacking the king diagonally.
*/

// validity of a position in board
bool isValid(pair<int, int> pos){
	return pos.first >= 0 && pos.first < BOARD_SIZE && pos.second >= 0 && pos.second < BOARD_SIZE;
}


bool kingChecked(pair<int, int> king_pos, vector<string> board){

    // if king is not checked from left upper corner direction
	for(int i=king_pos.first-1, j=king_pos.second-1; i>=0 && j>=0; i--, j--){
		if(board[i][j] == 'B' || board[i][j] == 'Q')
			return true;
		else if(board[i][i] != '.')
			break;
	}
	
    // if king is checked from right lower corner direction
    for(int i=king_pos.first+1, j=king_pos.second+1; i < BOARD_SIZE && j < BOARD_SIZE; i++, j++){
        if(board[i][j] == 'B' || board[i][j] == 'Q')
			return true;
		else if(board[i][i] != '.')
			break;
    }

    // if king is checked from right upper corner direction
    for(int i=king_pos.first-1, j=king_pos.second+1; i >= 0 && j < BOARD_SIZE; i--, j++){
        if(board[i][j] == 'B' || board[i][j] == 'Q')
			return true;
		else if(board[i][i] != '.')
			break;
    }

    // if king is checked from left lower corner direction
    for(int i=king_pos.first+1, j=king_pos.second-1; i < BOARD_SIZE && j >= 0; i++, j--){
        if(board[i][j] == 'B' || board[i][j] == 'Q')
			return true;
		else if(board[i][i] != '.')
			break;
    }

    // if king is checked from north
    for(int i = king_pos.first-1; i >= 0; i--){
        if(board[i][king_pos.second] == 'Q' || board[i][king_pos.second] == 'R')
            return true;
        else if(board[i][king_pos.second] != '.')
            break;
    }

    // if king is checked from south
    for(int i = king_pos.first+1; i < BOARD_SIZE; i++){
        if(board[i][king_pos.second] == 'Q' || board[i][king_pos.second] == 'R')
            return true;
        else if(board[i][king_pos.second] != '.')
            break;
    }

    // if king is checked from left
    for(int j=king_pos.second-1; j >= 0; j--){
        if(board[king_pos.first][j] == 'Q' || board[king_pos.first][j] == 'R')
            return true;
        else if(board[king_pos.first][j] != '.')
            break;
    }

    // if king is checked from right
    for(int j=king_pos.second+1; j < BOARD_SIZE; j++){
        if(board[king_pos.first][j] == 'Q' || board[king_pos.first][j] == 'R')
            return true;
        else if(board[king_pos.first][j] != '.')
            break;
    }

    // if king is checked by knight
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    for(int i=0;i<8;i++){
        pair<int, int> knight_pos = {king_pos.first + dx[i], king_pos.second + dy[i]};
        if(isValid(knight_pos) && board[knight_pos.first][knight_pos.second] == 'K')
            return true;
    }

    // if king is checked by pawn
    for(int j : {1, -1}){
        pair<int, int> pawn_pos = {king_pos.first + 1, king_pos.second + j};
        if(isValid(pawn_pos) && board[pawn_pos.first][pawn_pos.second] == 'K')
            return true;
    }

	return false;
}

bool isKingChecked(vector<string> board){
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].length(); j++){
            if(board[i][j] == 'k'){
                if(kingChecked({i, j}, board))
                    return true;
                else
                    return false;
            }
        }
    }

    return false;
}

// main function
int main(){
    vector<string> board = {
        "...k....",
        "........",
        ".B......",
        "......P.",
        ".......R",
        "..N.....",
        "........",
        ".....Q.."
    };
    
    if(isKingChecked(board))
        cout << "Yes\n";
    else
        cout << "No\n";
	return 0;
}