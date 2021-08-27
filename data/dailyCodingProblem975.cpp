#include <bits/stdc++.h>
using namespace std;

/*
You are going on a road trip, and would like to create a suitable music playlist.
The trip will require N songs, though you only have M songs downloaded, where M < N.
A valid playlist should select each song at least once, and guarantee a buffer of B songs between repeats.

Given N, M, and B, determine the number of valid playlists.
*/

int numWays(int N, int M, int B){
	int dp[N+1][M+1];
	memset(dp, 0, sizeof(dp));
	
	dp[0][0] = 1;

	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			dp[i][j] = (dp[i-1][j-1] * (M-j+1) + dp[i-1][j] * max(j-B, 0));
		}
	}

	return dp[N][M];
}


// main function
int main(){
    cout << numWays(3, 3, 1) << "\n";
    cout << numWays(3, 2, 0) << "\n";
    cout << numWays(3, 2, 1) << "\n";
	return 0;
}