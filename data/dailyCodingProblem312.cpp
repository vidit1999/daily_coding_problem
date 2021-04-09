#include <bits/stdc++.h>
using namespace std;

/*
You are given a 2 x N board, and instructed to completely cover the board with the following shapes:

Dominoes, or 2 x 1 rectangles.
Trominoes, or L-shapes.
For example, if N = 4, here is one possible configuration, where A is a domino, and B and C are trominoes.

A B B C
A B C C
Given an integer N, determine in how many ways this task is possible.
*/

int countPossibleWays(int n){
	int a[n+1], b[n+1];
	a[0] = a[1] = 1;
	b[0] = b[1] = 0;
	
	for(int i=2;i<=n;i++){
		a[i] = a[i-1] + a[i-2] + 2*b[i-1];
		b[i] = a[i-2] + b[i-2];
	}
	
	return a[n];
}

// main function
int main(){
	cout << countPossibleWays(3) << "\n";
	return 0;
}