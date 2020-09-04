#include <bits/stdc++.h>
#define ALPHABET_SIZE 26
using namespace std;

/*
Given a list of words, return the shortest unique
prefix of each word. For example, given the list:

dog
cat
apple
apricot
fish

Return the list:

d
c
app
apr
f
*/

struct Trie{
	bool unique_in;
	bool is_endof_word;
	Trie* children[ALPHABET_SIZE];
};

Trie* newNode(){
	Trie* root = new Trie;
	root->is_endof_word = false;
	root->unique_in = true;
	for(int i=0; i<ALPHABET_SIZE; i++) root->children[i] = nullptr;
	return root;
}

void insert(Trie* root, string s){
	Trie* curr = root;
	
	for(char c : s){
		int index = c - 'a';
		if(!curr->children[index])
			curr->children[index] = newNode();
		else
			curr->children[index]->unique_in = false;
		curr = curr->children[index];
	}
	
	curr->is_endof_word = true;
}

string minPrefix(Trie* root, string s){
	string prefix = "";
	Trie* curr = root;
	
	for(char c : s){
		int index = c - 'a';
		prefix += c;
		if(curr->children[index]->unique_in) return prefix;
		curr = curr->children[index];
	}
	
	return prefix;
}

vector<string> shortestUniquePrefix(vector<string> v){
	Trie* root = newNode();
	for(string s : v) insert(root, s);
	
	vector<string> ans;
	for(string s : v) ans.push_back(minPrefix(root, s));
	
	return ans;
}

// main function
int main(){
	vector<string> v = {
		"dog",
		"cat",
		"apple",
		"apricot",
		"fish"
	};
	
	for(string s : shortestUniquePrefix(v))
		cout << s << "\n";
	return 0;
}