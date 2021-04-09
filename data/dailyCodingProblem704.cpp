#include <bits/stdc++.h>
#define DOTS 10
using namespace std;

/*
One way to unlock an Android phone is through a pattern of swipes across a 1-9 keypad.

For a pattern to be valid, it must satisfy the following:

All of its keys must be distinct.
It must not connect two keys by jumping over a third key, unless that key has already been used.
For example, 4 - 2 - 1 - 7 is a valid pattern, whereas 2 - 1 - 7 is not.

Find the total number of valid unlock patterns of length N, where 1 <= N <= 9.
*/

int totalWays(int curr, int visits[DOTS], int jumps[DOTS][DOTS], int to_touch){
	if(to_touch <= 0){
		return (to_touch == 0)? 1 : 0;
	}
	
	visits[curr] = 1;
	int count = 0;
	
	for(int i=1; i<DOTS; i++){
		if(!visits[i] && (!jumps[i][curr] || visits[jumps[i][curr]]))
			count += totalWays(i, visits, jumps, to_touch-1);
	}
	
	visits[curr] = 0;
	return count;
}

int waysToConnect(int n){
	int jumps[DOTS][DOTS] = {0}, visits[DOTS] = {0};
	
	jumps[1][3] = jumps[3][1] = 2;
	jumps[1][7] = jumps[7][1] = 4;
	jumps[3][9] = jumps[9][3] = 6;
	jumps[7][9] = jumps[9][7] = 8;
	
	jumps[1][9] = jumps[9][1] = \
	jumps[2][8] = jumps[8][2] = \
	jumps[3][7] = jumps[7][3] = \
	jumps[4][6] = jumps[6][4] = 5;
	
	int count = 0;
	count += (
		4*totalWays(1, visits, jumps, n-1) + 
		4*totalWays(2, visits, jumps, n-1) +
		totalWays(5, visits, jumps, n-1)
	);
	
	return count;
}

// main function
int main(){
	for(int i=1; i<=9; i++)
		cout << waysToConnect(i) << "\n";
	return 0;
}