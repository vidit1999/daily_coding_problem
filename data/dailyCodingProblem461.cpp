#include <bits/stdc++.h>
using namespace std;

/*
There is an N by M matrix of zeroes. Given N and M,
write a function to count the number of ways of starting
at the top-left corner and getting to the bottom-right corner.
You can only move right or down.

For example, given a 2 by 2 matrix, you should return 2,
since there are two ways to get to the bottom-right:

Right, then down
Down, then right

Given a 5 by 5 matrix, there are 70 ways to get to the bottom-right.
*/

int numWays(int n, int m){
    int numWaysDP[n][m];

    for(int i=0;i<n;i++){
        numWaysDP[i][0] = 1;
    }
    for(int i=0;i<m;i++){
        numWaysDP[0][i] = 1;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            numWaysDP[i][j] = numWaysDP[i-1][j] + numWaysDP[i][j-1];
        }
    }
    return numWaysDP[n-1][m-1];
}

// main function
int main(){
    cout << numWays(2,2) << "\n";
    cout << numWays(2,3) << "\n";
    cout << numWays(3,3) << "\n";
    return 0;
}