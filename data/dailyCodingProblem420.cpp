#include <bits/stdc++.h>
using namespace std;

/*
A number is considered perfect if its digits sum up to exactly 10.

Given a positive integer n, return the n-th perfect number.

For example, given 1, you should return 19. Given 2, you should return 28.
*/

int perfectNumber(int n){
	int nthElem = 19 + (n-1)*9;
	int tenMuls = int(log10(nthElem)) - 1;
	
	return nthElem + 9*tenMuls;
}

// main function
int main(){
	for(int i=1;i<=10;i++)
		cout << perfectNumber(i) << "\n";
	return 0;
}