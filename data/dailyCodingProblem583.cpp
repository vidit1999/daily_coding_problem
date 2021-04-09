#include <bits/stdc++.h>
#define M 3
#define N 4
using namespace std;

/*
You are given a 2-d matrix where each cell
represents number of coins in that cell.
Assuming we start at matrix[0][0], and can
only move right or down, find the maximum
number of coins you can collect by the bottom right corner.

For example, in this matrix

0 3 1 1
2 0 0 4
1 5 3 1

The most we can collect is 0 + 2 + 1 + 5 + 3 + 1 = 12 coins.
*/

int mostCollectCoins(int mat[M][N]){
	int dp[M][N];

	dp[0][0] = mat[0][0];

	// for the case of first row
	for(int i=1;i<N;i++)
		dp[0][i] = dp[0][i-1] + mat[0][i];

	// for the case of first column
	for(int i=1;i<M;i++)
		dp[i][0] = dp[i-1][0] + mat[i][0];

	for(int i=1;i<M;i++){
		for(int j=1;j<N;j++){
			dp[i][j] = mat[i][j] + max(dp[i-1][j], dp[i][j-1]);
		}
	}

	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}

	return dp[M-1][N-1];
}

// main function
int main(){
	int mat[M][N] = {
		{0, 3, 1, 1},
		{2, 0, 0, 4},
		{1, 5, 3, 1}
	};

	cout << mostCollectCoins(mat) << "\n";
	return 0;
}