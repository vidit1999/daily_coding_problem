#include <bits/stdc++.h>
using namespace std;

/*
Given a string of round, curly, and square open and closing brackets,
return whether the brackets are balanced (well-formed).

For example, given the string "([])[]({})", you should return true.

Given the string "([)]" or "((()", you should return false.
*/

bool isBalanced(string brackets){
	stack<char> stk;
	
	for(char bracket : brackets){
		if(bracket == '(' || bracket == '{' || bracket == '[')
			stk.push(bracket);
		else{
			if(stk.empty()) return false;
			switch(bracket){
				case ')' : { if(stk.top() != '(') return false; break; }
				case '}' : { if(stk.top() != '{') return false; break; }
				case ']' : { if(stk.top() != '[') return false; break; }
			}
			stk.pop();
		}
	}
	
	return stk.empty();
}

// main function
int main(){
	cout << boolalpha << isBalanced("([)]") << "\n";
	return 0;
}