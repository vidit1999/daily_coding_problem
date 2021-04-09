#include <bits/stdc++.h>
using namespace std;

/*
Generate a finite, but an arbitrarily large binary tree quickly in O(1).

That is, generate() should return a tree whose size is unbounded but finite.
*/

struct node{
	int data;
	node *left, *right;
};

node* newNode(int data){
	auto root = new node;
	root->data = data;
	root->left = root->right = nullptr;
	return root;
}

int height(node* root){
	if(!root) return 0;
	return 1 + max(height(root->left), height(root->right));
}

node* generateTree(){
	if(rand()%2){
		auto root = newNode(0);
		root->left = generateTree();
		root->right = generateTree();
		return root;
	}
	return nullptr;
}

// main function
int main(){
	srand(time(0));

	for(int i=0; i<10; i++){
		cout << height(generateTree()) << "\n";
	}
	return 0;
}