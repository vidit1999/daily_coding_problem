#include <bits/stdc++.h>
#define ROW 4
#define COLUMN 3
using namespace std;

/*
Given a 2-D matrix representing an image, a location of a pixel in the screen and a color C,
replace the color of the given pixel and all adjacent same colored pixels with C.

For example, given the following matrix, and location pixel of (2, 2),
and 'G' for green:

B B W
W W W
W W W
B B B

Becomes

B B G
G G G
G G G
B B B
*/

bool isValid(int i, int j, int prev_colour, int new_colour, char mat[ROW][COLUMN]){
	return (
		i >= 0 && i < ROW &&
		j >= 0 && j < COLUMN &&
		mat[i][j] == prev_colour &&
		mat[i][j] != new_colour
	);
}

void dfs(int x, int y, int prev_colour, int new_colour, char mat[ROW][COLUMN]){
	mat[x][y] = new_colour;
	
	for(int i=-1; i<=1; i++){
		for(int j=-1; j<=1; j++){
			if(!(i == 0 && j == 0) && isValid(x+i, y+j, prev_colour, new_colour, mat)){
				dfs(x+i, y+j, prev_colour, new_colour, mat);
			}
		}
	}
}

void matrixColour(int i, int j, int new_colour, char mat[ROW][COLUMN]){
	int prev_colour = mat[i][j];
	dfs(i, j, prev_colour, new_colour, mat);
}

void showMatrix(char mat[ROW][COLUMN]){
	for(int i=0; i<ROW; i++){
		for(int j=0; j<COLUMN; j++)
			cout << mat[i][j] << " ";
		cout << "\n";
	}
}

// main function
int main(){
	char mat[ROW][COLUMN] = {
		{'B', 'B', 'W'},
		{'W', 'W', 'W'},
		{'W', 'W', 'W'},
		{'B', 'B', 'B'}
	};
	
	showMatrix(mat);
	matrixColour(2, 2, 'G', mat);
    cout << "\n\n";
	showMatrix(mat);
	
	return 0;
}