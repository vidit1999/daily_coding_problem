#include <bits/stdc++.h>
using namespace std;

/*
There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time.
Given N, write a function that returns the number of unique ways you can climb the staircase.
The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2

What if, instead of being able to climb 1 or 2 steps at a time,
you could climb any number from a set of positive integers X? For example,
if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
*/

// only for case of 1 and 2 steps
// fibonacchi series
int climbStair(int n){
	int a = 1, b = 2;
	
	for(int i=0;i<n-1;i++){
		b = a + b;
		a = b - a;
	}
	
	return a;
}


// general case
int climbStairGeneral(int n, set<int> X){
	vector<int> climb(n+1, 0);
	climb[0] = 1;
	
	for(int i=1;i<=n;i++){
		int count = 0;
		for(int it : X){
			if(i > it)
				count += climb[i-it];
		}
		if(X.find(i) != X.end())
			count++;
		climb[i] = count;
	}
	
	return climb[n];
}

// main function
int main(){
	cout << climbStairGeneral(4, {1, 2, 3}) << "\n";
	return 0;
}