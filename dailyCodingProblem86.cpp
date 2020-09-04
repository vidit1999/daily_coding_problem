#include <bits/stdc++.h>
using namespace std;

/*
Given a string of parentheses, write a function to compute the minimum
number of parentheses to be removed to make the string valid
(i.e. each open parenthesis is eventually closed).

For example, given the string "()())()", you should return 1.
Given the string ")(", you should return 2,
since we must remove all of them.
*/

int removeCount(string s){
	int matching_mismatch = 0;
	int closing_extra = 0;
	
	for(char c : s){
		if(c == '(')
			matching_mismatch++;
		else{
			if(matching_mismatch == 0){
				closing_extra++;
			}
			else
				matching_mismatch--;
		}
	}
	
	return matching_mismatch + closing_extra;
}

// main function
int main(){
	cout << removeCount("()())()") << "\n";
	cout << removeCount(")(") << "\n";
	return 0;
}