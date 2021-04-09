#include <bits/stdc++.h>
using namespace std;

/*
There is an N by M matrix of zeroes. Given N and M, write a function
to count the number of ways of starting at the top-left corner and
getting to the bottom-right corner. You can only move right or down.

For example, given a 2 by 2 matrix, you should return 2,
since there are two ways to get to the bottom-right:

Right, then down
Down, then right

Given a 5 by 5 matrix, there are 70 ways to get to the bottom-right.
*/

int countWays(int n, int m){
	int count[n][m];
	
	for(int i=0; i<n; i++) count[i][0] = 1;
	for(int i=0; i<m; i++) count[0][i] = 1;
	
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			count[i][j] = count[i][j-1] + count[i-1][j];
		}
	}
	
	return count[n-1][m-1];
}

// main function
int main(){
	cout << countWays(2, 2) << "\n";
	cout << countWays(3, 3) << "\n";
	cout << countWays(5, 5) << "\n";
	return 0;
}