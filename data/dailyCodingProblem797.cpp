#include <bits/stdc++.h>
using namespace std;

/*
Given an even number (greater than 2), return
two prime numbers whose sum will be equal to the given number.

A solution will always exist. See Goldbach’s conjecture.

Example:

Input: 4
Output: 2 + 2 = 4
If there are more than one solution possible,
return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c, d] is another solution with c <= d, then

[a, b] < [c, d]
If a < c OR a==c AND b < d.
*/

pair<int, int> goldbachConj(int n){
    if(n%2 != 0) return {-1, -1};
    
    // sieve of eratosthenes
    bool sieve[n+1];
    memset(sieve, true, sizeof(sieve));
    
    for(int i=2; i*i<=n; i++){
        if(sieve[i]){
            for(int j=i*i; j<=n; j+=i){
                sieve[j] = false;
            }
        }
    }
    
    // prime number pair
    for(int i=2; i<n; i++){
        if(sieve[i] && sieve[n-i]){
            return {i, n-i};
        }
    }
    
    return {-1, -1};
}

// main function
int main(){
    srand(time(0));
    
    for(int i=0; i<5; i++){
        int n = (rand()%100 + 2)*2;
        cout << n << ", ";
        auto ans = goldbachConj(n);
        cout << ans.first << ", " << ans.second << "\n";
    }
    return 0;
}