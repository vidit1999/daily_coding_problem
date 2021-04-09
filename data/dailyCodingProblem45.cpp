#include <bits/stdc++.h>
using namespace std;

/*
Using a function rand5() that returns an integer from 1 to 5 (inclusive) with uniform probability,
implement a function rand7() that returns an integer from 1 to 7 (inclusive).
*/

int rand5(){
	return rand()%5 + 1;
}

int rand7(){
	int table[5][5] = {
		{1, 2, 3, 4, 5},
		{6, 7, 1, 2, 3},
		{4, 5, 6, 7, 1},
		{2, 3, 4, 5, 6},
		{7, 0, 0, 0, 0}
	};
	
	int num;
	
	do{
		num = table[rand5()-1][rand5()-1];
	}while(num == 0);
	
	return num;
}

// main fucntion
int main(){
	srand(time(0));
	
	unordered_map<int, int> number_count;
	
	for(int i=0; i<7000; i++) number_count[rand7()]++;
	
	for(auto it : number_count){
		cout << it.first << " --> " << it.second << "\n";
	}
	
	return 0;
}