#include <bits/stdc++.h>
using namespace std;

/*
Given a string of round, curly, and square open and closing brackets,
return whether the brackets are balanced (well-formed).

For example, given the string "([])[]({})", you should return true.

Given the string "([)]" or "((()", you should return false.
*/

bool bracketsValid(string s){
	stack<char> stk;
	
	for(char c : s){
		if(c == '(' || c == '{' || c == '[')
			stk.push(c);
		else{
			if(stk.empty()) return false;
			if(stk.top() == '(' && c != ')') return false;
			if(stk.top() == '{' && c != '}') return false;
			if(stk.top() == '[' && c != ']') return false;
			
			stk.pop();
		}
	}
	
	return stk.empty();
}

// main function
int main(){
	cout << bracketsValid("([])[]({})") << "\n";
	cout << bracketsValid("([)]") << "\n";
	cout << bracketsValid("((()") << "\n";
	return 0;
}