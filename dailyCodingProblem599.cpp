#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26

/*
Ghost is a two-person word game where players alternate
appending letters to a word. The first person who spells
out a word, or creates a prefix for which there is no
possible continuation, loses. Here is a sample game:

Player 1: g
Player 2: h
Player 1: o
Player 2: s
Player 1: t [loses]

Given a dictionary of words, determine the letters the
first player should start with, such that with optimal
play they cannot lose.

For example, if the dictionary is ["cat", "calf", "dog", "bear"],
the only winning start letter would be b
*/

struct Trie{
	bool is_eow;
	Trie* children[ALPHABET_SIZE];
};

Trie* newTrie(){
	auto root = new Trie;
	root->is_eow = false;

	for(int i=0; i<ALPHABET_SIZE; i++){
		root->children[i] = nullptr;
	}

	return root;
}

void insertTrie(Trie* root, string s){
	for(char c : s){
		int i = c - 'a';
		if(!root->children[i]){
			root->children[i] = newTrie();
		}
		root = root->children[i];
	}

	root->is_eow = true;
}

bool ghostGameHelper(Trie* root){
	if(!root || root->is_eow) return false;

	for(int i=0; i<ALPHABET_SIZE; i++){
		if(ghostGameHelper(root->children[i])){
			return false;
		}
	}

	return true;
}

vector<char> ghostGame(vector<string> words){
	vector<char> ans;
	auto root = newTrie();

	for(string word : words){
		insertTrie(root, word);
	}

	for(int i=0; i<ALPHABET_SIZE; i++){
		if(ghostGameHelper(root->children[i])){
			ans.push_back('a' + i);
		}
	}

	return ans;
}

void testFunc(vector<vector<string>> v){
	for(auto words : v){
		auto ans = ghostGame(words);
		for(char c : ans){
			cout << c << " ";
		}
		cout << "\n";
	}
}

// main function
int main(){
	testFunc({
		{"cat", "calf", "dog", "bear"},
		{"cat", "calf", "dog"},
		{"cat", "cap", "dog"},
		{"cat", "calf", "dog", "bear", "hi", "hit"},
		{"cat", "calf", "dog", "bear", "hi", "hut"}
	});
	return 0;
}