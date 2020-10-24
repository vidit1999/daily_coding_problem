#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26

/*
Implement an autocomplete system. That is, given a query string s and
a set of all possible query strings, return all strings in the set that have s as a prefix.

For example, given the query string de and the set of strings
[dog, deer, deal], return [deer, deal].

Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.
*/

struct Trie{
	bool is_eow;
	Trie* children[ALPHABET_SIZE];
};

Trie* newNode(){
	Trie* root = new Trie;
	root->is_eow = false;
	for(int i=0; i<ALPHABET_SIZE; i++){
		root->children[i] = nullptr;
	}
	return root;
}

void insertTrie(Trie* root, string& s){
	auto curr = root;

	for(char c : s){
		int index = c - 'a';
		if(!curr->children[index]){
			curr->children[index] = newNode();
		}
		curr = curr->children[index];
	}

	curr->is_eow = true;
}

Trie* createTrieFromVec(vector<string>& v){
	auto root = newNode();
	for(string& s : v){
		insertTrie(root, s);
	}
	return root;
}

vector<string> samePrefixHelper(Trie* root){
	if(root == nullptr) return {};
	
	vector<string> ans;
	
	for(int i=0; i<ALPHABET_SIZE; i++){
		if(root->children[i]){
			for(string s : samePrefixHelper(root->children[i])){
				ans.push_back(string(1,char('a'+i)) + s);
			}
			if(root->children[i]->is_eow){
    			ans.push_back(string(1, char('a'+i)));
    		}
		}
	}

	return ans;
}

vector<string> samePrefix(string word, vector<string> pos_words){
	auto root = createTrieFromVec(pos_words);
	auto curr = root;

	vector<string> ans;

	for(char c : word){
		int index = c - 'a';
		if(!curr->children[index]){
			return ans;
		}
		curr = curr->children[index];
	}
    
    if(curr && curr->is_eow){
        ans.push_back(word);
    }
    
	for(string s : samePrefixHelper(curr)){
		ans.push_back(word + s);
	}

	return ans;
}

// main function
int main(){
	string word = "de";
	vector<string> pos_words = {"dog", "deer", "deal"};

	for(string s : samePrefix(word, pos_words)){
		cout << s << "\n";
	}
	return 0;
}