#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of arrays of integers, where each array
corresponds to a row in a triangle of numbers. For example,
[[1], [2, 3], [1, 5, 1]] represents the triangle:

  1
 2 3
1 5 1

We define a path in the triangle to start at the top and go down
one row at a time to an adjacent value, eventually ending with
an entry on the bottom row. For example, 1 -> 3 -> 5. The weight
of the path is the sum of the entries.

Write a program that returns the weight of the maximum weight path.
*/

int maximumWeightPath(vector<vector<int>> triangle){
    if(triangle.empty()) return -1;

    for(int i=triangle.size()-2; i>=0; i--){
        for(int j=0; j<triangle[i].size(); j++){
            triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }

    return triangle[0][0];
}

// main function
int main(){
    cout << maximumWeightPath({{1}, {2, 3}, {1, 5, 1}}) << "\n";
    return 0;
}