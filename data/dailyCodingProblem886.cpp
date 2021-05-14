#include <bits/stdc++.h>
using namespace std;

/*
The edit distance between two strings refers to the minimum
number of character insertions, deletions, and substitutions
required to change one string to the other. For example, the
edit distance between “kitten” and “sitting” is three:
substitute the “k” for “s”, substitute the “e” for “i”, and append a “g”.

Given two strings, compute the edit distance between them.
*/

int editDistanceHelper(string& s1, string& s2, int m, int n, vector<vector<int>>& dp){
    if(m == 0) return n;
    if(n == 0) return m;

    if(dp[m][n] != -1) return dp[m][n];

    if(s1[m-1] == s2[n-1]){
        dp[m][n] = editDistanceHelper(s1, s2, m-1, n-1, dp);
    } else {
        dp[m][n] = 1 + min(
            editDistanceHelper(s1, s2, m-1, n-1, dp),
            min(
                editDistanceHelper(s1, s2, m, n-1, dp),
                editDistanceHelper(s1, s2, m-1, n, dp)
            )
        );
    }

    return dp[m][n];
}

int editDistance(string s1, string s2){
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    return editDistanceHelper(s1, s2, m, n, dp);
}

// main function
int main(){
    cout << editDistance("geek", "gesek") << "\n";
    cout << editDistance("cat", "cut") << "\n";
    cout << editDistance("sunday", "saturday") << "\n";
    cout << editDistance("kitten", "sitting") << "\n";
    return 0;
}
