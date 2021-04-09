#include <bits/stdc++.h>
using namespace std;

/*
Given a complete binary tree, count the number of nodes in
faster than O(n) time. Recall that a complete binary tree
has every level filled except the last, and the nodes in
the last level are filled starting from the left.
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

int leftHeight(node* root){
	int height = 0;

	while(root){
		height++;
		root = root->left;
	}

	return height;
}

int rightHeight(node* root){
	int height = 0;

	while(root){
		height++;
		root = root->right;
	}

	return height;
}

int countFullTreeHeight(node* root){
	if(!root) return 0;

	int left_height = leftHeight(root);
	int right_height = rightHeight(root);

	if(left_height == right_height)
		(1 << left_height)-1;

	return 1 + countFullTreeHeight(root->left) + countFullTreeHeight(root->right);
}

// main function
int main(){
	auto root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	cout << countFullTreeHeight(root) << "\n";

	return 0;
}