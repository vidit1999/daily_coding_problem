#include <bits/stdc++.h>
using namespace std;

/*
If V == 0, then 0 coins required.
If V > 0
minCoins(coins[0..m-1], V) 
= min {1 + minCoins(V-coin[i])} 
where i varies from 0 to m-1 
and coin[i] <= V 
*/

// recursive solution
int minCoins(int coins[], int m, int V){
	if(V == 0)
		return 0;
	int res = INT_MAX;
	for(int i=0;i<m;i++){
		if(coins[i] <= V){
			int sub_res = minCoins(coins, m, V-coins[i]);
			if(sub_res != INT_MAX && sub_res + 1 < res)
				res = sub_res + 1;
		}
	}
	return res;
}

// dp based solution
int minCoinsDP(int coins[], int m, int V){
	int table[V+1];
	table[0] = 0;
	for(int i=1;i<=V;i++)
		table[i] = INT_MAX;
	for(int i=1;i<=V;i++){
		for(int j=0;j<m;j++){
			if(coins[j] <= i){
				int sub_res = table[i - coins[j]];
				if(sub_res != INT_MAX && sub_res + 1 < table[i])
					table[i] = sub_res + 1;
			}
		}
	}
	return table[V];
}

// main function
int main(){
	int coins[] = {9, 6, 5, 1};
	int m = sizeof(coins)/sizeof(coins[0]);
	int V = 11;
	cout << minCoinsDP(coins, m, V) << "\n";
	return 0;
}