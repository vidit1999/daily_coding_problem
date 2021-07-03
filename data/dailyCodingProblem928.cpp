#include <bits/stdc++.h>
using namespace std;

/*
A number is considered perfect if its digits sum up to exactly 10.

Given a positive integer n, return the n-th perfect number.

For example, given 1, you should return 19. Given 2, you should return 28.
*/

int nThPerfect(int n){
    for(int i=19; ; i+=9){
        int sum = 0;

        for(int x=i; x>0; x/=10){
            sum += x%10;
        }

        if(sum == 10) n--;

        if(n == 0){
            return i;
        }
    }
    return -1;
}

// main function
int main(){
    for(int i=1; i<=20; i++){
        cout << nThPerfect(i) << "\n";
    }

    return 0;
}