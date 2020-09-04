#include <bits/stdc++.h>
using namespace std;

/*
Mastermind is a two-player game in which the first player attempts to guess the secret code of the second.
In this version, the code may be any six-digit number with all distinct digits.

Each turn the first player guesses some number, and the second player responds by saying how many
digits in this number correctly matched their location in the secret code. For example,
if the secret code were 123456, then a guess of 175286 would score two, since 1 and 6 were correctly placed.

Write an algorithm which, given a sequence of guesses and their scores,
determines whether there exists some secret code that could have produced them.

For example, for the following scores you should return True, since they correspond to the secret code 123456:

{175286: 2, 293416: 3, 654321: 0}

However, it is impossible for any key to result in the following scores,
so in this case you should return False:

{123456: 4, 345678: 4, 567890: 4}
*/

bool mastermind(unordered_map<int, int> guesses){
	for(
		int i=0, j=0, k=0, l=0, m=0, n=0;
		i <= 9 && j <= 9 && k <= 9 && l <= 9 && m <= 9 && n <= 9 &&
		i != 0 && j != i && k != i && k != j && l != i && l != j &&
		l != k && m != i && m != j && m != k && m != l && n != i &&
		n != j && n != k && n != l && n != m;
		i++, j++, k++, l++, m++, n++;
	){
		cout << to_string(i) + to_string(j) + 
	}
}


// main function
int main(){
	return 0;
}