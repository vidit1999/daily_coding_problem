#include <bits/stdc++.h>
using namespace std;


/*
Write a function that returns the bitwise AND of all integers between M and N, inclusive.
*/

int getMsb(int num){
	int msb_count = -1;
	
	while(num){
		num >>= 1;
		msb_count++;
	}
	
	return msb_count;
}

int countAndRange(int m, int n){
	int ans = 0;
	
	while(m && n){
		int msb_count1 = getMsb(m);
		int msb_count2 = getMsb(n);
		
		if(msb_count1 != msb_count2){
			return ans;
		}
		
		int msb_val = (1 << msb_count1);
		ans += msb_val;
		
		m -= msb_val;
		n -= msb_val;
	}
	
	return ans;
}

// main function
int main(){
	int m = 10, n = 15;
	cout << countAndRange(m, n) << "\n";
	return 0;
}