#include <bits/stdc++.h>
using namespace std;

/*
Given a array of numbers representing the stock prices of a company in chronological order,
write a function that calculates the maximum profit you could have made from buying and selling that stock.
You're also given a number fee that represents a transaction fee for each buy and sell transaction.

You must buy before you can sell the stock, but you can make as many transactions as you like.

For example, given [1, 3, 2, 8, 4, 10] and fee = 2, you should return 9, since you could buy
the stock at 1 dollar, and sell at 8 dollars, and then buy it at 4 dollars and sell it at 10 dollars.
Since we did two transactions, there is a 4 dollar fee, so we have 7 + 6 = 13 profit minus 4 dollars of fees.
*/

int maxProfit(vector<int> prices, int fees){
	int n = prices.size();
	if(n == 1) return 0;
	
	int i = 0, maxPro = 0, count = 0;
	
	while(i < n-1){
		while(i < n-1 && prices[i] >= prices[i+1])
			i++;
		
		if(i == n-1)
			break;
		
		int buy = i++;
		
		while(i < n && ((prices[i] >= prices[i-1]) || (prices[i-1] - prices[buy] <= fees)))
			i++;
		
		int sell = i-1;
		count++;
		maxPro += (prices[sell]-prices[buy] - fees);
	}
	
	return maxPro;
}

// main function
int main(){
	cout << maxProfit({1, 3, 2, 8, 4, 10}, 2) << "\n";
	return 0;
}