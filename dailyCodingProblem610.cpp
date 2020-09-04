#include <bits/stdc++.h>
using namespace std;

/*
Implement division of two positive integers without using the division,
multiplication, or modulus operators. Return the quotient as an integer,
ignoring the remainder.
*/

int divQuotient(int dividend, int divisior){
	if(divisior == 0) return INT_MAX;
	
	int sign = ((dividend < 0) ^ (divisior < 0))? -1 : 1;
	
	dividend = abs(dividend);
	divisior = abs(divisior);
	int quotient = 0;
	
	while(dividend >= divisior){
		quotient++;
		dividend -= divisior;
	}
	
	return sign * quotient;
}

// main function
int main(){
	cout << divQuotient(10, 3) << "\n";
	cout << divQuotient(43, -8) << "\n";
	return 0;
}