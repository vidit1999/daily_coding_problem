#include <bits/stdc++.h>
using namespace std;

/*
Implement regular expression matching with the following special characters:

. (period) which matches any single character
* (asterisk) which matches zero or more of the preceding element
That is, implement a function that takes in a string and a valid regular expression
and returns whether or not the string matches the regular expression.

For example, given the regular expression "ra." and the string "ray",
your function should return true. The same regular expression on the
string "raymond" should return false.

Given the regular expression ".*at" and the string "chat",
your function should return true. The same regular expression
on the string "chats" should return false.
*/

bool matchPatternHelper(string text, string pat, int m, int n, vector<vector<int>>& dp){
    // both are empty
    if(m == 0 && n == 0) return true;
    
    // if pattern is empty then text must be empty
    if(n == 0) return m == 0;
    
    if(dp[m][n] != -1) return dp[m][n];

    // text is empty but pattern is not
    if(m == 0){
        for(int i=1; i<=n; i++){
            // if all chars in pattern are not *
            // return false
            if(pat[i-1] != '*'){
                dp[m][n] = false;
                break;
            }
        }

        // else return true
        return dp[m][n];;
    }

    if(pat[n-1] == '*')
        dp[m][n] = matchPatternHelper(text, pat, m-1, n, dp) || matchPatternHelper(text, pat, m, n-1, dp);
    else if(pat[n-1] == '.' || pat[n-1] == text[m-1])
        dp[m][n] = matchPatternHelper(text, pat, m-1, n-1, dp);
    else
        dp[m][n] = false;
    
    return dp[m][n];
}

bool matchPattern(string text, string pat){
    int m = text.length(), n = pat.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    return matchPatternHelper(text, pat, m, n, dp);
}

void checkMatches(string text, vector<string> pats){
    for(string pat : pats){
        cout << (matchPattern(text, pat) ? "Yes" : "No") << " ";
    }
    cout << "\n";
}

// main function
int main(){
    string text = "baaabab";
    vector<string> pats = {
        "*****ba*****ab",
        "ba*****ab",
        "ba*ab",
        "a*ab",
        "a*****ab",
        "*a*****ab",
        "ba*ab****",
        "****",
        "*",
        "aa?ab",
        "b*b",
        "a*a",
        "baaabab",
        "?baaabab",
        "*baaaba*",
    };

    checkMatches(text, pats);

    return 0;
}