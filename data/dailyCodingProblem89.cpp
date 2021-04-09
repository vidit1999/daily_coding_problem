#include <bits/stdc++.h>
using namespace std;

/*
Determine whether a tree is a valid binary search tree.

A binary search tree is a tree with two children, left and right,
and satisfies the constraint that the key in the
left child must be less than or equal to the root
and the key in the right child must be greater
than or equal to the root.
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

bool isBSTHelper(node* root, node*& prev){
	if(!root) return true;
	
	if(!isBSTHelper(root->left, prev)) return false;
	
	if(prev && root->data <= prev->data) return false;
	
	prev = root;
	
	return isBSTHelper(root->right, prev);
}

bool isBST(node* root){
	node* prev = nullptr;
	return isBSTHelper(root, prev);
}

// main function
int main(){
	node* root = newNode(4);
	root->left = newNode(2);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right = newNode(5);
	
	cout << boolalpha << isBST(root) << "\n";
	
	return 0;
}