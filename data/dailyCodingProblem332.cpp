#include <bits/stdc++.h>
using namespace std;

/*
Given integers M and N, write a program that counts how many
positive integer pairs (a, b) satisfy the following conditions:

a + b = M
a XOR b = N
*/

pair<int, int> sumXor(unsigned long M, unsigned long N){
	unsigned long A = (M - N)/2;
	int a = 0, b = 0;
	
	for(int i=0;i<8*sizeof(M);i++){
		unsigned long Ni = N & (1 << i), Ai = A & (1 << i);
		if(Ni > 0 && Ai == 0){
			a |= (1 << i);
		}
		else if(Ni == 0 && Ai > 0){
			a |= (1 << i);
			b |= (1 << i);
		}
		else if(Ni == 1 && Ai == 1){
			return {-1, -1};
		}
	}
	
	return {a, b};
}

// main function
int main(){
	auto ans = sumXor(17, 13);
	cout << ans.first << " -- " << ans.second << "\n";
	return 0;
}