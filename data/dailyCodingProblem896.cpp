#include <bits/stdc++.h>
using namespace std;

/*
Implement division of two positive integers without using the division,
multiplication, or modulus operators. Return the quotient as an integer,
ignoring the remainder.
*/

int divisionQuotient(int dividend, int divisior){
    int sign = ((dividend < 0) ^ (divisior < 0)) ? -1 : 1;
    int quotient = 0;

    dividend = abs(dividend);
    divisior = abs(divisior);

    while(dividend >= divisior){
        dividend -= divisior;
        quotient++;
    }

    return sign*quotient;
}

// main function
int main(){
    cout << divisionQuotient(10, 3) << "\n";
    cout << divisionQuotient(-10, 3) << "\n";
    cout << divisionQuotient(10, -3) << "\n";
    cout << divisionQuotient(-10, -3) << "\n";
    return 0;
}