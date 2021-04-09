#include <bits/stdc++.h>
#define M 4
#define N 4
using namespace std;

/*
Suppose you are given a table of currency exchange rates, represented as a 2D array.
Determine whether there is a possible arbitrage: that is, whether there is some
sequence of trades you can make, starting with some amount A of any currency,
so that you can end up with some amount greater than A of that currency.

There are no transaction costs and you can trade fractional quantities.
*/


// soln : https://www.dailycodingproblem.com/blog/how-to-find-arbitrage-opportunities-in-python/
bool isPossibleArbitrage(int table[M][N]){
	float transformedTable[M][N];
	
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			transformedTable = -log(table[i][j]);
	
	int source = 0;
	int minDist[M] = {INT_MAX};
	minDist[source] = 0;
	
	for(int i=0;i<M-1;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
				if(minDist[k] > minDist[j] + transformedTable[j][k])
					minDist[k] = minDist[j] + transformedTable[j][k];
			}
		}
	}
	
	for(int j=0;j<M;j++){
		for(int k=0;k<N;k++){
			if(minDist[k] > minDist[j] + transformedTable[j][k])
				return true;
		}
	}
	
	return false;
}

// main function
int main(){
	return 0;
}