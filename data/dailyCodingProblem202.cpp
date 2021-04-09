#include <bits/stdc++.h>
using namespace std;

/*
Write a program that checks whether an integer is a palindrome.
For example, 121 is a palindrome, as well as 888. 678 is not a palindrome.
Do not convert the integer into a string.
*/

bool isPalindromeNumber(int number){
	int divisor = 1;
	while(number/divisor >= 10) divisor *= 10;
	
	while(number){
		int last_digit = number%10;
		int first_digit = number/divisor;
		
		if(last_digit != first_digit) return false;
		
		number = (number%divisor)/10;
		divisor /= 100;
	}
	
	return true;
}

// main function
int main(){
	if(isPalindromeNumber(12321))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}