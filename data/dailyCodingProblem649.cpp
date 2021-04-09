#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 256

/*
Given a string, return the first recurring character in it,
or null if there is no recurring character.

For example, given the string "acbbac", return "b".
Given the string "abcdef", return null.
*/

char firstRecurringChar(string s){
	int count[MAX_SIZE] = { 0 };
	
	for(char c : s){
		if(++count[c] > 1)
			return c;
	}
	
	return '\0';
}

// main function
int main(){
	cout << firstRecurringChar("acbbac") << "\n";
	cout << firstRecurringChar("abcdef") << "\n";
	return 0;
}