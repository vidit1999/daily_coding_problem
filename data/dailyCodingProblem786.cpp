#include <bits/stdc++.h>
using namespace std;

/*
Implement integer exponentiation. That is,
implement the pow(x, y) function,
where x and y are integers and returns x^y.

Do this faster than the naive method
of repeated multiplication.

For example, pow(2, 10) should return 1024.
*/

int powFunc(int x, int y){
	int ans = 1;
	
	while(y > 0){
		if(y%2){
			ans *= x;
		}
		
		y /= 2;
		x *= x;
	}
	
	return ans;
}

// main function
int main(){
	cout << powFunc(2, 10) << "\n";
	cout << powFunc(3, 5) << "\n";
	cout << powFunc(4, 3) << "\n";
	return 0;
}