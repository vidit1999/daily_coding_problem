#include <bits/stdc++.h>
using namespace std;

/*
Find the maximum of two numbers without using any
if-else statements, branching, or direct comparisons.
*/

int maxNum(int x, int y){
	return x - ((x-y) & ((x-y) >> 31));
}

// main function
int main(){
	int x = 5, y = 6;
	cout << maxNum(x, y) << "\n";
	return 0;
}