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
	node* root = new node;
	root->data = data;
	root->left = root->right = nullptr;
	return root;
}

void printInorder(node* root){
	if(root){
		printInorder(root->left);
		cout << root->data << " ";
		printInorder(root->right);
	}
}

node* generate(){
	node* root = newNode(rand()%1000);
	
	if(rand()%2) root->left = generate();
	if(rand()%2) root->right = generate();
	
	return root;
}

// main function
int main(){
	srand(time(0));
	
	printInorder(generate()); cout << "\n";
	printInorder(generate()); cout << "\n";
	printInorder(generate()); cout << "\n";
	printInorder(generate()); cout << "\n";
	
	return 0;
}