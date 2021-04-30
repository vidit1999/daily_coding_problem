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

string doOperation(string num1, string num2, string op){
    if(op == "+") return to_string(stoi(num1) + stoi(num2));
    if(op == "-") return to_string(stoi(num1) - stoi(num2));
    if(op == "*") return to_string(stoi(num1) * stoi(num2));
    if(op == "/") return to_string(stoi(num1) / stoi(num2));
    return "-1";
}

int evalRevPolish(vector<string> expression){
    stack<string> s;

    for(auto e : expression){
        if(e == "+" || e == "-" || e == "*" || e == "/"){
            if(s.empty()) return -1;
            string num2 = s.top(); s.pop();

            if(s.empty()) return -1;
            string num1 = s.top(); s.pop();

            s.push(doOperation(num1, num2, e));
        } else {
            s.push(e);
        }
    }

    if(s.empty() || s.size() > 1) return -1;
    return stoi(s.top());
}

// main function
int main(){
    vector<string> expression = {
        "15", "7", "1", "1", "+", "-", "/", "3", "*", "2", "1", "1", "+", "+", "-"
    };

    cout << evalRevPolish(expression) << "\n";

    return 0;
}