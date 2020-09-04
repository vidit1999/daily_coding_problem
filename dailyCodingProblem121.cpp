#include <bits/stdc++.h>
using namespace std;

/*
Given a string which we can delete at most k,
return whether you can make a palindrome.

For example, given 'waterrfetawx' and a k of 2,
you could delete f and x to get 'waterretaw'.
*/

int longestCommonSubseq(string s1, string s2){
	int m = s1.length(), n = s2.length();
	int lcs[m+1][n+1];
	
	for(int i=0; i<=m; i++){
		for(int j=0; j<=n; j++){
			if(i == 0 || j == 0)
				lcs[i][j] = 0;
			else if(s1[i-1] == s2[j-1])
				lcs[i][j] = 1 + lcs[i-1][j-1];
			else
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
		}
	}
	
	return lcs[m][n];
}

bool kDeletePalindrome(string s, int k){
	int n = s.length();
	string rev_s = s;
	
	reverse(rev_s.begin(), rev_s.end());
		
	int lcs_len = longestCommonSubseq(s, rev_s);
	
	return (n - lcs_len <= k);
}

// main function
int main(){
	string s = "waterrfetawx";
	int k = 2;
	cout << kDeletePalindrome(s, k) << "\n";
	return 0;
}