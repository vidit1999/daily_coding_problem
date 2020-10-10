#include <bits/stdc++.h>
using namespace std;

/*
The Sieve of Eratosthenes is an algorithm used to generate all prime numbers smaller than N.
The method is to take increasingly larger prime numbers, and mark their multiples as composite.

For example, to find all primes less than 100, we would first mark
[4, 6, 8, ...] (multiples of two), then [6, 9, 12, ...] (multiples of three), and so on.
Once we have done this for all primes less than N,
the unmarked numbers that remain will be prime.

Implement this algorithm.

Bonus: Create a generator that produces primes indefinitely
(that is, without taking N as an input).
*/

vector<int> sieveEratosthenes(int n){
	vector<int> arr(n, true);
	arr[0] = false, arr[1] = false;

	for(int i=2; i<n; i++){
		if(arr[i]){
			for(int j=2; i*j<n; j++){
				arr[i*j] = false;
			}
		}
	}

	vector<int> ans;

	for(int i=0; i<n; i++){
		if(arr[i]) ans.push_back(i);
	}

	return ans;
}

// main function
int main(){
	for(int i : sieveEratosthenes(50)){
		cout << i << "\n";
	}
	return 0;
}