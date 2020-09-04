#include <bits/stdc++.h>
using namespace std;

#define M 9
#define N 10

/*
You are given an M by N matrix consisting of booleans that represents a board.
Each True boolean represents a wall. Each False boolean represents a tile you can walk on.

Given this matrix, a start coordinate, and an end coordinate,
return the minimum number of steps required to reach the end
coordinate from the start. If there is no possible path,
then return null. You can move up, left, down, and right.
You cannot move through walls. You cannot wrap around the edges of the board.

For example, given the following board:

[[f, f, f, f],
[t, t, f, t],
[f, f, f, f],
[f, f, f, f]]

and start = (3, 0) (bottom left) and end = (0, 0) (top left),
the minimum number of steps required to reach the end is 7,
since we would need to go through (1, 2) because there is
a wall everywhere else on the second row.
*/

struct Position{
    int x, y, dis;
};

bool isValid(int x, int y, bool mat[M][N]){
    return (
        x >= 0 && x < M &&
        y >= 0 && y < N &&
        !mat[x][y]
    );
}

vector<pair<int, int>> nextPoints(pair<int, int> pos){
    return {
        {pos.first, pos.second+1},
        {pos.first, pos.second-1},
        {pos.first+1, pos.second},
        {pos.first-1, pos.second}
    };
}



int minStepsToDest(bool matrix[M][N], pair<int, int> start, pair<int, int> end){
    queue<Position> q({{start.first, start.second, 0}});
    
    if(matrix[start.first][start.second]) return -1;

    while(!q.empty()){
        auto front = q.front(); q.pop();
        if(front.x == end.first && front.y == end.second) return front.dis;
        matrix[front.x][front.y] = true;
        for(auto next_point  : nextPoints({front.x, front.y})){
            if(isValid(next_point.first, next_point.second, matrix)){
                q.push({next_point.first, next_point.second, front.dis+1});
            }
        }
    }

    return -1;
}

// main function
int main(){
	// bool matrix[M][N] = {
	// 	{false, false, false, false},
	// 	{true, true, false, true},
	// 	{false, false, false, false},
	// 	{false, false, false, false}
	// };

    bool matrix2[M][N] = {
        { false, true, false, false, false, false, true, false, false, false }, 
        { false, true, false, true, false, false, false, true, false, false }, 
        { false, false, false, true, false, false, true, false, true, false }, 
        { true, true, true, true, false, true, true, true, true, false }, 
        { false, false, false, true, false, false, false, true, false, true }, 
        { false, true, false, false, false, false, true, false, true, true }, 
        { false, true, true, true, true, true, true, true, true, false }, 
        { false, true, false, false, false, false, true, false, false, false }, 
        { false, false, true, true, true, true, false, true, true, false } 
    };

    // cout << minStepsToDest(matrix, {3, 0}, {0, 0}) << "\n";
    cout << minStepsToDest(matrix2, {0, 0}, {3, 4}) << "\n";
	
    return 0;
}