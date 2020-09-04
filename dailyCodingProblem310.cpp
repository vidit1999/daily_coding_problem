#include <bits/stdc++.h>
using namespace std;

/*
Write an algorithm that finds the total number of set bits in all integers between 1 and N.
*/

int countSetBits(int n){
	int count = 0;
	while(n){
		count += (n & 1);
		n >>= 1;
	}
	return count;
}

int totalSetBits(int n){
	int total = 0;
	
	for(int i=1;i<=n;i++)
		total += countSetBits(i);
	
	return total;
}

// main function
int main(){
	return 0;
}