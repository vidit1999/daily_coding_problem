#include <bits/stdc++.h>
using namespace std;

/*
Given an array of numbers representing the stock prices of a company in chronological order and an integer k,
return the maximum profit you can make from k buys and sells. You must buy the stock before you can sell it,
and you must sell the stock before you can buy it again.

For example, given k = 2 and the array [5, 2, 4, 0, 1], you should return 3.
*/

int maxProfit(int prices[], int n, int k){
	int profit[k+1][n];
	
	// no transaction so no profit
	for(int i=0;i<n;i++)
		profit[0][i] = 0;
	
	// only one price so no profit
	for(int i=0;i<=k;i++)
		profit[i][0] = 0;
	
	for(int i=1;i<=k;i++){
		int prevDiff = INT_MIN;
		for(int j=1;j<n;j++){
			prevDiff = max(prevDiff, -prices[j-1] + profit[i-1][j-1]);
			profit[i][j] = max(profit[i][j-1], prices[j] + prevDiff);
		}
	}
	
	return profit[k][n-1];
}

// main function
int main(){
	int prices[] = {5, 2, 4, 0, 1};
	int n = sizeof(prices)/sizeof(prices[0]);
	int k = 2;
	
	cout << maxProfit(prices, n, k) << "\n";
	return 0;
}