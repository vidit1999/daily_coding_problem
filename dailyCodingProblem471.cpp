#include <bits/stdc++.h>
using namespace std;

/*
Total number of possible Binary Search Trees with n different keys
(countBST(n)) = Catalan number Cn = (2n)! / ((n + 1)! * n!) 
*/

// calculate factorial of n
unsigned long factorial(int n){
    if(n==0 || n==1)
        return 1;
    unsigned long fact = 1;
    for(int i=2;i<=n;i++)
        fact *= i;
    return fact;
}

// binomial coefficient nCr
unsigned long binCoeff(int N, int r){
    unsigned long res = 1;
    if(r > N-r)
        r = N-r;
    for(int i=0;i<r;i++){
        res *= (N-i);
        res /= (i+1); 
    }
    return res;
}

// calculate n-th catalan number
unsigned long countBST(int n){
    return binCoeff(2*n,n)/(n+1);
}

// mainfunction
int main(){
    for(int i=0;i<10;i++)
        cout << countBST(i) << "\n";
    return 0;
}