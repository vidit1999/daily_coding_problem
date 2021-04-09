#include <bits/stdc++.h>
using namespace std;

/*
Using a function rand7() that returns an integer from 1 to 7 (inclusive)
with uniform probability, implement a function rand5() that returns an
integer from 1 to 5 (inclusive).
*/

int rand7(){
	return rand()%7 + 1;
}

int rand5(){
	int num;
	
	do{
		num = rand7();
	}while(num > 5);
	
	return num;
}

// main function
int main(){
	srand(time(0));
	unordered_map<int, int> num_count;
	
	for(int i=0; i<10000; i++){
		num_count[rand5()]++;
	}
	
	for(auto it : num_count){
		cout << it.first << " : " << it.second << "\n";
	}
	return 0;
}