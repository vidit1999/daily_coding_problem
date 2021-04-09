#include <bits/stdc++.h>
using namespace std;

/*
Implement the function fib(n), which returns the nth
number in the Fibonacci sequence, using only O(1) space.
*/

int fib(int n){
	int a = 0, b = 1;
	if(n == 0) return a;
	
	for(int i=2; i<=n; i++){
		int next = a+b;
		a = b;
		b = next;
	}
	
	return b;
}

// main function
int main(){
	for(int i=0; i<=10; i++)
		cout << fib(i) << "\n";
	return 0;
}