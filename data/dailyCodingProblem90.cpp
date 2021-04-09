#include <bits/stdc++.h>
using namespace std;

/*
Given an integer n and a list of integers l,
write a function that randomly generates a
number from 0 to n-1 that isn't in l (uniform).
*/

int randMissing(int n, unordered_set<int>& num_l){
	// unordered_set<int> num_l(l.begin(), l.end());
	int num;

    do{
        num = rand()%n;
    }while(num_l.find(num) != num_l.end());

    return num;
}

// main function
int main(){
    srand(time(0));

    unordered_set<int> num_l = {0, 5, 9, 8};
    unordered_map<int, int> num_occ_count;
    
    for(int i=0; i<600; i++){
        num_occ_count[randMissing(10, num_l)]++;
    }

    for(auto it : num_occ_count){
        cout << it.first << ", " << it.second << "\n";
    }


	return 0;
}