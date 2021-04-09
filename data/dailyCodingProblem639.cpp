#include <bits/stdc++.h>
using namespace std;

/*
Given a mapping of digits to letters (as in a phone number),
and a digit string, return all possible letters the number
could represent. You can assume each valid number in the
mapping is a single digit.

For example if {“2”: [“a”, “b”, “c”], 3: [“d”, “e”, “f”], …}
then “23” should return [“ad”, “ae”, “af”, “bd”, “be”,
“bf”, “cd”, “ce”, “cf"].
*/

vector<string> possibleKLatterNumbersHelper(
    string& number,
    int pos,
    unordered_map<string, vector<string>>& letter_word_map
){
    if(pos == number.length()-1){
        return letter_word_map[string(1, number[pos])];
    }

    vector<string> ans;
    for(string letter : letter_word_map[string(1, number[pos])]){
        for(string s : possibleKLatterNumbersHelper(number, pos+1, letter_word_map)){
            ans.push_back(letter + s);
        }
    }
    return ans;
}

vector<string> possibleLetterNumbers(
    unordered_map<string, vector<string>> letter_word_map,
    string number
){
	return possibleKLatterNumbersHelper(number, 0, letter_word_map);
}

// main function
int main(){
    unordered_map<string, vector<string>> letter_word_map = {
        {"2", {"a", "b", "c"}},
        {"3", {"d", "e", "f"}},
    };

    string number = "23";

    for(string s : possibleLetterNumbers(letter_word_map, number)){
        cout << s << "\n";
    }
	return 0;
}