#include <bits/stdc++.h>
using namespace std;

/*
A regular number in mathematics is defined as one which evenly divides some power of 60.
Equivalently, we can say that a regular number is one whose only prime divisors are 2, 3, and 5.

These numbers have had many applications, from helping ancient
Babylonians keep time to tuning instruments according to the diatonic scale.

Given an integer N, write a program that returns, in order, the first N regular numbers.
*/


int nThRegularNumber(int n){
	int numbers[n];
	int i2 = 0, i3 = 0, i5 = 0;
	int next_factor_2 = 2;
	int next_factor_3 = 3;
	int next_factor_5 = 5;
	int next_reg_num = 1;
	
	numbers[0] = next_reg_num;
	
	for(int i=1;i<n;i++){
		next_reg_num = min(next_factor_2, min(next_factor_3, next_factor_5));
		numbers[i] = next_reg_num;
		
		if(next_reg_num == next_factor_2){
			i2++;
			next_factor_2 = numbers[i2]*2;
		}
		if(next_reg_num == next_factor_3){
			i3++;
			next_factor_3 = numbers[i3]*3;
		}
		if(next_reg_num == next_factor_5){
			i5++;
			next_factor_5 = numbers[i5]*5;
		}
	}
	
	return next_reg_num;
}

// main function
int main(){
	for(int n=1;n<=20;n++)
		cout << nThRegularNumber(n) << "\n";
	return 0;
}