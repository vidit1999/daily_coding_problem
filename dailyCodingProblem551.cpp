#include <bits/stdc++.h>
#define percentage 65
using namespace std;

/*
Assume you have access to a function toss_biased() which returns 0 or 1 with a
probability that's not 50-50 (but also not 0-100 or 100-0).
You do not know the bias of the coin.

Write a function to simulate an unbiased coin toss.
*/

// return 0.38, seed 0
int toss_biased(){
	if(rand()%100 < percentage)
		return 0;
	return 1;
}

int unbiasedCoin(){
	int res1 = toss_biased(), res = toss_biased();
	
	if(res1 != res2)
		return res1;
	
	return unbiasedCoin();
}

// main function
int main(){
	return 0;
}