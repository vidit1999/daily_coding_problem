#include <bits/stdc++.h>
using namespace std;

/*
You have n fair coins and you flip them all at the same time. Any that come up tails you set aside.
The ones that come up heads you flip again. How many rounds do you expect to play before only one coin remains?

Write a function that, given n, returns the number of rounds you'd expect to play until one coin remains.
*/

int numRounds(int n){
	int count = 0;
	while(n > 1){
		int num_tosses = n;
		for(int i=0;i<num_tosses;i++){
			if(rand()%2 == 0)
				n--;
		}
		count++;
	}
	
	return count;
}

// main function
int main(){
	srand(time(0));
	cout << numRounds(100) << "\n";
	return 0;
}