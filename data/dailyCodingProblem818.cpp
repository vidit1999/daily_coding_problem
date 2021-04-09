#include <bits/stdc++.h>
using namespace std;

/*
The Sieve of Eratosthenes is an algorithm used to generate
all prime numbers smaller than N. The method is to take
increasingly larger prime numbers, and mark their multiples as composite.

For example, to find all primes less than 100, we would
first mark [4, 6, 8, ...] (multiples of two), then [6, 9, 12, ...]
(multiples of three), and so on. Once we have done this for all
primes less than N, the unmarked numbers that remain will be prime.

Implement this algorithm.

Bonus: Create a generator that produces primes indefinitely
(that is, without taking N as an input).
*/

// Sieve of Eratosthenes
vector<int> sieveEratosthenes(int n){
    vector<bool> sieve(n, true);
    vector<int> ans;

    sieve[0] = sieve[1] = false;

    for(int i=2; i<n; i++){
        if(sieve[i]){
            ans.push_back(i);
            for(int j=2; i*j<n; j++){
                sieve[i*j] = false;
            }
        }
    }

    return ans;
}

// prime generator
void primeGenerator(){
    int num = 2;

    while(true){
        bool is_prime = true;
        for(int i=2; i<=num/2; i++){
            if(num%i == 0){
                is_prime = false;
                break;
            }
        }
        if(is_prime) cout << num << "\n";
        num++;
    }
}

// main function
int main(){
    for(int i : sieveEratosthenes(50)){
        cout << i << "\n";
    }
    primeGenerator();
    return 0;
}
