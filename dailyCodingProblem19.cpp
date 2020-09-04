#include <bits/stdc++.h>
using namespace std;

#define N 4
#define K 3

/*
A builder is looking to build a row of N houses that can be of K different colors.
He has a goal of minimizing cost while ensuring that no two neighboring houses are of the same color.

Given an N by K matrix where the nth row and kth column represents
the cost to build the nth house with kth color,
return the minimum cost which achieves this goal.
*/

int minCost(int cost[N][K]){
	int dp[N][K];
	
	for(int i=0; i<K; i++){
		dp[0][i] = cost[0][i];
	}
	
	for(int i=1; i<N; i++){
		for(int j=0; j<K; j++){
			dp[i][j] = INT_MAX;
			for(int col=0; col<K; col++){
				if(col != j){
					dp[i][j] = min(dp[i][j], dp[i-1][col] + cost[i][j]);
				}
			}
		}
	}

	int min_cost = INT_MAX;
	
	for(int i=0; i<K; i++){
		min_cost = min(min_cost, dp[N-1][i]);
	}
	
	return min_cost;
}

// main function
int main(){
	srand(time(0));
	
	int cost[N][K];
	
	for(int i=0; i<N; i++){
		for(int j=0; j<K; j++){
			cost[i][j] = rand()%10+1;
			cout << cost[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
    
	cout << minCost(cost) << "\n";
	
	return 0;
}