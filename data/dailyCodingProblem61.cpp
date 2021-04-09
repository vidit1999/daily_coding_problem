#include <bits/stdc++.h>
using namespace std;

/*
Implement integer exponentiation. That is, implement the pow(x, y)
function, where x and y are integers and returns x^y.

Do this faster than the naive method of repeated multiplication.

For example, pow(2, 10) should return 1024.
*/

int power(int x, int y){
	if(y == 0) return 1;
	
	int temp = power(x, y/2);
	
	if(y%2 == 0)
		return temp*temp;
	else
		return x*temp*temp;
}

// main function
int main(){
	cout << power(2, 10) << "\n";
	return 0;
}