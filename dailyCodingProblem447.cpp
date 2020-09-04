#include <bits/stdc++.h>
using namespace std;

/*
Implement integer exponentiation. That is, implement the pow(x, y) function,
where x and y are integers and returns x^y.

Do this faster than the naive method of repeated multiplication.

For example, pow(2, 10) should return 1024.
*/

int power(int x,int y){
	int res = 1;
	
	while(y > 0){
		if(y%2 != 0)
			res *= x;
		y /= 2;
		x *= x;
	}
	
	return res;
}

// main function
int main(){
	cout <<power(2, 10) << "\n";
	return 0;
}