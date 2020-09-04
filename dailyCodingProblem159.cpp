#include <bits/stdc++.h>
using namespace std;

/*
Given a string, return the first recurring character in it,
or null if there is no recurring character.

For example, given the string "acbbac", return "b".
Given the string "abcdef", return null.
*/

char firstRecurring(string s){
	unordered_set<int> uset;
	
	for(char c : s){
		if(uset.find(c) != uset.end()) return c;
		uset.insert(c);
	}
	
	return '$';
}

// main function
int main(){
	cout << firstRecurring("acbbac") << "\n";
	cout << firstRecurring("abcdef") << "\n";
	return 0;
}