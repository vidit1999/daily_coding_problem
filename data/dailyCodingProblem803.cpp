#include <bits/stdc++.h>
using namespace std;

#define LENGTH 6

/*
Mastermind is a two-player game in which the first player attempts
to guess the secret code of the second. In this version, the code
may be any six-digit number with all distinct digits.

Each turn the first player guesses some number, and the second player
responds by saying how many digits in this number correctly matched
their location in the secret code. For example, if the secret code
were 123456, then a guess of 175286 would score two, since 1 and 6 were correctly placed.

Write an algorithm which, given a sequence of guesses and their scores,
determines whether there exists some secret code that could have produced them.

For example, for the following scores you should return True,
since they correspond to the secret code 123456:

{175286: 2, 293416: 3, 654321: 0}

However, it is impossible for any key to result in the following scores,
so in this case you should return False:

{123456: 4, 345678: 4, 567890: 4}
*/

bool checkSolution(unordered_map<string, int>& guesses, string& number){
    for(auto it : guesses){
        int match_count = 0;
        
        for(int i=0; i<LENGTH; i++){
            if(it.first[i] == number[i]) match_count++;
        }
        
        if(match_count != it.second) return false;
    }
    
    return true;
}


bool masterMindHelper(
    string& number,
    unordered_map<string, int>& guesses,
    unordered_set<char>& visited
){
    if(number.length() == LENGTH){
        return checkSolution(guesses, number);
    }
    
    for(int i=(number.empty() ? 1 : 0); i<=9; i++){
        if(visited.find(i + '0') != visited.end()) continue;
        
        number.push_back(i + '0');
        visited.insert(i + '0');
        
        if(masterMindHelper(number, guesses, visited)){
            return true;
        }
        
        visited.erase(i + '0');
        number.pop_back();
    }
    
    return false;
}

bool masterMind(unordered_map<string, int>& guesses){
    string number = "";
    unordered_set<char> visited;
    
    if(masterMindHelper(number, guesses, visited)){
        cout << number << "\n";
        return true;
    }
    return false;
}

// main function
int main(){
    unordered_map<string, int> guesses1 = {
        {"175286", 2},
        {"293416", 3},
        {"654321", 0}
    };
    
    unordered_map<string, int> guesses2 = {
        {"123456", 4},
        {"345678", 4},
        {"567890", 4}
    };
    
    cout << masterMind(guesses2) << "\n";
    
    return 0;
}