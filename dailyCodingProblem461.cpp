#include <bits/stdc++.h>
using namespace std;

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