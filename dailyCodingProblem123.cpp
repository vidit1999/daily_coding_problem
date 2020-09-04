#include <bits/stdc++.h>
using namespace std;

/*
Given a string, return whether it represents a number.
Here are the different kinds of numbers:

"10", a positive integer
"-10", a negative integer
"10.1", a positive real number
"-10.1", a negative real number
"1e5", a number in scientific notation

And here are examples of non-numbers:

"a"
"x 1"
"a -2"
"-"
*/

bool isNumber(string num){
	int minus_count = 0, dot_count = 0, e_count = 0, digit_count = 0;
	
	for(int i=0; i<num.length(); i++){
		if(num[i] == '-'){
			if(
				i != 0 || ++minus_count > 1 || num.length() == 1
			)
				return false;
		}
		else if(num[i] == '.'){
			if(
				i == 0 || ++dot_count > 1 || i == num.length()-1
			)
				return false;
		}
		else if(num[i] == 'e'){
			if(
				i == 0 || ++e_count > 1 || i == num.length()-1
			)
				return false;
		}
		else if(num[i] >= '0' && num[i] <= '9')
			digit_count++;
		else
			return false;
	}
	
	return digit_count != 0;
}

// main function
int main(){
	cout << isNumber("10") << "\n";
	cout << isNumber("-10") << "\n";
	cout << isNumber("10.1") << "\n";
	cout << isNumber("-10.1") << "\n";
	cout << isNumber("1e5") << "\n";
	cout << isNumber("a") << "\n";
	cout << isNumber("x 1") << "\n";
	cout << isNumber("a -2") << "\n";
	cout << isNumber("-") << "\n";
	return 0;
}