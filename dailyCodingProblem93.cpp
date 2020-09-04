#include <bits/stdc++.h>
using namespace std;

/*
Given a tree, find the largest tree/subtree that is a BST.

Given a tree, return the size of the largest tree/subtree that is a BST.
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

int size(node* root){
	if(!root) return 0;
	return 1 + size(root->left) + size(root->right);
}

bool isBSTUtil(node* root, node*& prev){
	if(!root) return true;
	
	if(!isBSTUtil(root->left, prev))
		return false;
	
	if(prev && root->data <= prev->data)
		return false;
	
	prev = root;
	
	return isBSTUtil(root->right, prev);
}

bool isBST(node* root){
	node* prev = nullptr;
	return isBSTUtil(root, prev);
}

int largestSubtreeBST(node* root){
	if(isBST(root)){
		return size(root);
	}

    return max(
        largestSubtreeBST(root->left),
        largestSubtreeBST(root->right)
    );
}

// main function
int main(){
	node* root = newNode(50);
	root->left = newNode(30);
	root->left->left = newNode(5);
	root->left->right = newNode(20);
	root->right = newNode(60);
	root->right->left = newNode(45);
	root->right->right = newNode(70);
	root->right->right->left = newNode(65);
	root->right->right->right = newNode(80);

    printInorder(root); cout << "\n";
	cout << largestSubtreeBST(root) << "\n";

	return 0;
}