#include <bits/stdc++.h>
using namespace std;

#define N 3
#define K 3

/*
A builder is looking to build a row of N houses that can be of K different colors.
He has a goal of minimizing cost while ensuring that no two neighboring houses are of the same color.

Given an N by K matrix where the nth row and kth column represents the cost to
build the nth house with kth color, return the minimum cost which achieves this goal.
*/

int minCostHelper(
	int prev_color, int curr_house,
	int cost_mat[N][K], unordered_map<string, int>& dp
){
	if(N > 1 && K < 2){
		return INT_MAX;
	}
	
	if(curr_house == N){
		return 0;
	}
	
	string find_string = to_string(prev_color) + "$" + to_string(curr_house);
	
	if(dp.find(find_string) != dp.end()){
		return dp[find_string];
	}
	
	int min_cost = INT_MAX;
	
	for(int i=0; i<K; i++){
		if(i != prev_color){
			min_cost = min(
				min_cost,
				cost_mat[curr_house][i] + minCostHelper(i, curr_house+1, cost_mat, dp)
			);
		}
	}
	
	dp[find_string] = min_cost;
	
	return min_cost;
}

int minCost(int cost_mat[N][K]){
	unordered_map<string, int> dp;
	return minCostHelper(-1, 0, cost_mat, dp);
}

// main function
int main(){
	int cost_mat[N][K] = {
		{1, 3, 2},
		{2, 4, 5},
		{5, 2, 3}
	};
	
	cout << minCost(cost_mat) << "\n";
	
	return 0;
}