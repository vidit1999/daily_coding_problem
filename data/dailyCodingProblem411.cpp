#include <bits/stdc++.h>
using namespace std;

/*
Given a string which we can delete at most k, return whether you can make a palindrome.

For example, given 'waterrfetawx' and a k of 2, you could delete f and x to get 'waterretaw'.
*/

int editDistance(string s1, string s2, int m, int n){
	int dp[m+1][n+1];
	
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i == 0)
				dp[i][j] = j;
			else if(j == 0)
				dp[i][j] = i;
			else if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	return dp[m][n];
}

bool isKPalindrome(string s, int k){
	string r = s;
	reverse(r.begin(), r.end());
	return  editDistance(s, r, s.length(), r.length()) <= 2*k;
}

// main function
int main(){
	if(isKPalindrome("waterrfetawx", 2))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}