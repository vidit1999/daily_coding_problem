#include <bits/stdc++.h>
using namespace std;

/*
Write a function that returns the bitwise AND of all integers between M and N, inclusive.
*/

int andOfAll(int M, int N){
	int res = M;
	for(int i=M;i<=N;i++){
		res &= i;
		if(res == 0)
			return 0;
	}
	return res;
}

// main function
int main(){
	cout << andOfAll(10, 15) << "\n";
	cout << andOfAll(10, 20) << "\n";
	return 0;
}