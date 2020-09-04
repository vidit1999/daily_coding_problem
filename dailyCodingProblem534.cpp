#include <bits/stdc++.h>
using namespace std;

/*
Given a string, determine whether any permutation of it is a palindrome.

For example, carrace should return true, since it can be rearranged to form racecar,
which is a palindrome. daily should return false, since there's no rearrangement that can form a palindrome.
*/

bool isPermutationPalindrome(string s){
	unordered_map<char, int> letterCount;
	for(char c : s)
		letterCount[c]++;
	
	int oddCount = 0;
	for(auto it : letterCount){
		if(it.second%2 != 0){
			oddCount++;
			if(oddCount > 1)
				return false;
		}
	}
	
	return true;
}

// main function
int main(){
	if(isPermutationPalindrome("carrace"))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}