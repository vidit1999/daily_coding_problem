#include <bits/stdc++.h>
using namespace std;

/*
You are given N identical eggs and access to a building with k floors.
Your task is to find the lowest floor that will cause an egg to break,
if dropped from that floor. Once an egg breaks, it cannot be dropped again.
If an egg breaks when dropped from the xth floor, you can assume
it will also break when dropped from any floor greater than x.

Write an algorithm that finds the minimum number of trial drops
it will take, in the worst case, to identify this floor.

For example, if N = 1 and k = 5, we will need to try dropping
the egg at every floor, beginning with the first, until we reach
the fifth floor, so our solution will be 5.
*/

int eggDropHelper(int n, int k, vector<vector<int>>& dp){
    if(k <= 1) return k;
    if(n == 1) return k;
    
    if(dp[n][k] != -1) return dp[n][k];
    
    int min_count = INT_MAX;
    
    for(int i=1; i<=k; i++){
        min_count = min(
            min_count,
            max(
                eggDropHelper(n-1, i-1, dp),
                eggDropHelper(n, k-i, dp)
            )
        );
    }
    
    dp[n][k] = min_count + 1;
    
    return dp[n][k];
}

int eggDrop(int n, int k){
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    return eggDropHelper(n, k, dp);
}

// main function
int main(){
    cout << eggDrop(1, 5) << "\n";
    cout << eggDrop(2, 10) << "\n";
    cout << eggDrop(2, 36) << "\n";
    return 0;
}