#include <bits/stdc++.h>
using namespace std;

#define ROW 7
#define COL 6
#define WIN_NUM 4

/*
Connect 4 is a game where opponents take turns dropping
red or black discs into a 7 x 6 vertically suspended grid.
The game ends either when one player creates a line of four
consecutive discs of their color (horizontally, vertically,
or diagonally), or when there are no more spots left in the grid.

Design and implement Connect 4.
*/

void printBoard(vector<vector<char>>& board){
	for(int i=ROW-1; i>=0; i--){
		for(int j=COL-1; j>=0; j--){
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

bool checkWin(vector<vector<char>>& board, int x, int y){
	char c = board[x][y];
	int count = 0;
	
	// check vertical direction
	for(int i=x; i>=0; i--){
		if(board[i][y] == c){
			if(++count == WIN_NUM){
				return true;
			}
		}
		else{
			break;
		}
	}
	
	count = 0;
	int left_count = 0, right_count = 0;
	
	// check horizontal left
	for(int i=y; i>=0; i--){
		if(board[x][i] == c){
			left_count++;
			if(++count == WIN_NUM){
				return true;
			}
		}
		else{
			break;
		}
	}
	
	count = 0;
	
	// check horizontal right
	for(int i=y; i<COL; i++){
		if(board[x][i] == c){
			right_count++;
			if(++count == WIN_NUM){
				return true;
			}
		}
		else{
			break;
		}
	}
	
	count = 0;
	
	if(left_count + right_count - 1 == WIN_NUM) return true;
	
	// check left diagonal
	for(int i=x, j=y; i>=0 && j>=0; i--, j--){
		if(board[i][j] == c){
			if(++count == WIN_NUM){
				return true;
			}
		}
		else{
			break;
		}
	}
	
	count = 0;
	
	// check right diagonal
	for(int i=x, j=y; i<ROW && j<COL; i++, j++){
		if(board[i][j] == c){
			if(++count == WIN_NUM){
				return true;
			}
		}
		else{
			break;
		}
	}
	
	return false;
}

void connect4(){
	vector<vector<char>> board(
		ROW,
		vector<char>(COL, '.')
	);
	
	vector<int> row_min(COL, 0);
	int player = 0;
	
	while(true){
		bool all_finished = true;
		
		for(int i : row_min){
			if(i < ROW){
				all_finished = false;
				break;
			}
		}
		
		if(all_finished)
			break;
		
		int x, y;
		do{
			y = rand()%COL;
			x = row_min[y];
		}while(x >= ROW);
		
		row_min[y]++;
		
		cout << "Turn : " << player << "\n";
		cout << "**********\n";
		
		board[x][y] = char(player + '0');
		player = 1 - player;
		
		printBoard(board);
		
		if(checkWin(board, x, y)){
			cout << "Winner : " << (1-player) << "\n";
			break;
		}
	}
}

// main function
int main(){
	srand(time(0));
	
	connect4();
	
	return 0;
}