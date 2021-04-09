#include <bits/stdc++.h>
using namespace std;

/*
Given a 32-bit positive integer N, determine whether it is a power of four in faster than O(log N) time.
*/

bool isPower4(unsigned int n){
	return (n != 0) && !(n & (n-1)) && !(n & 0xAAAAAAAA);
}

// main function
int main(){
	if(isPower4(64))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}