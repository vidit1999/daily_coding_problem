#include <bits/stdc++.h>
using namespace std;

/*
Write a program that checks whether an integer is a palindrome.
For example, 121 is a palindrome, as well as 888. 678 is not a
palindrome. Do not convert the integer into a string.
*/

bool checkPalindrome(int number){
    number = abs(number);

    int divisor = 1;

    while(number/divisor >= 10)
        divisor *= 10;

    while(number){
        if(number/divisor != number%10)
            return false;
        number = (number%divisor)/10;
        divisor /= 100;
    }

    return true;
}

// main function
int main(){
    cout << checkPalindrome(1001) << "\n";
    cout << checkPalindrome(121) << "\n";
    cout << checkPalindrome(888) << "\n";
    cout << checkPalindrome(678) << "\n";
    cout << checkPalindrome(1) << "\n";
    cout << checkPalindrome(0) << "\n";
    cout << checkPalindrome(12) << "\n";
    return 0;
}
