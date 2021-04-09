#include <bits/stdc++.h>
using namespace std;

#define TEST_NUM 100000

/*
Given an integer n and a list of integers l,
write a function that randomly generates a
number from 0 to n-1 that isn't in l (uniform).
*/

int uniformRandomMissing(unordered_set<int>& lset, int n){
	int random;

	do{
		random = rand()%n;
	}while(lset.find(random) != lset.end());

	return random;
}

void testFunc(unordered_set<int>& lset, int n){
	unordered_map<int, int> num_occ_count;

	for(int i=0; i<TEST_NUM; i++){
		num_occ_count[uniformRandomMissing(lset, n)]++;
	}

	for(auto it : num_occ_count){
		cout << it.first << " --> " << it.second << "\n";
	}
}

// main function
int main(){
	srand(time(0));
	int n = 20;
	unordered_set<int> lset;

	while(lset.size() < n/2){
		lset.insert(rand()%n);
	}

	for(int i : lset){
		cout << i << " ";
	}

	cout << "\n";

	testFunc(lset, n);

	return 0;
}