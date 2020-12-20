#include <bits/stdc++.h>
using namespace std;

/*
Given two strings A and B, return whether or not A
can be shifted some number of times to get B.

For example, if A is abcde and B is cdeab, return true.
If A is abc and B is acb, return false.
*/

bool checkRotation(string s1, string s2){
	return (s1 + s1).find(s2) != string::npos;
}

// main function
int main(){
	cout << checkRotation("abcde", "cdeab") << "\n";
	cout << checkRotation("abc", "acb") << "\n";
	return 0;
}