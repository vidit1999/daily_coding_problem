#include <bits/stdc++.h>
#define ALPHABET_SIZE 26
using namespace std;

/*
Implement a PrefixMapSum class with the following methods:

insert(key: str, value: int): Set a given key's value in the map. If the key already exists, overwrite the value.
sum(prefix: str): Return the sum of all values of keys that begin with a given prefix.

For example, you should be able to run the following code:
mapsum.insert("columnar", 3)
assert mapsum.sum("col") == 3

mapsum.insert("column", 2)
assert mapsum.sum("col") == 5
*/

struct Trie{
	int value;
	bool end_of_word;
	Trie* children[ALPHABET_SIZE];
};

Trie* getNode(int value){
	Trie* tr = new Trie;
	tr->value = value;
	tr->end_of_word = false;
	for(int i=0; i<ALPHABET_SIZE; i++){
		tr->children[i] = nullptr;
	}
	return tr;
}

void insert(Trie* root, string key, int value){
	Trie* curr = root;
	
	for(int i=0; i<key.length(); i++){
		int index = key[i] - 'a';
		
		if(curr->children[index] == nullptr){
			curr->children[index] = getNode(value);
		}
		else{
			curr->children[index]->value += value;
		}
		curr = curr->children[index];
	}
	
	curr->end_of_word = true;
}

int sum(Trie* root, string prefix){
	Trie* curr = root;
	
	for(int i=0; i<prefix.length(); i++){
		int index = prefix[i] - 'a';
		
		if(curr->children[index] == nullptr)
			return -1;
		curr = curr->children[index];
	}
	
	return curr->value;
}

class PrefixMapSum{
	Trie* tr;
	
	public:
	PrefixMapSum(){ tr = getNode(0); }
	
	void insert(string key, int value){
		::insert(tr, key, value);
	}
	
	int sum(string prefix){
		return ::sum(tr, prefix);
	}
};

// main function
int main(){
	PrefixMapSum pms;
	pms.insert("columnar", 3);
	cout << pms.sum("col") << "\n";
	
	pms.insert("column", 2);
	cout << pms.sum("col") << "\n";
	return 0;
}