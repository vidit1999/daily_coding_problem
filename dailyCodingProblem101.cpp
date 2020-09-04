#include <bits/stdc++.h>
using namespace std;

/*
Given an even number (greater than 2), return
two prime numbers whose sum will be equal to the given number.

A solution will always exist. See Goldbach’s conjecture.

Example:

Input: 4
Output: 2 + 2 = 4
If there are more than one solution possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b, and [c, d] is another solution with c <= d, then

[a, b] < [c, d]
If a < c OR a==c AND b < d.
*/


void sieveOfEratosthenes(int n, bool isPrime[]){
	isPrime[0] = isPrime[1] = false;
	
	for(int i=2; i<=n; i++) isPrime[i] = true;
	
	for(int i=2; i*i<=n; i++){
		if(isPrime[i]){
			for(int j=i*i; j<=n; j+=i)
				isPrime[j] = false;
		}
	}
}

pair<int, int> goldbachPair(int n){
	bool isPrime[n+1];
	sieveOfEratosthenes(n, isPrime);
	
	for(int i=2; i<n; i++){
		if(isPrime[i] && isPrime[n-i])
			return {i, n-i};
	}
	
	return {-1, -1};
}

void testFunc(vector<int> v){
	for(int n : v){
		auto ans = goldbachPair(n);
		cout << ans.first << ", " << ans.second << "\n";
	}
}

// main function
int main(){
	testFunc({
		4, 74, 1024, 66, 9990
	});
	return 0;
}