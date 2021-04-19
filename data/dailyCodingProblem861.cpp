#include <bits/stdc++.h>
using namespace std;

#define N 8

/*
A knight is placed on a given square on an 8 x 8 chessboard.
It is then moved randomly several times, where each move is a
standard knight move. If the knight jumps off the board at any
point, however, it is not allowed to jump back on.

After k moves, what is the probability that the knight remains on the board?
*/

bool isSafe(int i, int j){
    return i >= 0 && i < N && j >= 0 && j < N;
}

double knightProbHelper(
    int x, int y, int k,
    vector<pair<int, int>>& moves,
    unordered_map<int, unordered_map<int, unordered_map<int, double>>>& dp
){
    // if knight is not safe return 0
    if(!isSafe(x, y)) return 0;

    // safe after k moves return 1
    if(k == 0) return 1;

    if(
        dp.find(x) != dp.end() &&
        dp[x].find(y) != dp[x].end() &&
        dp[x][y].find(k) != dp[x][y].end()
    ){
        return dp[x][y][k];
    }

    dp[x][y][k] = 0;

    for(auto p : moves){
        dp[x][y][k] += knightProbHelper(x+p.first, y+p.second, k-1, moves, dp) / 8.0;
    }

    return dp[x][y][k];
}

double knightProb(int x, int y, int k){
    unordered_map<int, unordered_map<int, unordered_map<int, double>>> dp;
    vector<pair<int, int>> moves = {
        {1, 2}, {2, 1},
        {1, -2}, {2, -1},
        {-1, -2}, {-2, -1},
        {-1, 2}, {-2, 1}
    };

    return knightProbHelper(x, y, k, moves, dp);
}

// main function
int main(){
    cout << knightProb(0, 0, 3) << "\n";
    return 0;
}