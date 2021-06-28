#include <bits/stdc++.h>
using namespace std;

/*
Given a 32-bit positive integer N,
determine whether it is a power
of four in faster than O(log N) time.
*/

bool isPowerOfFour(unsigned n){
    return (n != 0) && !(n & (n-1)) && !(n & 0xAAAAAAAA);
}

// main function
int main(){
    for(int i=0; i<1000; i++){
        if(isPowerOfFour(i)){
            cout << i << "\n";
        }
    }
    return 0;
}