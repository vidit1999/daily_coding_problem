#include <bits/stdc++.h>
using namespace std;

/*
Given a string of round, curly, and square open and
closing brackets, return whether the brackets are balanced (well-formed).

For example, given the string "([])[]({})", you should return true.

Given the string "([)]" or "((()", you should return false.
*/

bool checkBrackets(string s){
    stack<char> stk;

    for(char c : s){
        if(c == '(' || c == '{' || c == '['){
            stk.push(c);
        }
        else{
            if(stk.empty()) return false;

            if(c == ')' && stk.top() != '(') return false;
            if(c == '}' && stk.top() != '{') return false;
            if(c == ']' && stk.top() != '[') return false;

            stk.pop();
        }
    }

    return stk.empty();
}

// main function
int main(){
    cout << checkBrackets("([])[]({})") << "\n";
    cout << checkBrackets("([)]") << "\n";
    cout << checkBrackets("((()") << "\n";
    return 0;
}
