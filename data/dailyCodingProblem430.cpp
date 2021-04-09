#include <bits/stdc++.h>
using namespace std;

/*
Given a string of parentheses, find the balanced string that can be produced from it
using the minimum number of insertions and deletions. If there are multiple solutions, return any of them.

For example, given "(()", you could return "(())". Given "))()(", you could return "()()()()".
*/

string minInsDelBalanced(string s){
	int count = 0;
	string ans = "";
	
	for(char c : s){
		if(c == '(')
			count++;
		else{
			if(count == 0)
				ans += '(';
			else
				count--;
		}
		ans += c;
	}
	
	while(count--)
		ans += ')';
	
	return ans;
}

void testFunc(vector<string> v){
	for(string s : v){
		cout << minInsDelBalanced(s) << "\n";
	}
}

// main function
int main(){
	testFunc({
		"(()",
		"))()("
	});
	return 0;
}