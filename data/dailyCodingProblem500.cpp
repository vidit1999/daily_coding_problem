#include <bits/stdc++.h>
#define M 4
#define N 4
using namespace std;

/*
You are given an M by N matrix consisting of booleans that represents a board.
Each True boolean represents a wall. Each False boolean represents a tile you can walk on.

Given this matrix, a start coordinate, and an end coordinate,
return the minimum number of steps required to reach the end coordinate from the start.
If there is no possible path, then return null. You can move up, left, down, and right.
You cannot move through walls. You cannot wrap around the edges of the board.

For example, given the following board:

[[f, f, f, f],
[t, t, f, t],
[f, f, f, f],
[f, f, f, f]]

and start = (3, 0) (bottom left) and end = (0, 0) (top left),
the minimum number of steps required to reach the end is 7,
since we would need to go through (1, 2) because there is a wall everywhere else on the second row.
*/

// return if (x, y) is a valid position in the board
bool is_valid(int arr[M][N], int x, int y){
	return x >= 0 && x < M && y >= 0 && y < N && !arr[x][y];
}


bool is_possible_path(int arr[M][N], pair<int, int> start, pair<int, int> end){
	if(start == end){
		arr[start.first][start.second] = false;
		return true;
	}
	if(is_valid(arr, start.first, start.second)){
		arr[start.first][start.second] = true;
		for(int i=-1;i<=1;i++)
			for(int j=-1;j<=1;j++){
				if(is_possible_path(arr, make_pair(start.first+i, start.second+j), end))
					return true;
			}
		arr[start.first][start.second] = false;
	}
	return false;
}

// main function
int main(){
	int arr[M][N] = {
        {false, false, false, false},
        {true, true, false, true},
        {false, false, false, false},
        {false, false, false, false}
    };
    if(is_possible_path(arr, make_pair(3, 0), make_pair(0, 0)))
        cout << "Yes\n";
    else
        cout << "No\n";
}