#include <bits/stdc++.h>
using namespace std;

/*
The edit distance between two strings refers to the minimum number of character insertions,
deletions, and substitutions required to change one string to the other. For example,
the edit distance between “kitten” and “sitting” is three: substitute the “k” for “s”,
substitute the “e” for “i”, and append a “g”.

Given two strings, compute the edit distance between them.
*/

int editDistance(string s1, string s2){
	int m = s1.length(), n = s2.length();
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
				dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
		}
	}
	
	return dp[m][n];
}

// main function
int main(){
	cout << editDistance("kitten", "sitting") << "\n";
	return 0;
}