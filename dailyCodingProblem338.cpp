#include <bits/stdc++.h>
using namespace std;

/*
Given an integer n, find the next biggest integer with the same number of 1-bits on.
For example, given the number 6 (0110 in binary), return 9 (1001).
*/

long preprocessed[32];

int count_set_bits(int number){
    int count = 0;
    for(int i=0;i<32;i++){
        if(preprocessed[i] & number)
            count++;
    }
    return count;
}

int next_int_same_set(int number){
	int count_set = count_set_bits(number);

    while(1){
        if(count_set_bits(++number) == count_set)
            return number;
    }

    return 0;
}

// main function
int main(){
    for(int i=0;i<32;i++) preprocessed[i] = (1ll << i);

    cout << next_int_same_set(6) << "\n";
    cout << next_int_same_set(156) << "\n";
    cout << next_int_same_set(16777215) << "\n";

	return 0;
}