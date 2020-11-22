#include <bits/stdc++.h>
using namespace std;

#define DIGIT_COUNT 6

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

bool checkNumberMatchGuesses(vector<pair<string, int>>& guesses, string& number){
	for(auto& p : guesses){
		int similar_count = 0;
		for(int i=0; i<DIGIT_COUNT; i++){
			if(p.first[i] == number[i]){
				similar_count++;
			}
		}
		if(similar_count != p.second){
			return false;
		}
	}
	return true;
}

bool masterMindHelper(
	vector<pair<string, int>>& guesses,
	string& number
){
	if(number.length() == DIGIT_COUNT){
		return checkNumberMatchGuesses(guesses, number);
	}
	
	for(int i=(number.empty())? 1 : 0; i<=9; i++){
		number.push_back(i + '0');
		if(masterMindHelper(guesses, number)){
			return true;
		}
		number.pop_back();
	}
	
	return false;
}


bool masterMind(vector<pair<string, int>>& guesses){
	string number = "";
	return masterMindHelper(guesses, number);
}

// main function
int main(){
	vector<pair<string, int>> guesses = {
		// {"175286", 2},
		// {"293416", 3},
		// {"654321", 0}
		{"123456", 4},
		{"345678", 4},
		{"567890", 4}
	};
	
	cout << masterMind(guesses) << "\n";
	
    return 0;
}