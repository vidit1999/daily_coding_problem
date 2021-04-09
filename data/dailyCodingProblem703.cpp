#include <bits/stdc++.h>
using namespace std;

#define N 8

/*
A knight is placed on a given square on an 8 x 8 chessboard.
It is then moved randomly several times, where each move is
a standard knight move. If the knight jumps off the board
at any point, however, it is not allowed to jump back on.

After k moves, what is the probability that the knight remains on the board?
*/

bool isValid(int x, int y){
    return (
        x >= 0 && x < N &&
        y >= 0 && y < N
    );
}


double knightOnBoardHelper(
    int x, int y, int k, int dx[], int dy[],
    vector<vector<vector<double>>>& dp
){
    if(!isValid(x, y))
        return 0;
    if(k == 0)
        return 1;
    
    if(dp[x][y][k] != -1)
        return dp[x][y][k];

    double ans = 0;

    for(int i=0; i<8; i++){
        ans += knightOnBoardHelper(x+dx[i], y+dy[i], k-1, dx, dy, dp) / 8;
    }

    dp[x][y][k] = ans;

    return ans;
}

double knightOnBoard(int k){
    vector<vector<vector<double>>> dp(
        N+1, vector<vector<double>>(
            N+1, vector<double>(k+1, -1)
        )
    );

    int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

    double ans = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            ans += knightOnBoardHelper(i, j, k, dx, dy, dp);
        }
    }

    return ans/64;
}

// main function
int main(){
    for(int k=1; k<=10; k++){
        cout << knightOnBoard(k) << "\n";
    }
	return 0;
}