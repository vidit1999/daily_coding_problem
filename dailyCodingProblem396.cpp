#include <bits/stdc++.h>
using namespace std;

/*
Given a string, return the length of the longest palindromic subsequence in the string.

For example, given the following string:

MAPTPTMTPA

Return 7, since the longest palindromic subsequence in the string is APTMTPA.
Recall that a subsequence of a string does not have to be contiguous!

Your algorithm should run in O(n^2) time and space.
*/

int longestPlindromicSubSeq(string s, int i, int j, unordered_map<string, int>& palindromicLength){
	string unique_key = to_string(i) + "," + to_string(j);
	
	if(palindromicLength.find(unique_key) != palindromicLength.end())
		return palindromicLength[unique_key];
	
	if(i == j)
		palindromicLength[unique_key] = 1;
	else if(s[i] == s[j])
		palindromicLength[unique_key] = 2 + longestPlindromicSubSeq(s, i+1, j-1, palindromicLength);
	else
		palindromicLength[unique_key] = max(longestPlindromicSubSeq(s, i+1, j, palindromicLength),
											longestPlindromicSubSeq(s, i, j-1, palindromicLength));
	
	return palindromicLength[unique_key];
}

// main function
int main(){
	unordered_map<string, int> palindromicLength;
	string s = "MAPTPTMTPA";
	cout << longestPlindromicSubSeq(s, 0, s.length()-1, palindromicLength);
	return 0;
}