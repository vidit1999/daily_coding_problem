#include <bits/stdc++.h>
using namespace std;

/*
Given an arithmetic expression in Reverse Polish Notation, write a program to evaluate it.

The expression is given as a list of numbers and operands. For example: [5, 3, '+'] should return 5 + 3 = 8.

For example, [15, 7, 1, 1, '+', '-', '/', 3, '*', 2, 1, 1, '+', '+', '-'] should return 5,
since it is equivalent to ((15 / (7 - (1 + 1))) * 3) - (2 + (1 + 1)) = 5.
*/

bool isOperator(string op){
	if(op == "+" || op == "-" || op == "*" || op == "/")
		return true;
	return false;
}

int resultOperation(string op1, string op2, string oprtr){
	if(oprtr == "+")
		return stoi(op1) + stoi(op2);
	if(oprtr == "-")
		return stoi(op1) - stoi(op2);
	if(oprtr == "*")
		return stoi(op1) * stoi(op2);
	if(oprtr == "/")
		return stoi(op1) / stoi(op2);
}

int reversePolishResult(vector<string> expressions){
	stack<string> st;
	for(string s : expressions){
		if(isOperator(s)){
			string op2 = st.top();
			st.pop();
			string op1 = st.top();
			st.pop();
			
			st.push(to_string(resultOperation(op1,op2,s)));
		}
		else
			st.push(s);
	}
	return stoi(st.top());
}

// main function
int main(){
	cout << reversePolishResult({"15", "7", "1", "1", "+", "-", "/", "3", "*", "2", "1", "1", "+", "+", "-"}) << "\n";
	return 0;
}