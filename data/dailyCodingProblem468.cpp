#include <bits/stdc++.h>
#define N 3
using namespace std;

/*
Given an N by N matrix, rotate it by 90 degrees clockwise.

For example, given the following matrix:

[[1, 2, 3],
 [4, 5, 6],
 [7, 8, 9]]
you should return:

[[7, 4, 1],
 [8, 5, 2],
 [9, 6, 3]]

Follow-up: What if you couldn't use any extra space?
*/

void rotateMatrix(int mat[][N]){
    for(int x=0;x<N/2;x++){
        for(int y=x;y<N-x-1;y++){

            int tmp = mat[x][y];
            mat[x][y] = mat[N-y-1][x];
            mat[N-y-1][x] = mat[N-x-1][N-y-1];
            mat[N-x-1][N-y-1] = mat[y][N-x-1];
            mat[y][N-x-1] = tmp;
        }
    }
}

void showMatrix(int mat[][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    }
}

// main function
int main(){
    int mat[][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    showMatrix(mat);
    cout << "\n----------\n";
    rotateMatrix(mat);
    showMatrix(mat);
    return 0;
}