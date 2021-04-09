#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26
/*
Given a list of words,
return the shortest
unique prefix of each word.
For example, given the list:

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
	bool is_eow;
	bool unique_node;
	Trie* children[ALPHABET_SIZE];
};

Trie* newTrieNode(){
	Trie* root = new Trie;
	root->is_eow = false;
	root->unique_node = true;
	for(int i=0; i<ALPHABET_SIZE; i++){
		root->children[i] = nullptr;
	}
	return root;
}

void insert(Trie* root, string s){
	Trie* curr = root;

	for(int i=0; i<s.length(); i++){
		int index = s[i] - 'a';
		if(!curr->children[index]){
			curr->children[index] = newTrieNode();
		}
		else{
			curr->children[index]->unique_node = false;
		}
		curr = curr->children[index];
	}
	curr->is_eow = true;
}

Trie* buildTrie(vector<string> v){
	Trie* root = newTrieNode();
	for(string s : v){
		insert(root, s);
	}
	return root;
}

string uniquePrefixHelper(Trie* root, string s){
	string ans = "";
	auto curr = root;

	for(int i=0; i<s.length(); i++){
		int index = s[i] - 'a';
		ans += s[i];
		if(curr->children[index]->unique_node) break;
		curr =  curr->children[index];
	}

	return ans;
}

vector<string> uniquePrefix(vector<string> v){
	auto word_trie = buildTrie(v);
	vector<string> ans;

	for(string s : v){
		ans.push_back(uniquePrefixHelper(word_trie, s));
	}

	return ans;
}

// main function
int main(){
	vector<string> v = {
		"dog",
		"cat",
		"apple",
		"apricot",
		"fish",
	};

	for(auto s : uniquePrefix(v)){
		cout << s << "\n";
	}
	return 0;
}