#include <bits/stdc++.h>
using namespace std;

/*
Given an integer n, find the next biggest integer with the same number of 1-bits on.
For example, given the number 6 (0110 in binary), return 9 (1001).
*/

unsigned int snoob(unsigned int n){
	unsigned int rightOne, nextHigherOneBit, rightOnesPattern, next = 0;
	
	if(n){
		rightOne = n & -(signed)n;
		nextHigherOneBit = n + rightOne;
		rightOnesPattern = n ^ nextHigherOneBit;
		rightOnesPattern = rightOnesPattern/rightOne;
		rightOnesPattern >>= 2;
		next = nextHigherOneBit | rightOnesPattern;
	}
	
	return next;
}

// main function
int main(){
	cout<< snoob(6) << "\n";
	return 0;
}