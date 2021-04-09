#include <bits/stdc++.h>
#define N 4
using namespace std;

/*
At a party, there is a single person who everyone knows,
but who does not know anyone in return (the "celebrity").
To help figure out who this is, you have access to an O(1)
method called knows(a, b), which returns True
if person a knows person b, else False.

Given a list of N people and the above operation,
find a way to identify the celebrity in O(N) time.
*/

int mat[N][N] = {
	{0, 0, 1, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 0},
	{0, 0, 1, 0}
};

bool knows(int a, int b)
{
	return mat[a][b];
}

int identifyCeleb()
{
	int a = 0, b = N-1;
	
	while(a < b){
		if(knows(a, b))
			a++;
		else
			b--;
	}
	
	for(int i=0;i<N;i++){
		if(i!=a && (!knows(i, a) || knows(a, i)))
			return -1;
	}
	
	return a;
}
// main function
int main(){
	cout << identifyCeleb() << "\n";
	return 0;
}