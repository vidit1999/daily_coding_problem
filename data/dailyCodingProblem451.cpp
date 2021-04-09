#include <bits/stdc++.h>
using namespace std;

/*
Implement the function fib(n), which returns the nth number in the Fibonacci sequence, using only O(1) space.
*/

int fib(int n){
	if(n == 0)
		return 0;
	int a = 0, b = 1;
	
	for(int i=2;i<=n;i++){
		int c = a + b;
		a = b;
		b = c;
	}
	
	return b;
}

// main function
int main(){
	cout << fib(9) << "\n";
	return 0;
}