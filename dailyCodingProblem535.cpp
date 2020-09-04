#include <bits/stdc++.h>
using namespace std;

/*
You are given N identical eggs and access to a building with k floors. Your task is to find
the lowest floor that will cause an egg to break, if dropped from that floor.
Once an egg breaks, it cannot be dropped again. If an egg breaks when dropped from
the xth floor, you can assume it will also break when dropped from any floor greater than x.

Write an algorithm that finds the minimum number of trial drops it will take,
in the worst case, to identify this floor.

For example, if N = 1 and k = 5, we will need to try dropping the egg at every floor,
beginning with the first, until we reach the fifth floor, so our solution will be 5.
*/

int eggDrop(int n, int k){
	int eggFloor[n+1][k+1];
	
	for(int i=0;i<=n;i++){
		eggFloor[i][0] = 0;
		eggFloor[i][1] = 1;
	}
	
	for(int i=0;i<=k;i++){
		eggFloor[1][i] = i; 
	}
	
	for(int i=2;i<=n;i++){
		for(int j=2;j<=k;j++){
			eggFloor[i][j] = INT_MAX;
			for(int x=1;x<=j;x++){
				eggFloor[i][j] = min(
					eggFloor[i][j],
					1 + max(eggFloor[i-1][x-1], eggFloor[i][j-x])
				);
			}
		}
	}
	
	return eggFloor[n][k];
}

// main function
int main(){
	cout << eggDrop(2, 36) << "\n";
	cout << eggDrop(1, 5) << "\n";
	return 0;
}