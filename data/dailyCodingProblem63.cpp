#include <bits/stdc++.h>
#define ROW 4
#define COLUMN 4
using namespace std;

/*
Given a 2D matrix of characters and a target word,
write a function that returns whether the word can
be found in the matrix by going left-to-right, or up-to-down.

For example, given the following matrix:

[['F', 'A', 'C', 'I'],
 ['O', 'B', 'Q', 'P'],
 ['A', 'N', 'O', 'B'],
 ['M', 'A', 'S', 'S']]

and the target word 'FOAM', you should return true,
since it's the leftmost column. Similarly, given the
target word 'MASS', you should return true,
since it's the last row.
*/

bool findLROrUD(int x, int y, string word, char mat[ROW][COLUMN]){
	bool find_left_right = true, find_up_down = true;
	
	// find left to right
	for(int i=0; i<word.length(); i++){
		if(y+i >= COLUMN || mat[x][y+i] != word[i]){
			find_left_right = false;
			break;
		}
	}
	
	// find up to down
	for(int i=0; i<word.length(); i++){
		if(x+i >= ROW || mat[x+i][y] != word[i]){
			find_up_down = false;
			break;
		}
	}
	
	return (find_left_right || find_up_down);
}

bool wordPresent(string word, char mat[ROW][COLUMN]){
	int word_len = word.length();
	
	if(word_len > ROW && word_len > COLUMN) return false;
	
	for(int i=0; i<ROW; i++){
		for(int j=0; j<ROW; j++){
			if(!word.empty() && mat[i][j] == word[0] && findLROrUD(i, j, word, mat))
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
	
	cout << wordPresent("FOAM", mat) << "\n";
	cout << wordPresent("MASS", mat) << "\n";
	cout << wordPresent("ANBA", mat) << "\n";
	cout << wordPresent("ANOB", mat) << "\n";
	
	return 0;
}