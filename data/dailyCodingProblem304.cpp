#include <bits/stdc++.h>
#define N 8
using namespace std;

/*
A knight is placed on a given square on an 8 x 8 chessboard.
It is then moved randomly several times, where each move is a standard knight move.
If the knight jumps off the board at any point, however, it is not allowed to jump back on.

After k moves, what is the probability that the knight remains on the board?
*/

bool isInside(int x, int y){
	return x >= 0 && x < N && y >= 0 && y < N;
}

double probabilityBeingInside(int start_x, int start_y, int steps){
	double dp[N][N][steps+1];
	
	int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
	int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			dp[i][j][0] = 1;
	
	for(int s=1;s<=steps;s++){
		for(int x=0;x<N;x++){
			for(int y=0;y<N;y++){
				double prob = 0;
				for(int i=0;i<8;i++){
					int pos_x = x + dx[i];
					int pos_y = y + dy[i];
					if(isInside(pos_x, pos_y))
						prob += dp[pos_x][pos_y][s-1]/8.0;
				}
				dp[x][y][s] = prob;
			}
		}
	}
	
	return dp[start_x][start_y][steps];
}

// main function
int main(){
	cout << probabilityBeingInside(0, 0, 3) << "\n";
	cout << probabilityBeingInside(0, 0, 1) << "\n";
	return 0;
}