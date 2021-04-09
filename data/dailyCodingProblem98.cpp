#include <bits/stdc++.h>
#define ROW 3
#define COLUMN 4
using namespace std;

/*
Given a 2D board of characters and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell,
where "adjacent" cells are those horizontally or vertically neighboring.
The same letter cell may not be used more than once.

For example, given the following board:

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

exists(board, "ABCCED") returns true, exists(board, "SEE")
returns true, exists(board, "ABCB") returns false.
*/

bool isExists(
	char board[ROW][COLUMN], string& word,
	int& len, int pos_x, int pos_y, int pos
){
	if(pos == len) return true;
	
	if(pos_x < 0 || pos_y < 0 || pos_x >= ROW || pos_y >= COLUMN) return false;
	
	if(board[pos_x][pos_y] == word[pos]){
		char temp = board[pos_x][pos_y];
		board[pos_x][pos_y] = '$';
		
		bool res = (
			isExists(board, word, len, pos_x+1, pos_y, pos+1) ||
			isExists(board, word, len, pos_x-1, pos_y, pos+1) ||
			isExists(board, word, len, pos_x, pos_y+1, pos+1) ||
			isExists(board, word, len, pos_x, pos_y-1, pos+1)
		);
		
		board[pos_x][pos_y] = temp;
		return res;
	}
	
	return false;
}

bool exists(char board[ROW][COLUMN], string& word){
	int len = word.length();
	
	for(int i=0; i<ROW; i++){
		for(int j=0; j<COLUMN; j++){
			if(
				board[i][j] == word[0] &&
				isExists(board, word, len, i, j, 0)
			){
				return true;
			}
		}
	}
	
	return false;
}

void testFunc(char board[ROW][COLUMN], vector<string> v){
	for(string s : v){
		if(exists(board, s))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// main function
int main(){
	char board[ROW][COLUMN] = {
		{'A','B','C','E'},
		{'S','F','C','S'},
		{'A','D','E','E'}
	};
	
	testFunc(board, {
		"SEE", "ABCCED", "ABCB"
	});
	return 0;
}