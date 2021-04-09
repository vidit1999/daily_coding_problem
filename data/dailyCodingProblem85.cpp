#include <bits/stdc++.h>
using namespace std;

/*
Given three 32-bit integers x, y, and b, return x if b is 1 and y if b is 0,
using only mathematical or bit operations. You can assume b can only be 1 or 0.
*/

int operation(int x, int y, int b){
	b = -b;
	return (x & b) | (y & ~b);
}

// main function
int main(){
	cout << operation(10, 20, 1) << "\n";
	cout << operation(10, 20, 0) << "\n";
	return 0;
}