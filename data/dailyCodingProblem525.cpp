#include <bits/stdc++.h>
#define R 4
#define C 5
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

void printSpiral(int arr[R][C], int i, int j, int m, int n){
	if(i >= m || j >= n)
		return;
	for(int p=i;p<n;p++)
		cout << arr[i][p] << "\n";
	
	for(int p=i+1;p<m;p++)
		cout << arr[p][n-1] << "\n";
	
	if((m-1) != i)
		for(int p=n-2;p>=j;p--)
			cout << arr[m-1][p] << "\n";
	if((n-1) != j)
		for(int p=m-2;p>i;p--)
			cout << arr[p][j] << "\n";
	printSpiral(arr, i+1, j+1, m-1, n-1);
}

// main function
int main(){
	int arr[R][C] = {{1,  2,  3,  4,  5},
					 {6,  7,  8,  9,  10},
					 {11, 12, 13, 14, 15},
					 {16, 17, 18, 19, 20}};
	printSpiral(arr, 0, 0, R, C);
	return 0;
}