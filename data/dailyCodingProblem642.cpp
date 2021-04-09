#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26

/*
A step word is formed by taking a given word, adding a letter, and anagramming the result.
For example, starting with the word "APPLE", you can add an "A" and anagram to get "APPEAL".

Given a dictionary of words and an input word,
create a function that returns all valid step words.
*/

bool isValidStepWord(string word, string dict_word){
    unordered_map<char, int> char_count;
    for(char c : dict_word) char_count[c]++;
    for(char c : word) char_count[c]--;

    int extra_count = 0;
    
    for(auto it : char_count){
        if(it.second == 1){
            if(++extra_count > 1)
                return false;
        }
        else if(it.second != 0)
            return false;
    }

    return (extra_count == 1);
}

unordered_set<string> stepWords(string word, unordered_set<string> dictionary){
	unordered_set<string> step_words;
	
	for(string dict_word : dictionary){
		if(isValidStepWord(word, dict_word))
			step_words.insert(dict_word);
	}
	
	return step_words;
}

// main function
int main(){
	unordered_set<string> dictionary = {
		"APPEAL", "CAPPLE",
		"PALPED", "LAPPED",
		"DAPPLE", "ALEPPO",
		"LAPPER", "RAPPEL",
		"LAPPET", "PAPULE",
		"LAPET", "PAULE",
	};
	string word = "APPLE";
	
	for(string s : stepWords(word, dictionary)){
		cout << s << "\n";
	}
	
	return 0;
}