#include <bits/stdc++.h>
using namespace std;

/*
You're given a string consisting solely of (, ), and *. * can represent either a (, ), or an empty string.
Determine whether the parentheses are balanced.
For example, (()* and (*) are balanced. )*( is not balanced.
*/

bool isBalanced(string s){
	int lo = 0, hi = 0;
	
	for(char c : s){
		lo += ((c == '(')? 1 : -1);
		hi += ((c != ')')? 1 : -1);
		
		if(hi < 0)
			break;
		lo = max(lo, 0);
	}
	
	return lo == 0;
}

void testFunc(vector<string> v){
	for(auto s : v){
		if(isBalanced(s))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// main function
int main(){
	testFunc({
		"(()*",
		"(*)",
		"",
		")*("
	});
	return 0;
}