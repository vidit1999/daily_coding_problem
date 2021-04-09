#include <bits/stdc++.h>
using namespace std;

/*
Write a program that checks whether an integer is a palindrome.
For example, 121 is a palindrome, as well as 888. 678 is not a palindrome.
Do not convert the integer into a string.
*/

bool isPalindrome(int number){
	int divisor = 1;
	while(number/divisor >= 10)
		divisor *= 10;
	
	while(number){
		int leadingDigit = number/divisor;
		int trailingDigit = number%10;
		if(leadingDigit != trailingDigit)
			return false;
		number = (number%divisor)/10;
		divisor /= 100;
	}
	return true;
}

void testFunc(int number){
	if(isPalindrome(number))
		cout << "Yes\n";
	else
		cout << "No\n";
}

// main function
int main(){
	testFunc(0);
	testFunc(121);
	testFunc(888);
	testFunc(1);
	testFunc(678);
	testFunc(110);
	return 0;
}