#include <bits/stdc++.h>
using namespace std;

/*
Gray code is a binary code where each successive value differ
in only one bit, as well as when wrapping around.
Gray code is common in hardware so that we don't see
temporary spurious values during transitions.

Given a number of bits n, generate a possible gray code for it.

For example, for n = 2, one gray code would be [00, 01, 11, 10].
*/

vector<string> grayCodes(int n){
    vector<string> gray_codes = {"0", "1"};
    
    
    for(int i=2; i<(1 << n); i<<=1){
        for(int j=i-1; j>=0; j--){
            gray_codes.push_back(gray_codes[j]);
        }
        
        for(int j=0; j<2*i; j++){
            gray_codes[j] = (j < i ? "0" : "1") + gray_codes[j];
        }
    }
    
    return gray_codes;
}

// main function
int main(){
    for(auto g : grayCodes(3)){
        cout << g << "\n";
    }
    return 0;
}