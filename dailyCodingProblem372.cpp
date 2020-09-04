#include <bits/stdc++.h>
using namespace std;

/*
Write a function that takes a natural number as input and returns the number of digits the input has.

Constraint: don't use any loops.
*/

int countDigits(int number){
	return (number == 0)? 0 : 1 + countDigits(number/10);
}

int countDigits2(int number){
	return floor(log10(number) + 1);
}

// main function
int main(){
	cout << countDigits(12345) << "\n";
	cout << countDigits2(12345) << "\n";
	return 0;
}