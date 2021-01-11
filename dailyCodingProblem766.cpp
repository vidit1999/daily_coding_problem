#include <bits/stdc++.h>
using namespace std;

/*
You are given a string consisting of the letters x and y,
such as xyxxxyxyy. In addition, you have an operation called flip,
which changes a single x to y or vice versa.

Determine how many times you would need to apply this operation
to ensure that all x's come before all y's. In the preceding example,
it suffices to flip the second and sixth characters, so you should return 2.
*/

int segerateXY(string s){
    int x_count = 0;

    for(char c : s){
        if(c == 'x'){
            x_count++;
        }
    }

    int i = 0, ans = 0;

    for(; i<x_count; i++){
        if(s[i] == 'y'){
            ans++;
        }
    }

    for(; i<s.length(); i++){
        if(s[i] == 'x'){
            ans++;
        }
    }

    return ans;
}

// main function
int main(){
    cout <<segerateXY("xyxxxyxyy") << "\n";
    return 0;
}
