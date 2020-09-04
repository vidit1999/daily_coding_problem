#include <bits/stdc++.h>
using namespace std;

/*
Given an arithmetic expression in Reverse Polish Notation,
write a program to evaluate it.

The expression is given as a list of numbers and operands.
For example: [5, 3, '+'] should return 5 + 3 = 8.

For example, [15, 7, 1, 1, '+', '-', '/', 3, '*', 2, 1, 1, '+', '+', '-']
should return 5, since it is equivalent to ((15 / (7 - (1 + 1))) * 3) - (2 + (1 + 1)) = 5.

You can assume the given expression is always valid.
*/

int evaluateExpHelper(int num1, int num2, int op){
	switch(op){
		case '+' : return num1 + num2;
		case '-' : return num1 - num2;
		case '*' : return num1 * num2;
		case '/' : return num1 / num2;
	}
	return -1;
}

int evaluateExp(vector<int> expression){
	stack<int> s;
	
	for(int i : expression){
		if(
			i == '+' || i == '-' ||
			i == '*' || i == '/'
		){
			int num2 = s.top(); s.pop();
			int num1 = s.top(); s.pop();
			s.push(evaluateExpHelper(num1, num2, i));
		}
		else 
			s.push(i);
	}
	
	return s.top();
}

// main function
int main(){
	cout << evaluateExp({15, 7, 1, 1, '+', '-', '/', 3, '*', 2, 1, 1, '+', '+', '-'}) << "\n";
	return 0;
}