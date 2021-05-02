#include <bits/stdc++.h>
using namespace std;

/*
Given a string, find the longest palindromic contiguous substring.
If there are more than one with the maximum length, return any one.

For example, the longest palindromic substring of "aabcdcb" is "bcdcb".
The longest palindromic substring of "bananas" is "anana".
*/

void getStartMaxlen(int high, int low, int& start, int& maxlen, string& s){
    while(low >= 0 && high < s.length() && s[low] == s[high]){
        if(high-low+1 > maxlen){
            start = low;
            maxlen = high-low+1;
        }
        low--;
        high++;
    }
}

string longestPaindromicSubStr(string s){
    int start = 0, maxlen = 0;

    for(int i=0; i<s.length(); i++){
        getStartMaxlen(i+1, i-1, start, maxlen, s);
        getStartMaxlen(i, i-1, start, maxlen, s);
    }

    return s.substr(start, maxlen);
}

// main function
int main(){
    cout << longestPaindromicSubStr("aabcdcb") << "\n";
    cout << longestPaindromicSubStr("bananas") << "\n";
    cout << longestPaindromicSubStr("forgeeksskeegfor") << "\n";
    cout << longestPaindromicSubStr("geeks") << "\n";
    return 0;
}