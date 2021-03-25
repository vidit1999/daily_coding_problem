#include <bits/stdc++.h>
using namespace std;

#define M 3
#define N 4

/*
You are given a 2-d matrix where each cell represents number of coins in that cell.
Assuming we start at matrix[0][0], and can only move right or down, find the maximum
number of coins you can collect by the bottom right corner.

For example, in this matrix

0 3 1 1
2 0 0 4
1 5 3 1

The most we can collect is 0 + 2 + 1 + 5 + 3 + 1 = 12 coins.
*/

int maxCoin(int arr[M][N]){
    for(int i=1; i<M; i++){
        arr[i][0] += arr[i-1][0];
    }
    
    for(int j=1; j<N; j++){
        arr[0][j] += arr[0][j-1];
    }
    
    for(int i=1; i<M; i++){
        for(int j=1; j<N; j++){
            arr[i][j] += max(arr[i-1][j], arr[i][j-1]);
        }
    }
    
    return arr[M-1][N-1];
}

// main function
int main(){
    int arr[M][N] = {
        {0, 3, 1, 1},
        {2, 0, 0, 4},
        {1, 5, 3, 1}
    };
    
    cout << maxCoin(arr) << "\n";
    
    return 0;
}