#include <bits/stdc++.h>
using namespace std;

/*
Find the minimum number of coins required to make n cents.

You can use standard American denominations, that is, 1¢, 5¢, 10¢, and 25¢.

For example, given n = 16, return 3 since we can make it with a 10¢, a 5¢, and a 1¢.
*/

int minCoins(int n){
	int count = 0;
	for(int i : {25, 10, 5, 1}){
		count += n/i;
		n %= i;
	}
	return count;
}

// main function
int main(){
	cout << minCoins(16) << "\n";
	return 0;
}