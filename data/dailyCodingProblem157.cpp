#include <bits/stdc++.h>
using namespace std;

/*
Given a string, determine whether any permutation of it is a palindrome.

For example, carrace should return true, since it can be rearranged to form racecar,
which is a palindrome. daily should return false, since there's no rearrangement that can form a palindrome.
*/

bool anyPermPalindrome(string s){
	unordered_map<char, int> char_count;
	
	for(char c : s) char_count[c]++;
	
	int odd_count = 0;
	
	for(auto it : char_count){
		if(it.second%2 != 0)
			if(++odd_count > 1) return false;
	}
	
	return true;
}

// main function
int main(){
	cout << anyPermPalindrome("carrace") << "\n";
	cout << anyPermPalindrome("daily") << "\n";
	return 0;
}