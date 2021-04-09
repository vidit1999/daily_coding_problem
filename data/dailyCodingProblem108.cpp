#include <bits/stdc++.h>
using namespace std;

/*
Given two strings A and B, return whether or
not A can be shifted some number of times to get B.

For example, if A is abcde and B is cdeab, return true.
If A is abc and B is acb, return false.
*/

bool isShiftedString(string s1, string s2){
	if(s1.length() != s2.length()) return false;
	
	int n = s1.length();
	
	for(int i=0; i<n; i++){
		string rotated = s1.substr(i) + s1.substr(0, i);
		if(rotated == s2)
			return true;
	}
	
	return false;
}

// main function
int main(){
	if(isShiftedString("abcde", "cdeab"))
		cout << "Yes\n";
	else
		cout << "No\n";
    
    if(isShiftedString("abc", "acb"))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}