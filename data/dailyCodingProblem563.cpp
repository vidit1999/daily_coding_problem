#include <bits/stdc++.h>
#define CHARBIT 4
using namespace std;

/*
Find the maximum of two numbers without using any if-else statements, branching, or direct comparisons.
*/

int max(int x, int y){
	return x - ((x - y) & ((x - y) >> (sizeof(int) * CHARBIT - 1)));
}

// main function
int main(){
	cout << max(10, 14) << "\n";
	cout << max(17, 12) << "\n";
	cout << max(-1, -3) << "\n";
	cout << max(-2, 5) << "\n";
	cout << max(23, 23) << "\n";
	return 0;
}