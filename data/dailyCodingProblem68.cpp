#include <bits/stdc++.h>
using namespace std;

/*
On our special chessboard, two bishops attack each other if
they share the same diagonal. This includes bishops that
have another bishop located between them, i.e. bishops
can attack through pieces.

You are given N bishops, represented as (row, column)
tuples on a M by M chessboard. Write a function to count
the number of pairs of bishops that attack each other.
The ordering of the pair doesn't matter:
(1, 2) is considered the same as (2, 1).

For example, given M = 5 and the list of bishops:

(0, 0)
(1, 2)
(2, 2)
(4, 0)

The board would look like this:

[b 0 0 0 0]
[0 0 b 0 0]
[0 0 b 0 0]
[0 0 0 0 0]
[b 0 0 0 0]

You should return 2, since bishops 1 and 3
attack each other, as well as bishops 3 and 4.
*/

int countBishopDiagonal(vector<vector<char>>& mat, int x, int y){
	int count = 0;

	// top left corner
	for(int i=x-1, j=y-1; i>=0 && j>=0; i--, j--){
		if(mat[i][j] == 'b')
			count++;
	}

	// bottom left corner
	for(int i=x+1, j=y-1; i<mat.size() && j>=0; i++, j--){
		if(mat[i][j] == 'b')
			count++;
	}

	// top right corner
	for(int i=x-1, j=y+1; i>=0 && j<mat[0].size(); i--, j++){
		if(mat[i][j] == 'b')
			count++;
	}

	// bottom right corner
	for(int i=x+1, j=y+1; i<mat.size() && j<mat[0].size(); i++, j++){
		if(mat[i][j] == 'b')
			count++;
	}

	return count;
}

int countBishopAttacking(vector<vector<char>>& mat){
	int count = 0;

	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<mat[0].size(); j++){
			if(mat[i][j] == 'b'){
				count += countBishopDiagonal(mat, i, j);
			}
		}
	}

	return count/2;
}

int countBishop(int M, vector<pair<int, int>> arr){
	vector<vector<char>> mat(M, vector<char>(M, '0'));

	for(auto p : arr){
		mat[p.first][p.second] = 'b';
	}

	for(int i=0; i<M; i++){
		for(int j=0; j<M; j++){
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}

	return countBishopAttacking(mat);
}

// main function
int main(){
	cout << countBishop(
		5,
		{
			{0, 0},
			{1, 2},
			{2, 2},
			{4, 0},
		}
	) << "\n";
	return 0;
}