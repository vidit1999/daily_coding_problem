#include <bits/stdc++.h>
using namespace std;

/*
Invert a binary tree.

For example, given the following tree:

    a
   / \
  b   c
 / \  /
d   e f
should become:

  a
 / \
 c  b
 \  / \
  f e  d
*/

struct node{
	char data;
	node *left, *right;
};

node* newNode(char data){
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

void invertTree(node* root){
	if(root){
		invertTree(root->left);
		invertTree(root->right);
		swap(root->left, root->right);
	}
}

// main function
int main(){
	node* root = newNode('a');
	root->left = newNode('b');
	root->right = newNode('c');
	root->left->left = newNode('d');
	root->left->right = newNode('e');
	root->right->left = newNode('f');
	
	printInorder(root); cout << "\n";
	
	invertTree(root);
	
	printInorder(root); cout << "\n";
	return 0;
}