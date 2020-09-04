#include <bits/stdc++.h>
using namespace std;

/*
Given the root to a binary search tree,
find the second largest node in the tree.
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

void inorderTraversal(node* root, node*& prev, node*& curr){
	if(root){
		inorderTraversal(root->left, prev, curr);
		prev = curr;
		curr = root;
		inorderTraversal(root->right, prev, curr);
	}
}

node* secondMaxNode(node* root){
	node *prev = nullptr, *curr = nullptr;
	inorderTraversal(root, prev, curr);
	return prev;
}

// main function
int main(){
	node* root = newNode(4);
	root->left = newNode(2);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right = newNode(6);
	root->right->left = newNode(5);
	root->right->right = newNode(7);
	
	node* second = secondMaxNode(root);
	cout << second->data << "\n";
	
	return 0;
}