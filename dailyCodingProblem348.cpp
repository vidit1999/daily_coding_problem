#include <bits/stdc++.h>
using namespace std;

/*
A ternary search tree is a trie-like data structure where each node
may have up to three children. Here is an example which represents
the words code, cob, be, ax, war, and we.

       c
    /  |  \
   b   o   w
 / |   |   |
a  e   d   a
|    / |   | \ 
x   b  e   r  e  

The tree is structured according to the following rules:

left child nodes link to words lexicographically earlier than the parent prefix
right child nodes link to words lexicographically later than the parent prefix
middle child nodes continue the current word

For instance, since code is the first word inserted in the tree,
and cob lexicographically precedes cod, cob is represented as a
left child extending from cod.

Implement insertion and search functions for a ternary search tree.
*/

struct node{
	char data;
	bool is_eow;
	node *mid, *left, *right;
};

node* newNode(char data){
	auto root = new node;
	root->data = data;
	root->is_eow = false;
	root->left = root->right = root->mid = nullptr;
	return root;
}

void insertHelper(node*& root, string& word, int index){
	if(!root) root = newNode(word[index]);
	
	if(root->data > word[index]){
		insertHelper(root->left, word, index);
	}
	else if(root->data < word[index]){
		insertHelper(root->right, word, index);
	}
	else{
		if(index == word.length()-1){
			root->is_eow = true;
		}
		else{
			insertHelper(root->mid, word, ++index);
		}
	}
}

void insert(node*& root, string word){
	if(word.empty()) return;
	insertHelper(root, word, 0);
}

bool searchHelper(node* root, string& word, int index){
	if(!root) return false;
	
	if(root->data > word[index]){
		return searchHelper(root->left, word, index);
	}
	else if(root->data < word[index]){
		return searchHelper(root->right, word, index);
	}
	else{
		if(index == word.length()-1){
			return root->is_eow;
		}
		else{
			return searchHelper(root->mid, word, ++index);
		}
	}
}

bool search(node* root, string word){
	if(word.empty()) return false;
	return searchHelper(root, word, 0);
}

// main function
int main(){
	node* root = nullptr;
	vector<string> words = {"code", "cob", "be", "ax", "war", "we"};

	for(string word : words){
		insert(root, word);
	}

	for(string word : words){
		cout <<search(root, word) << "\n";
	}
    
    cout << "\n";
	cout << search(root, "bear") << "\n";
	cout << search(root, "axis") << "\n";
	cout << search(root, "atom") << "\n";
	cout << search(root, "cod") << "\n";
	cout << search(root, "code") << "\n";
	cout << search(root, "wear") << "\n";

	return 0;
}