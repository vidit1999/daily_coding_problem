#include <bits/stdc++.h>
using namespace std;

/*
Given a positive integer n, find the smallest
number of squared integers which sum to n.

For example, given n = 13, return 2 since 13 = 32 + 22 = 9 + 4.

Given n = 27, return 3 since 27 = 32 + 32 + 32 = 9 + 9 + 9.
*/

int minSqSumHelper(int num, unordered_map<int, int>& dp){
    if(dp.find(num) != dp.end()) return dp[num];

    if(sqrt(num) == floor(sqrt(num))) return 1;

    int ans = num;

    for(int i=1; i*i <=num; i++){
        ans = min(ans, 1 + minSqSumHelper(num - i*i, dp));
    }

    dp[num] = ans;
    
    return ans;
}

int minSqSum(int num){
    unordered_map<int, int> dp;
    return minSqSumHelper(num, dp);
}

// main function
int main(){
    cout << minSqSum(13) << "\n";
    cout << minSqSum(27) << "\n";
    cout << minSqSum(6) << "\n";
    return 0;
}