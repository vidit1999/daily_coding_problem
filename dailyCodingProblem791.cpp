#include <bits/stdc++.h>
using namespace std;

/*
Write a function, throw_dice(N, faces, total),
that determines how many ways it is possible to
throw N dice with some number of faces each to get a specific total.

For example, throw_dice(3, 6, 7) should equal 15.
*/

int throw_dice_helper(int n, int& faces, int total, vector<vector<int>>& dp){
    if(total == 0 && n == 0) return 1;

    if(total == 0 || n == 0) return 0;

    if(dp[n][total] != -1) return dp[n][total];

    int ans = 0;

    for(int i=1; i<=faces; i++){
        if(total >= i){
            ans += throw_dice_helper(n-1, faces, total-i, dp);
        }
    }

    dp[n][total] = ans;

    return ans;
}

int throw_dice(int n, int faces, int total){
    vector<vector<int>> dp(n+1, vector<int>(total+1, -1));
    return throw_dice_helper(n, faces, total, dp);
}

// main function
int main(){
    cout << throw_dice(3, 6, 7) << "\n";
    cout << throw_dice(2, 4, 1) << "\n";
    cout << throw_dice(2, 2, 3) << "\n";
    cout << throw_dice(3, 6, 8) << "\n";
    cout << throw_dice(2, 4, 5) << "\n";
    cout << throw_dice(3, 4, 5) << "\n";

    return 0;
}
