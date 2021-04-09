#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree and an integer k, return whether there exists a root-to-leaf path that sums up to k.

For example, given k = 18 and the following binary tree:

    8
   / \
  4   13
 / \   \
2   6   19

Return True since the path 8 -> 4 -> 6 sums to 18.
*/

struct node{
	int data;
	node *left, *right;
};

node* newNode(int data){
	node* root = new node;
	root->data = data;
	root->left = root->right = NULL;
	return root;
}

bool isSumPath(node* root, int sum){
	if(root == NULL) return (sum == 0);

    if(!root->left && !root->right && (sum == root->data)) return true;
	
	return (
        (root->left && isSumPath(root->left, sum - root->data)) ||
        (root->right && isSumPath(root->right, sum - root->data))
    );
}

// main function
int main(){
	node* root = newNode(8);
	root->left = newNode(4);
	root->right = newNode(13);
	root->left->left = newNode(2);
	root->left->right = newNode(6);
	root->right->right = newNode(19);
	
	if(isSumPath(root, 18))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}