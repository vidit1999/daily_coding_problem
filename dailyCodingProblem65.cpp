#include <bits/stdc++.h>
#define N 4
#define M 5
using namespace std;

/*
Given a N by M matrix of numbers, print out the matrix in a clockwise spiral.

For example, given the following matrix:

[[1,  2,  3,  4,  5],
 [6,  7,  8,  9,  10],
 [11, 12, 13, 14, 15],
 [16, 17, 18, 19, 20]]
You should print out the following:

1
2
3
4
5
10
15
20
19
18
17
16
11
6
7
8
9
14
13
12
*/

void printSpiral(int mat[N][M], int i, int j, int k, int l){
	if(i >= k or j >= l) return;
	
	for(int p=i; p<l; p++)
		cout << mat[i][p] << "\n";
	
    for(int p=i+1; p<k; p++)
		cout << mat[p][l-1] << "\n";
	
    if(k-1 != i)
		for(int p=l-2; p>=j; p--)
			cout << mat[k-1][p] << "\n";
	
    if(l-1 != j)
		for(int p=k-2; p>i; p--)
			cout << mat[p][j] << "\n";
	
	printSpiral(mat, i+1, j+1, k-1, l-1);
}

// main function
int main(){
	int mat[N][M] = {
		{1,  2,  3,  4,  5},
		{6,  7,  8,  9,  10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20}
	};
	
	printSpiral(mat, 0, 0, N, M);
	
	return 0;
}