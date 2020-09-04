#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of integers representing coin denominations and a total amount of money.
Write a function to compute the fewest number of coins needed to make up that amount.
If it is not possible to make that amount, return null.

For example, given an array of [1, 5, 10] and an amount 56, return 7 since we can use 5 dimes,
1 nickel, and 1 penny.

Given an array of [5, 8] and an amount 15, return 3 since we can use 5 5-cent coins.
*/

int minCoin(int coins[], int n, int amount){
	int table[amount+1];
	
	table[0] = 0;
	
	for(int i=1;i<=amount;i++){
		table[i] = INT_MAX;
		for(int j=0;j<n;j++){
			if(i >= coins[j]){
				int res = table[i - coins[j]];
				if(res != INT_MAX && res+1 < table[i])
					table[i] = res + 1;
			}
		}
	}
	
	return table[amount];
}

// main function
int main(){
	int coins[] = {5, 8};
	int n = sizeof(coins)/sizeof(coins[0]);
	int amount = 15;
	
	cout << minCoin(coins, n, amount) << "\n";
	return 0;
}