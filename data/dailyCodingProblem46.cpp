#include <bits/stdc++.h>
using namespace std;

/*
Given a string, find the longest palindromic contiguous substring.
If there are more than one with the maximum length, return any one.

For example, the longest palindromic substring of "aabcdcb" is "bcdcb".
The longest palindromic substring of "bananas" is "anana".
*/

string longestPalindrome(string s){
	int n = s.length();
	
	bool dp[n][n];
	memset(dp, false, sizeof(dp));
	
	for(int i=0; i<n; i++){
		dp[i][i] = true;
	}
	
	int start = 0, max_len = 0;
	
	for(int i=0; i<n-1; i++){
		if(s[i] == s[i+1]){
			dp[i][i+1] = true;
			start = 0;
			max_len = 2;
		}
	}
	
	for(int k=3; k<=n; k++){
		for(int i=0; i<n-k+1; i++){
			int j = i-k+1;
			if(dp[i+1][j-1] && (s[i] == s[j])){
				dp[i][j] = true;
				if(k > max_len){
					start = i;
					max_len = k;
				}
			}
		}
	}
	
	return s.substr(start, max_len);
}

// main function
int main(){
	cout << longestPalindrome("aabcdcb") << "\n";
	cout << longestPalindrome("bananas") << "\n";
	return 0;
}