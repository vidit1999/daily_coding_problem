#include <bits/stdc++.h>
using namespace std;

/*
Given a array of numbers representing the stock prices of a company in chronological order,
write a function that calculates the maximum profit you could have made
from buying and selling that stock once. You must buy before you can sell it.

For example, given [9, 11, 8, 5, 7, 10], you should return 5,
since you could buy the stock at 5 dollars and sell it at 10 dollars.
*/

int maxStock(int arr[], int n){
	int max_profit = 0, min_num = arr[0];
	
	for(int i=1; i<n; i++){
		max_profit = max(max_profit, arr[i] - min_num);
		min_num = min(min_num, arr[i]);
	}
	
	return max_profit;
}

// main function
int main(){
	int arr[] = {1, 2, 90, 10, 110}; // {9, 11, 8, 5, 7, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << maxStock(arr, n) << "\n";
	return 0;
}