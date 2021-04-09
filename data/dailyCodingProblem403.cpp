#include <bits/stdc++.h>
using namespace std;

/*
Using a function rand5() that returns an integer from 1 to 5 (inclusive) with uniform probability,
implement a function rand7() that returns an integer from 1 to 7 (inclusive).
*/

int rand5(){return rand()%5 + 1;}

int rand7(){
	int var[5][5] = {
		{1, 2, 3, 4, 5},
		{6, 7, 1, 2, 3},
		{4, 5, 6, 7, 1},
		{2, 3, 4, 5, 6},
		{7, 0, 0, 0, 0}
	};
	
	int result = 0;
	while(result == 0){
		int i = rand5(), j = rand5();
		result = var[i-1][j-1];
	}
	
	return result;
}

// main function
int main(){
	srand(time(0));
	for(int i=0;i<10;i++)
		cout << rand7() << "\n";
	return 0;
}