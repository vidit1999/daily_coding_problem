#include <bits/stdc++.h>
using namespace std;

/*
There is an N by M matrix of zeroes. Given N and M, write a function
to count the number of ways of starting at the top-left corner and
getting to the bottom-right corner. You can only move right or down.

For example, given a 2 by 2 matrix, you should return 2, since there
are two ways to get to the bottom-right:

Right, then down
Down, then right

Given a 5 by 5 matrix, there are 70 ways to get to the bottom-right.
*/

int countWaysHelper(int m, int n, vector<vector<int>>& dp){
    if(m == 1 || n == 1) return 1;

    if(dp[m][n] != -1) return dp[m][n];

    dp[m][n] = countWaysHelper(m-1, n, dp) + countWaysHelper(m, n-1, dp);

    return dp[m][n];
}

int countWays(int m, int n){
    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    return countWaysHelper(m, n, dp);
}

// main function
int main(){
    cout << countWays(5, 5) << "\n";
    cout << countWays(3, 3) << "\n";
    return 0;
}
