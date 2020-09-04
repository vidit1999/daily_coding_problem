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
	root->left = nullptr;
	root->right = nullptr;
	return root;
}

unordered_map<node*, int> node_height;

int height(node* root){
	if(node_height.find(root) != node_height.end())
		return node_height[root];
	
	int height_tree;
	if(!root)
		height_tree = 0;
	else
		height_tree = max(height(root->left), height(root->right))+1;
	
	node_height[root] = height_tree;
	return height_tree;
}


bool isBalanced(node* root){
	if(!root) return true;
	
	int left_height = height(root->left), right_height = height(root->right);
	
	return (abs(left_height - right_height) <= 1) && isBalanced(root->left) && isBalanced(root->right);
}

// main function
int main(){
	node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->right->left = newNode(6);
    root1->left->left->left = newNode(7);
	

    node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);
    root2->left->left->left = newNode(8);

	if(isBalanced(root1))
		cout << "Yes\n";
	else
		cout << "No\n";

    if(isBalanced(root2))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}