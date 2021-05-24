#include <bits/stdc++.h>
using namespace std;

/*
Given a string which we can delete at most k,
return whether you can make a palindrome.

For example, given 'waterrfetawx' and a k of 2,
you could delete f and x to get 'waterretaw'.
*/

int kPalindromeHelper(string& s1, string& s2, int m, int n, vector<vector<int>>& dp){
    if(m == 0) return n;
    if(n == 0) return m;

    if(dp[m][n] != -1) return dp[m][n];

    dp[m][n] = (s1[m-1] == s2[n-1])? kPalindromeHelper(s1, s2, m-1, n-1, dp) :
                1 + min(kPalindromeHelper(s1, s2, m-1, n, dp), kPalindromeHelper(s1, s2, m, n-1, dp));

    return dp[m][n];
}

bool kPalindrome(string s, int k){
    int l = s.length();
    vector<vector<int>> dp(l+1, vector<int>(l+1, -1));
    string rev = s;
    reverse(rev.begin(), rev.end());
    return (kPalindromeHelper(s, rev, l, l, dp) <= 2*k);
}

// main function
int main(){
    cout << kPalindrome("waterrfetawx", 2) << "\n";
    cout << kPalindrome("acdcb", 1 ) << "\n";
    return 0;
}