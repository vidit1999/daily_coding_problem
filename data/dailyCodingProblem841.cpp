#include <bits/stdc++.h>
using namespace std;

/*
Given integers M and N, write a program that counts
how many positive integer pairs (a, b)
satisfy the following conditions:

a + b = M
a XOR b = N
*/

int countPairs(int M, int N){
    int count = 0;

    for(int i=0;i<=M;i++){
        if((i^(M-i)) == N){
            count++;
        }
    }

    return count;
}

// main function
int main(){
    cout << countPairs(100, 100) << "\n";
    return 0;
}
