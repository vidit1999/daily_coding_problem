#include <bits/stdc++.h>
using namespace std;

/*
At a party, there is a single person who everyone knows,
but who does not know anyone in return (the "celebrity").

To help figure out who this is, you have access to an O(1) method called knows(a, b),
which returns True if person a knows person b, else False.

Given a list of N people and the above operation, find a way to identify the celebrity in O(N) time.
*/

/*
If a knows b then a cannot be celebrity, discard a.
If a does not know b then b cannot be celebrity, discard b,
Repeat the above process.
*/

int MATRIX[4][4] = {
	{0,0,1,0},
	{0,0,1,0},
	{0,0,0,0},
	{0,0,1,0}
};

bool knows(int a, int b){
	return MATRIX[a][b];
}

int celebrityIdentify(int n){
	int a = 0;
	int b = n-1;
	
	while(a < b){
		if(knows(a,b))
			a++;
		else
			b--;
	}
	return a;
}

// main function
int main(){
	int n = 4;
	cout << celebrityIdentify(n) << "\n";
	return 0;
}