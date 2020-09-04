#include <bits/stdc++.h>
using namespace std;

/*
Given a string, split it into as few strings as possible
such that each string is a palindrome.

For example, given the input string racecarannakayak,
return ["racecar", "anna", "kayak"].

Given the input string abc, return ["a", "b", "c"].
*/

vector<string> minSplitPalindrome(string s){
	if(isPalindrome(s, i, j)){
		return {s.substr(i, j-i+1)};
	}
	
	vector<string> ans;
	
	
}

// main function
int main(){
	return 0;
}