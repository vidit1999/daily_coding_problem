#include <bits/stdc++.h>
#define ROW 3
#define COL 4
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

exists(board, "ABCCED") returns true,
exists(board, "SEE") returns true,
exists(board, "ABCB") returns false.
*/

bool isValid(int i, int j, char board[ROW][COL]){
	return (
		(i >= 0 && i < ROW) && // check for valid row index
		(j >= 0 && j < COL) && // check for valid column index
		(board[i][j] != '0') // check if already not visited
	);
}

bool existsHelper(char board[ROW][COL], int i, int j, string& word, int index){
	if(index == word.length()) return true;
	
	if(board[i][j] != word[index]) return false;
	
	char prev = board[i][j];
	board[i][j] = '0';
	
	if(isValid(i, j-1, board) && existsHelper(board, i, j-1, word, index+1))
		return true;
	else if(isValid(i, j+1, board) && existsHelper(board, i, j+1, word, index+1))
		return true;
	else if(isValid(i-1, j, board) && existsHelper(board, i-1, j, word, index+1))
		return true;
	else if(isValid(i+1, j, board) && existsHelper(board, i+1, j, word, index+1))
		return true;
	board[i][j] = prev;
	
	return false;
}

bool exists(char board[ROW][COL], string word){
	return existsHelper(board, 0, 0, word, 0);
}
// main function
int main(){
	char board[ROW][COL] = {
		{'A','B','C','E'},
		{'S','F','C','S'},
		{'A','D','E','E'}
	};
	
	if(exists(board, "ABCCED"))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}