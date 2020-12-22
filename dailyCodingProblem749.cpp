#include <bits/stdc++.h>
using namespace std;

/*
Given a string, find the longest palindromic contiguous substring.
If there are more than one with the maximum length, return any one.

For example, the longest palindromic substring of "aabcdcb" is "bcdcb".
The longest palindromic substring of "bananas" is "anana".
*/

void getStartMaxlen(string& s, int& start, int& max_len, int low, int high){
	while(low >= 0 && high < s.length() && s[low] == s[high]){
		if(high-low+1 > max_len){
			start = low;
			max_len = high-low+1;
		}
		low--;
		high++;
	}
}

string longestPalindromicSubstr(string s){
	int max_len = 0, start = 0;

	for(int i=1; i<s.length(); i++){
		// odd length palindromes
		getStartMaxlen(s, start, max_len, i-1, i+1);

		// even length palindromes
		getStartMaxlen(s, start, max_len, i, i+1);
	}

	return s.substr(start, max_len);
}

// main function
int main(){
	cout << longestPalindromicSubstr("aabcdcb") << "\n";
	cout << longestPalindromicSubstr("bananas") << "\n";
	return 0;
}