#include <bits/stdc++.h>
using namespace std;

/*
Given a string, return the first recurring character in it,
or null if there is no recurring character.

For example, given the string "acbbac", return "b".
Given the string "abcdef", return null.
*/

char firstRepeatingChar(string s){
    unordered_set<char> uset;

    for(char c : s){
        if(uset.find(c) != uset.end()) return c;
        uset.insert(c);
    }

    return '\0';
}

// main function
int main(){
    cout << firstRepeatingChar("acbbac") << "\n";
    cout << firstRepeatingChar("abcdef") << "\n";
    cout << firstRepeatingChar("hello") << "\n";
    cout << firstRepeatingChar("world") << "\n";
    return 0;
}