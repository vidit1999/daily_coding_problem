#include <bits/stdc++.h>
using namespace std;

/*
Using a function rand7() that returns an integer from 1 to 7 (inclusive)
with uniform probability, implement a function rand5() that
returns an integer from 1 to 5 (inclusive).
*/

int rand7(){ return 1 + rand()%7; }

int rand5(){
	int num;
	do{ num = rand7(); }while(num > 5);
	return num;
}

// main function
int main(){
	int arr[5] = {0};
	
	for(int i=0; i<100000; i++){
		arr[rand5()-1]++;
	}
	
	for(int i=0; i<5; i++)
		cout << i+1 << " --> " << arr[i] << "\n";
	return 0;
}