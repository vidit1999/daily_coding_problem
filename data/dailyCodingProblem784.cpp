#include <bits/stdc++.h>
using namespace std;

#define ROW 4
#define COLUMN 4

/*
Given a 2D matrix of characters and a target word, write a function that returns whether
the word can be found in the matrix by going left-to-right, or up-to-down.

For example, given the following matrix:

[['F', 'A', 'C', 'I'],
 ['O', 'B', 'Q', 'P'],
 ['A', 'N', 'O', 'B'],
 ['M', 'A', 'S', 'S']]

and the target word 'FOAM', you should return true, since it's the leftmost column.
Similarly, given the target word 'MASS', you should return true, since it's the last row.
*/

bool checkWord(char mat[ROW][COLUMN], int x, int y, string word){
	bool left_right_check = true, up_down_check = true;
	
	// check for left to right
	for(int i=0; i<word.length(); i++){
		if((y+i >= COLUMN) || (mat[x][y+i] != word[i])){
			left_right_check = false;
			break;
		}
	}
	
	// check for up to down
	for(int i=0; i<word.length(); i++){
		if((x+i >= ROW) || (mat[x+i][y] != word[i])){
			up_down_check = false;
			break;
		}
	}
	
	return (left_right_check || up_down_check);
}

bool matrixFound(char mat[ROW][COLUMN], string word){
	if(word.empty() || (word.length() > ROW && word.length() > COLUMN)) return false;
	
	for(int i=0; i<ROW; i++){
		for(int j=0; j<COLUMN; j++){
			if(mat[i][j] == word[0] && checkWord(mat, i, j, word))
				return true;
		}
	}
	
	return false;
}

// main function
int main(){
	char mat[ROW][COLUMN] = {
		{'F', 'A', 'C', 'I'},
		{'O', 'B', 'Q', 'P'},
		{'A', 'N', 'O', 'B'},
		{'M', 'A', 'S', 'S'},
	};
	
	cout << boolalpha << matrixFound(mat, "FOAM") << "\n";
	cout << matrixFound(mat, "MASS") << "\n";
	
	return 0;
}