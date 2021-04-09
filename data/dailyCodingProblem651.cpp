#include <bits/stdc++.h>
using namespace std;

/*
Determine whether a tree is a valid binary search tree.

A binary search tree is a tree with two children, left and right,
and satisfies the constraint that the key in the left child must
be less than or equal to the root and the key in the right child
must be greater than or equal to the root.
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

bool isBstHelper(node* root, node*& prev){
	if(!root) return true;
	
	if(!isBstHelper(root->left, prev)) return false;
	
	if(prev && prev->data >= root->data) return false;
	prev = root;
	
	return isBstHelper(root->right, prev);
}

bool isBst(node* root){
	node* prev = nullptr;
	return isBstHelper(root, prev);
}

// main function
int main(){
	node* root = newNode(4);
	root->left = newNode(2);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right = newNode(5);
	
	printInorder(root); cout << "\n";
	
	cout << boolalpha << isBst(root) << "\n";
	
	return 0;
}