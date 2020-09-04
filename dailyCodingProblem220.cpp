#include <bits/stdc++.h>
#define MAX_SIZE 100
using namespace std;

/*
In front of you is a row of N coins, with values v1, v1, ..., vn.

You are asked to play the following game. You and an opponent take
turns choosing either the first or last coin from the row, removing
it from the row, and receiving the value of the coin.

Write a program that returns the maximum amount of money you can win
with certainty, if you move first, assuming your opponent plays optimally.
*/

int game(int i, int j, int sum, vector<int> arr, int seen[MAX_SIZE][MAX_SIZE]){
	if(i == j-1) return max(arr[i], arr[j]);
	if(seen[i][j] != -1) return seen[i][j];
	
	seen[i][j] = max(
		(sum - game(i+1, j, sum-arr[i], arr, seen)),
		(sum - game(i, j-1, sum-arr[j], arr, seen))
	);
	
	return seen[i][j];
}

int moneyWin(vector<int> arr){
	int sum = accumulate(arr.begin(), arr.end(), 0);
	int seen[MAX_SIZE][MAX_SIZE];
	
	for(int i=0; i<MAX_SIZE; i++){
		for(int j=0; j<MAX_SIZE; j++)
			seen[i][j] = -1;
	}
	
	return game(0, arr.size()-1, sum, arr, seen);
}

void testFunc(vector<vector<int>> v){
	for(auto arr : v)
		cout << moneyWin(arr) << "\n";
}

// main function
int main(){
	testFunc({
		{ 8, 15, 3, 7 },
		{ 2, 2, 2, 2 },
		{ 20, 30, 2, 2, 2, 10 }
	});
	return 0;
}