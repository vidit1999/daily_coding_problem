#include <bits/stdc++.h>
using namespace std;

/*
Given an unsigned 8-bit integer, swap its even and odd bits.
The 1st and 2nd bit should be swapped,
the 3rd and 4th bit should be swapped, and so on.

For example, 10101010 should be 01010101.
11100010 should be 11010001.

Bonus: Can you do this in one line?
*/

unsigned int swapOddEven(unsigned int num){
	return (((num&0xAA) >> 1) | ((num&0x55) << 1));
}

// main function
int main(){
	cout << swapOddEven(0b10101010) << "\n";
	cout << swapOddEven(0b11100010) << "\n";
	return 0;
}