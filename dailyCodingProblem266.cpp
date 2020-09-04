#include <bits/stdc++.h>
using namespace std;

/*
A step word is formed by taking a given word,
adding a letter, and anagramming the result.
For example, starting with the word "APPLE",
you can add an "A" and anagram to get "APPEAL".

Given a dictionary of words and an input word,
create a function that returns all valid step words.
*/

// word1_map => map of character with its count in first word
// word2 => second word
// returns true if valid step word
bool isValidStepWord(unordered_map<char, int> word1_map, string word2){
	for(char c : word2) word1_map[c]--;
	
	bool one_letter_added = false;
	
	for(auto it : word1_map){
		if(it.second == -1 || it.first == 1){
			// if only one letter is added then one_letter_added will be true
			// if more than one letter is added then return false
			if(!one_letter_added)
				one_letter_added = true;
			else
				return false;
		}
	}
	
	// return true if only one letter is added
	return (one_letter_added == true);
}

vector<string> validStepWords(string word, unordered_set<string> dictionary){
	unordered_map<char, int> word1_map;
	for(char c : word) word1_map[c]++;
	
	vector<string> ans;
	for(string word2 : dictionary){
		if(isValidStepWord(word1_map, word2))
			ans.push_back(word2);
	}
	
	return ans;
}

// main function
int main(){
	string word = "APPLE";
	unordered_set<string> dictionary = {"APPEAL", "APPLE", "APPPLE", "APPLME", "APLE"};
	
	for(string s : validStepWords(word, dictionary))
		cout << s << "\n";
	return 0;
}