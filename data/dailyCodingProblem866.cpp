#include <bits/stdc++.h>
using namespace std;

/*
Given an array of numbers representing the stock prices of a company
in chronological order and an integer k, return the maximum profit
you can make from k buys and sells. You must buy the stock before
you can sell it, and you must sell the stock before you can buy it again.

For example, given k = 2 and the array [5, 2, 4, 0, 1], you should return 3.
*/

int stockBuySellHelper(int arr[], int n, int k, vector<vector<int>>& dp){
    if(k == 0 || n == 0) return 0;

    if(dp[n][k] != -1) return dp[n][k];

    int ans = 0;

    for(int i=n-1; i>=0; i--){
        ans = max(
            ans,
            arr[n] - arr[i] + stockBuySellHelper(arr, i, k-1, dp)
        );
    }

    ans = max(ans, stockBuySellHelper(arr, n-1, k, dp));

    dp[n][k] = ans;

    return ans;
}

int stockBuySell(int arr[], int n, int k){
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    return stockBuySellHelper(arr, n-1, k, dp);
}

// main function
int main(){
    int arr[] = {5, 2, 4, 0, 1}; // {10, 22, 5, 75, 65, 80};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;

    cout << stockBuySell(arr, n, k) << "\n";

    return 0;
}