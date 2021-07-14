#include <bits/stdc++.h>
using namespace std;

/*
You're given a string consisting solely of (, ), and *. *
can represent either a (, ), or an empty string.
Determine whether the parentheses are balanced.

For example, (()* and (*) are balanced. )*( is not balanced.
*/

bool checkParenthesesBalanced(string& s){
    int count = 0;

    for(char c : s){
        if(c == '$') continue;
        if(c == '(') count++;
        if(c == ')' && --count < 0) return false;
    }

    return (count == 0);
}

bool isBalancedHelper(int i, string& s, vector<int>& indices){
    if(i == indices.size()) return checkParenthesesBalanced(s);

    for(char c : {'$', '(', ')'}){
        s[i] = c;
        if(isBalancedHelper(i+1, s, indices))
            return true;
    }

    return false;
}

bool isBalanced(string s){
    vector<int> indices;

    for(int i=0; i<s.length(); i++){
        if(s[i] == '*'){
            indices.push_back(i);
        }
    }

    return isBalancedHelper(0, s, indices);
}


// main function
int main(){
    cout << isBalanced("(()*") << "\n";
    cout << isBalanced("(*)") << "\n";
    cout << isBalanced(")*(") << "\n";
    cout << isBalanced("))(()(**()") << "\n";
    cout << isBalanced("))(*()()**") << "\n";
    cout << isBalanced("**)*((*)))") << "\n";
    cout << isBalanced(")*)**()((*") << "\n";
    cout << isBalanced(")*)**)*()(") << "\n";

    return 0;
}