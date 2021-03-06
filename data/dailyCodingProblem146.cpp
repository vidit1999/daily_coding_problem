#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree where all nodes are
either 0 or 1, prune the tree so that
subtrees containing all 0s are removed.

For example, given the following tree:

   0
  / \
 1   0
    / \
   1   0
  / \
 0   0

should be pruned to:

   0
  / \
 1   0
    /
   1

We do not remove the tree at the root or its left
child because it still has a 1 as a descendant.
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

node* pruneTree(node* root){
	if(!root) return nullptr;
	root->left = pruneTree(root->left);
	root->right = pruneTree(root->right);
	
	if(!root->left && !root->right && !root->data) return nullptr;
	
	return root;
}

void printInorder(node* root){
	if(root){
		printInorder(root->left);
		cout << root->data << " ";
		printInorder(root->right);
	}
}

// main function
int main(){
	node* root = newNode(0);
	root->left = newNode(1);
	root->right = newNode(0);
	root->right->left = newNode(1);
	root->right->right = newNode(0);
	root->right->left->left = newNode(0);
	root->right->left->right = newNode(0);
	
	printInorder(root);
	cout << "\n";
	printInorder(pruneTree(root));
	cout << "\n";
	
	return 0;
}