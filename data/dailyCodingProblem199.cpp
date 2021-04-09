#include <bits/stdc++.h>
using namespace std;

/*
Given a string of parentheses, find the balanced string that can be produced
from it using the minimum number of insertions and deletions.
If there are multiple solutions, return any of them.

For example, given "(()", you could return "(())". Given "))()(",
you could return "()()()()".
*/

string balanceParen(string parentheses){
	string ans = "";
	int count = 0;
	
	for(char c : parentheses){
		count += ((c == '(')? 1 : -1);
		if(count == -1){
			ans += '(';
			count = 0;
		}
		ans += c;
	}
	
	while(count--) ans += ')';
	
	return ans;
}

void testFunc(vector<string> v){
	for(auto parentheses : v){
		cout << balanceParen(parentheses) << "\n";
	}
}

// main function
int main(){
	testFunc({"(()", "))()(", "(())(()(", "(()("});
	return 0;
}