#include <bits/stdc++.h>
#define KAPREKAR_CONSTANT 6174
using namespace std;

/*
The number 6174 is known as Kaprekar's contant,
after the mathematician who discovered an associated property:
for all four-digit numbers with at least two distinct digits,
repeatedly applying a simple procedure eventually results in this value.

The procedure is as follows:

For a given input x, create two new numbers that consist of the digits in x in ascending and descending order.
Subtract the smaller number from the larger number.
For example, this algorithm terminates in three steps when starting from 1234:

4321 - 1234 = 3087
8730 - 0378 = 8352
8532 - 2358 = 6174

Write a function that returns how
many steps this will take for a given input N.
*/

string makeFourDigit(string number){
    if(number.length() < 4){
        int n = number.length();
        for(int i=0;i<4-n;i++)
            number += '0';
    }
    return number;
}

int kaprekarCount(int num){
    int count = 0;
    
    while(num != KAPREKAR_CONSTANT && count < 10){
        string min_num_str = to_string(num);
        sort(min_num_str.begin(), min_num_str.end());
        string max_num_str = string(min_num_str.rbegin(), min_num_str.rend());
        
        num = stoi(makeFourDigit(max_num_str)) - stoi(min_num_str);
        
        count++;
    }

    return count;
}

// main function
int main(){
    cout << kaprekarCount(1000) << "\n";
    cout << kaprekarCount(1167) << "\n";
    cout << kaprekarCount(1234) << "\n";
    cout << kaprekarCount(9812) << "\n";
	return 0;
}