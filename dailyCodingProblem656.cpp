#include <bits/stdc++.h>
using namespace std;

#define ROW 4
#define COL 3

/*
Given a 2-D matrix representing an image, a location of a pixel in the screen and a color C,
replace the color of the given pixel and all adjacent same colored pixels with C.

For example, given the following matrix, and location pixel of (2, 2), and 'G' for green:

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

bool isValid(int x, int y, char mat[ROW][COL], char old_color, char new_color){
	return (
		x >= 0 && x < ROW &&
		y >= 0 && y < COL &&
		mat[x][y] == old_color &&
		mat[x][y] != new_color
	);
}

void dfs(char mat[ROW][COL], int x, int y, char new_color, char old_color){
	mat[x][y] = new_color;
	
	int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
	
	for(int i=0; i<4; i++){
		if(isValid(x+dx[i], y+dy[i], mat, old_color, new_color))
			dfs(mat, x+dx[i], y+dy[i], new_color, old_color);
	}
}

void changeMatrix(char mat[ROW][COL], pair<int, int> location, char new_color){
	if(location.first < 0 || location.second < 0 || location.first > ROW || location.second > COL) return;
	
	char old_color = mat[location.first][location.second];
	dfs(mat, location.first, location.second, new_color, old_color);
	
	for(int i=0; i<ROW; i++){
		for(int j=0; j<COL; j++){
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}
}

// main function
int main(){
	char mat[ROW][COL] = {
		{'B', 'B', 'W'},
		{'W', 'W', 'W'},
		{'W', 'W', 'W'},
		{'B', 'B', 'B'},
	};
	pair<int, int> location = {2, 2};
	char new_color = 'G';
	changeMatrix(mat, location, new_color);
	return 0;
}