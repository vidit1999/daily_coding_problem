#include <bits/stdc++.h>
using namespace std;

/*
There are N prisoners standing in a circle, waiting to be executed.
The executions are carried out starting with the kth person,
and removing every successive kth person going clockwise until there is no one left.

Given N and k, write an algorithm to determine where a prisoner should stand in order to be the last survivor.

For example, if N = 5 and k = 2, the order of executions would be [2, 4, 1, 5, 3], so you should return 3.

Bonus: Find an O(log N) solution if k = 2.
*/

// O(n)
int josephus(int n, int k){
	if(n == 1)
		return 1;
	return (josephus(n-1, k) + k - 1) % n + 1;
}

// O(logn) for k = 2
int josephus2(int n){
	int p = 1;
	while(p <= n)
		p *= 2;
	return 2*n - p + 1;
}


// main function
int main(){
	cout << josephus(5, 2) << "\n";
	return 0;
}