#include <bits/stdc++.h>
#define ALPHABET_SIZE 26
using namespace std;

/*
Implement a PrefixMapSum class with the following methods:

insert(key: str, value: int): Set a given key's value in the map.
If the key already exists, overwrite the value.
sum(prefix: str): Return the sum of all values of
keys that begin with a given prefix.

For example, you should be able to run the following code:

mapsum.insert("columnar", 3)
assert mapsum.sum("col") == 3

mapsum.insert("column", 2)
assert mapsum.sum("col") == 5
*/

struct Trie{
	int data;
	bool is_endofword;
	Trie children[ALPHABET_SIZE];
};

class PrefixMapSum{
	unordered_map<string, int> str_val;
	Trie* tr;
	
	public:
	PrefixMapSum();
	void insert(string key, int value);
	int sum(string prefix);
}

Trie* newNode(int data){
	Trie* node = new Trie;
	node->data = data;
	node->is_endofword = false;
	
	for(int i=0; i<ALPHABET_SIZE; i++) node->children[i] = nullptr;
	
	return node;
}

PrefixMapSum::PrefixMapSum(){
	tr = newNode(0);
}

void PrefixMapSum::insert(string key, int value){
	bool present = false;
	node* curr = tr;
	
	if(str_val.find(key) != str_val.end()){
		present = true;
		int old_value = str_val[key];
	}
	
	for(int i=0; i<key.length(); i++){
		int index = key[i] - 'a';
		if(curr->children[index] == nullptr)
			curr->children[index] = newNode(value);
		else{
			curr->children[index]->data += (value - ((present)? old_value : 0));
		}
		curr = curr->children[index];
	}
	
	curr->is_endofword = true;
	str_val[key] = value;
}

int PrefixMapSum::sum(string prefix){
	Trie* curr = tr;
	
	for(int i=0; i<prefix.length(); i++){
		int index = prefix[i] - 'a';
		if(curr->children[index] == nullptr)
			return -1;
		curr = curr->children[index];
	}
	
	return curr->data;
}

// main function
int main(){
	PrefixMapSum pms;
	pms.insert("columnar", 3);
	cout << pms.sum("col") << "\n";
	
	pms.insert("column", 2);
	cout << pms.sum("col") << "\n";
	return 0;
}