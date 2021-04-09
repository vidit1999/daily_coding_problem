#include <bits/stdc++.h>
using namespace std;

/*
Given a complete binary tree, count the number of nodes in faster than O(n) time.
Recall that a complete binary tree has every level filled except the last,
and the nodes in the last level are filled starting from the left.

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6
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

int subTreeHeight(node* root, bool left_side){
	int height = 0;
	
	while(root){
		height++;
		root = ((left_side)? root->left : root->right);
	}
	
	return height;
}

int countNodes(node* root){
	int left_height = subTreeHeight(root, true);
	int right_height = subTreeHeight(root, false);
	
	if(left_height == right_height)
		return (1 << left_height) - 1;
	
	return 1 + countNodes(root->left) + countNodes(root->right);
}

// main function
int main(){
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);

    cout << countNodes(root) << "\n";

	return 0;
}