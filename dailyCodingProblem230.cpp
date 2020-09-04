#include <bits/stdc++.h>
using namespace std;

/*
You are given N identical eggs and access to a building with k floors.
Your task is to find the lowest floor that will cause an egg to break,
if dropped from that floor. Once an egg breaks, it cannot be dropped again.
If an egg breaks when dropped from the xth floor, you can assume
it will also break when dropped from any floor greater than x.

Write an algorithm that finds the minimum number of trial drops it will take,
in the worst case, to identify this floor.

For example, if N = 1 and k = 5, we will need to try dropping the egg at every floor,
beginning with the first, until we reach the fifth floor, so our solution will be 5.
*/

int minEggDrop(int n, int k){
	int eggDrop[n+1][k+1];
	
	for(int i=1; i<=n; i++){
		eggDrop[i][0] = 0; // zero floor no trial
		if(k > 0) eggDrop[i][1] = 1; // one floor one trial
	}
	
	for(int i=1; i<=k; i++){
		eggDrop[1][i] = i; // one egg i floog i trial
	}
	
	for(int i=2; i<=n; i++){
		for(int j=2; j<=k; j++){
			eggDrop[i][j] = INT_MAX;
			for(int x=1; x<=j; x++){
				int res = 1 + max(eggDrop[i][j-x], eggDrop[i-1][x-1]);
				if(res < eggDrop[i][j])
					eggDrop[i][j] = res;
			}
		}
	}
	
	return eggDrop[n][k];
}

// main function
int main(){
	cout << minEggDrop(2, 36) << "\n";
	cout << minEggDrop(1, 5) << "\n";
	return 0;
}