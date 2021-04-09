#include <bits/stdc++.h>
using namespace std;

#define CHAR_SIZE 256

/*
Determine whether there exists a one-to-one character
mapping from one string s1 to another s2.

For example, given s1 = abc and s2 = bcd, return true
since we can map a to b, b to c, and c to d.

Given s1 = foo and s2 = bar, return false since
the o cannot map to two characters.
*/

bool oneToOneMap(string s1, string s2){
    if(s1.length() != s2.length()) return false;

    vector<int> s1_char_count(CHAR_SIZE, -1);
    vector<bool> s2_check(CHAR_SIZE, false);

    for(int i=0; i<s1.length(); i++){
        if(s1_char_count[s1[i]] == -1){
            // we have not seen this character before
            // but in s2 we have seen this character
            if(s2_check[s2[i]]){
                return false;
            }

            // mark it as true for s2's character
            s2_check[s2[i]] = true;

            // map the s2's character against s1's character
            s1_char_count[s1[i]] = s2[i];
        }
        else if(s1_char_count[s1[i]] != s2[i]){
            // if mapping exists and it is not same
            return false;
        }
    }

    return true;
}

// main function
int main(){
    cout << oneToOneMap("abc", "bcd") << "\n";
    cout << oneToOneMap("foo", "bar") << "\n";
    cout << oneToOneMap("aab", "xxy") << "\n";
    cout << oneToOneMap("aab", "xyz") << "\n";
    return 0;
}
