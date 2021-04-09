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
	unsigned num = 0b11110000111100001111000011110000;
    binRepr(num);
    cout << "\n";
    binRepr(bitReversed(num));
    cout << "\n";
	return 0;
}