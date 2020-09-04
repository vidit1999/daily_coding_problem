#include <bits/stdc++.h>
using namespace std;

#define ALPHABET_SIZE 26

/*
Implement an autocomplete system. That is, given a query string s and a set
of all possible query strings, return all strings in the set that have s as a prefix.

For example, given the query string de and the set of
strings [dog, deer, deal], return [deer, deal].

Hint: Try preprocessing the dictionary into a
more efficient data structure to speed up queries.
*/

struct Trie{
	bool is_eow;
	Trie* children[ALPHABET_SIZE];
};

Trie* newNode(){
	Trie* root = new Trie;
	root->is_eow = false;
	for(int i=0; i<ALPHABET_SIZE; i++)
		root->children[i] = nullptr;
	return root;
}

void insert(Trie* root, string word){
	Trie* curr = root;
	
	for(int i=0; i<word.length(); i++){
		int index = word[i] - 'a';
		if(!curr->children[index])
			curr->children[index] = newNode();
		curr = curr->children[index];
	}
	
	curr->is_eow = true;
}

void wordPossible(Trie* root, string possible, vector<string>& ans){
	if(root->is_eow){
        ans.push_back(possible);
	}

	for(int i=0; i<ALPHABET_SIZE; i++){
		if(root->children[i]){
            wordPossible(root->children[i], possible + string(1, char(i+'a')), ans);
		}
	}
}

vector<string> getPreiction(string word, vector<string> dictionary){
	Trie* root = newNode();
	
    for(string s : dictionary){
        insert(root, s);
    }

	for(int i=0; i<word.length(); i++){
		int index = word[i] - 'a';
		if(!root->children[index])
			return {};
		root = root->children[index];
	}
	
    vector<string> ans;

    wordPossible(root, "", ans);
	
	for(int i=0; i<ans.size(); i++){
		ans[i] = word + ans[i];
	}
	
	return ans;
}

// main function
int main(){
	vector<string> dictionary = {
        "dog", "deer", "deal", "deeply", "de"
    };

    string word = "de";

    for(string s : getPreiction(word, dictionary)){
        cout << s << "\n";
    }

	return 0;
}