#include <bits/stdc++.h>
using namespace std;

/*
A number is considered perfect if its digits sum up to exactly 10.

Given a positive integer n, return the n-th perfect number.

For example, given 1, you should return 19. Given 2, you should return 28.
*/

int nThPerfect(int n){
	int nth_elem = 19 + (n-1)*9;
	int extras = int(log10(nth_elem)) - 1;
	return (nth_elem + 9*extras); 
}

// main function
int main(){
	for(int i=1; i<15; i++)
		cout << i << " --> " << nThPerfect(i) << "\n";
	return 0;
}