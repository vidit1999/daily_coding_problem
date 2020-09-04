#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree, determine whether or not it is height-balanced.
A height-balanced binary tree can be defined as one in which the heights
of the two subtrees of any node never differ by more than one.
*/

struct node{
	int data;
	node *left, *right;
};

node* newNode(int data){
	node* root = new node;
	root->data = data;
	root->right = root->left = NULL;
	return root;
}

void deleteTreeHelper(node* root){
	if(root){
		deleteTreeHelper(root->left);
		deleteTreeHelper(root->right);
		delete root;
	}
}

void deleteTree(node** root){
	deleteTreeHelper(*root);
	*root = NULL;
}

int height(node* root){
	if(root == NULL)
		return 0;
	return 1 + max(height(root->left), height(root->right));
}

bool isHeightBalanced(node* root){
	if(root == NULL)
		return true;
	return abs(height(root->left)-height(root->right)) <= 1 
			&& isHeightBalanced(root->left)
			&& isHeightBalanced(root->right);
}

// main function
int main(){
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(8);
	
	if(isHeightBalanced(root))
		cout << "Yes\n";
	else
		cout << "No\n";
	
	deleteTree(&root);
	return 0;
}