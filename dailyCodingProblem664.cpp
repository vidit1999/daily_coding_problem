#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree of integers, find the maximum path sum between two nodes.
The path must go through at least one node, and does not need to go through the root.
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

int maxSum(node* root, int& res){
	if(!root) return 0;

	int l = maxSum(root->left, res);
	int r = maxSum(root->right, res);

	int max_root_sum = max(root->data, root->data + max(l, r));
	res = max(res, max(max_root_sum, l+r+root->data));

	return max_root_sum;
}

int maxSumNodes(node* root){
	int res = INT_MIN;
	maxSum(root, res);
	return res;
}

// main function
int main(){
	node* root = newNode(10);
	root->left = newNode(2);
	root->right = newNode(10);
	root->left->left = newNode(20);
	root->left->right = newNode(1);
	root->right->right = newNode(-25);
	root->right->right->left = newNode(3);
	root->right->right->right = newNode(4);

	cout << maxSumNodes(root) << "\n";

	return 0;
}