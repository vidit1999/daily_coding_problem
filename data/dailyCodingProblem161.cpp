#include <bits/stdc++.h>
using namespace std;

/*
Given a 32-bit integer, return the number with its bits reversed.

For example, given the binary number 1111 0000 1111 0000 1111 0000 1111 0000,
return 0000 1111 0000 1111 0000 1111 0000 1111.
*/

void binRepr(unsigned n){
    if(n > 1)
        binRepr(n/2);
    cout << (n&1);
}

unsigned bitReversed(unsigned num){
	return ~num;
}

// main function
int main(){
    binRepr(252645135);
    cout << "\n";
    binRepr(bitReversed(252645135));
    cout << "\n";
	return 0;
}