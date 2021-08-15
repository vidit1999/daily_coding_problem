#include <bits/stdc++.h>
using namespace std;

/*
Write an algorithm that finds the total number of set bits in all integers between 1 and N
*/

// count the number of set bits in a number
int countSetBits(int num){
	int count = 0;
	while(num){
		count += (num & 1);
		num /= 2;
	}
	return count;
}

// count the total number of set bits
// from number 1 to n
int totalSetBitCount(int n){
	int count = 0;
	for(int i=1;i<=n;i++){
		count += countSetBits(i);
	}
	return count;
}

// main function
int main(){
	int n = 17;
	cout << totalSetBitCount(n) << "\n";
	return 0;
}