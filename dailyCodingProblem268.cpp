#include <bits/stdc++.h>
using namespace std;

/*
Given a 32-bit positive integer N, determine whether it
is a power of four in faster than O(log N) time.
*/

bool isPowerOf4(int number){
	return (
		(number != 0) &&
		!(number & (number-1)) &&
		!(number & 0xAAAAAAAA)
	);
}

// main function
int main(){
	for(unsigned int i : {1, 4, 64, 16, 32, 256})
		if(isPowerOf4(i))
			cout << "Yes\n";
		else
			cout << "No\n";
	return 0;
}