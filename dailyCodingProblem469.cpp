#include <bits/stdc++.h>
using namespace std;

/*
Mastermind is a two-player game in which the first player attempts to guess
the secret code of the second. In this version,
the code may be any six-digit number with all distinct digits.

Each turn the first player guesses some number, and the second player
responds by saying how many digits in this number correctly matched
their location in the secret code. For example, if the secret code were 123456,
then a guess of 175286 would score two, since 1 and 6 were correctly placed.

Write an algorithm which, given a sequence of guesses and their scores,
determines whether there exists some secret code that could have produced them.

For example, for the following scores you should return True, since they correspond to the secret code 123456:
{175286: 2, 293416: 3, 654321: 0}

However, it is impossible for any key to result in the following scores, so in this case you should return False:
{123456: 4, 345678: 4, 567890: 4}
*/


// generate all possible numbers of length 6 consisting of digits 0-9
// 10P6 is the number of possible ways
vector<int> genPermutation(){
    string allDigits = "0123456789";
	vector<int> selected;
	for(int i=0;i<10;i++){
		
	}
}


bool masterMind(vector<pair<string, int>> guesses){
    
    vector<string> possibleComb;
    for(int i=0;i<=9;i++){

    }
}

// main function
int main(){
    return 0;
}