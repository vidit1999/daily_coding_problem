#include <bits/stdc++.h>
using namespace std;

/*
Given a string, find the palindrome that can be made by inserting
the fewest number of characters as possible anywhere in the word.
If there is more than one palindrome of minimum length that can
be made, return the lexicographically earliest one
(the first one alphabetically).

For example, given the string "race", you should return "ecarace",
since we can add three letters to it (which is the smallest amount
to make a palindrome). There are seven other palindromes that can
be made from "race" by adding three letters, but "ecarace" comes
first alphabetically.

As another example, given the string "google",
you should return "elgoogle".
*/

string shortestCommonSuper(string s, string rev, vector<vector<int>>& dp){
	int n = s.length();

	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
			if(i == 0)
				dp[i][j] = j;
			else if(j == 0)
				dp[i][j] = i;
			else if(s[i-1] == rev[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j]);
		}
	}

	int index = dp[n][n];
	int i = n, j = n;
	string str;

	while(i > 0 && j > 0){
		if(s[i-1] == rev[j-1]){
			str.push_back(s[i-1]);
			i--;
			j--;
		}
		else if(dp[i-1][j] > dp[i][j-1]){
			str.push_back(rev[j-1]);
			j--;
		}
		else{
			str.push_back(s[i-1]);
			i--;
		}
		index--;
	}

	while(i > 0){
		str.push_back(s[i-1]);
		i--;
		index--;
	}

	while(j > 0){
		str.push_back(rev[j-1]);
		j--;
		index--;
	}

	return str;
}

string minInsertPalindrome(string s){
	string rev = s;
	reverse(rev.begin(), rev.end());

	int n = s.length();
	vector<vector<int>> dp(n+1, vector<int>(n+1));

	auto ans1 = shortestCommonSuper(s, rev, dp);
	auto ans2 = shortestCommonSuper(rev, s, dp);

	return (ans1 < ans2)? ans1 : ans2;
}

// main function
int main(){
	cout << minInsertPalindrome("google") << "\n";
	cout << minInsertPalindrome("race") << "\n";
	cout << minInsertPalindrome("lol") << "\n";
	cout << minInsertPalindrome("olo") << "\n";
	cout << minInsertPalindrome("aacc") << "\n";
	cout << minInsertPalindrome("ccaa") << "\n";
	cout << minInsertPalindrome("ac") << "\n";
	cout << minInsertPalindrome("ca") << "\n";

	return 0;
}