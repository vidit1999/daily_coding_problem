#include <bits/stdc++.h>
using namespace std;

/*
Implement integer division without using the division operator.
Your function should return a tuple of (dividend, remainder) and
it should take two numbers, the product and divisor.

For example, calling divide(10, 3) should return (3, 1)
since the divisor is 3 and the remainder is 1.

Bonus: Can you do it in O(log n) time?
*/

pair<int, int> division(int product, int divisor){
	int sign = ((product < 0) ^ (divisor < 0))? -1 : 1;
	
	product = abs(product), divisor = abs(divisor);
	
	int dividend = 0;
	
	while(product >= divisor){
		product -= divisor;
		dividend++;
	}
	
	return {dividend, product};
}

// main function
int main(){
	auto ans = division(10, 3);
	cout << ans.first << ", " << ans.second << "\n";
	return 0;
}