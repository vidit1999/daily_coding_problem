#include <bits/stdc++.h>
using namespace std;

/*
Given a stream of elements too large to store in memory,
pick a random element from the stream with uniform probability.
*/

int selectRandom(int x){
	static int res;
	static int count = 0;
	
	count++;
	if(count == 1)
		res = x;
	else{
		if(rand()%count == count-1)
			res = x;
	}
	return res;
}

// main function
int main(){
	int stream[] = {1,2,3,4,5};
	int n = sizeof(stream)/sizeof(stream[0]);
	
	srand(time(0));
	
	for(int i=0;i<n;i++)
		cout << i+1 << " --- " << selectRandom(stream[i]) << "\n";
	return 0;
}