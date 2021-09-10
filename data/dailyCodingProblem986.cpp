#include <bits/stdc++.h>
using namespace std;

/*
Given an integer n, return the length of the
longest consecutive run of 1s in its binary representation.

For example, given 156, you should return 3.
*/

int longestConsecutiveOne(int num){
	int count = 0;
	
	while(num){
		count++;
		
		num &= (num >> 1);
	}
	
	return count;
}

// main function
int main(){
	cout << longestConsecutiveOne(156) << "\n";
	cout << longestConsecutiveOne(14) << "\n";
	cout << longestConsecutiveOne(222) << "\n";
	return 0;
}