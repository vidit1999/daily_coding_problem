#include <bits/stdc++.h>
using namespace std;

/*
Let A be an N by M matrix in which every row and every column is sorted.

Given i1, j1, i2, and j2, compute the number of
elements of M smaller than M[i1, j1] and larger than M[i2, j2].

For example, given the following matrix:

[[1, 3, 7, 10, 15, 20],
[2, 6, 9, 14, 22, 25],
[3, 8, 10, 15, 25, 30],
[10, 11, 12, 23, 30, 35],
[20, 25, 30, 35, 40, 45]]

And i1 = 1, j1 = 1, i2 = 3, j2 = 3, return 15 as
there are 15 numbers in the matrix smaller than 6 or greater than 23.
*/


int matrixSmallerGreater(
    int i1, int j1, int i2, int j2,
    vector<vector<int>>& mat
){
    int ans = 0;

    for(auto& v : mat){
        for(int e : v){
            if(e < mat[i1][j1] || e > mat[i2][j2]){
                ans++;
            }
        }
    }

    return ans;
}

// main function
int main(){
    vector<vector<int>> mat = {
        {1, 3, 7, 10, 15, 20},
        {2, 6, 9, 14, 22, 25},
        {3, 8, 10, 15, 25, 30},
        {10, 11, 12, 23, 30, 35},
        {20, 25, 30, 35, 40, 45},
    };

    cout << matrixSmallerGreater(1, 1, 3, 3, mat) << "\n";
    return 0;
}
