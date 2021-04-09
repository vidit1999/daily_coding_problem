#include <bits/stdc++.h>
using namespace std;

/*
A unival tree (which stands for "universal value") is a
tree where all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.

For example, the following tree has 5 unival subtrees:

   0
  / \
 1   0
    / \
   1   0
  / \
 1   1
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

bool countUnivalHelper(node* root, int& count){
	if(!root) return true;
	
	bool left_check = countUnivalHelper(root->left, count);
	bool right_check = countUnivalHelper(root->right, count);
	
	if(!left_check && !right_check) return false;
	if(root->left && root->data != root->left->data) return false;
	if(root->right && root->data != root->right->data) return false;
	
	count++;
	return true;
}

int countUnival(node* root){
	int count = 0;
	countUnivalHelper(root, count);
	return count;
}

// main function
int main(){
	node* root = newNode(0);
	root->left = newNode(1);
	root->right = newNode(0);
	root->right->left = newNode(1);
	root->right->right = newNode(0);
	root->right->left->left = newNode(1);
	root->right->left->right = newNode(1);
	
	cout << countUnival(root) << "\n";
	
	return 0;
}