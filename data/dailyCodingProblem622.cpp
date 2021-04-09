#include <bits/stdc++.h>
using namespace std;

/*
Given the root of a binary tree, return a deepest node.
For example, in the following tree, return d.

    a
   / \
  b   c
 /
d
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

void deepestNodeHelper(node* root, int depth, int &max_depth, node*& deepest){
	if(!root) return;
	
	if(!root->left && !root->right){
		if(depth > max_depth){
			max_depth = depth;
			deepest = root;
		}
		return;
	}
	
	deepestNodeHelper(root->left, depth+1, max_depth, deepest);
	deepestNodeHelper(root->right, depth+1, max_depth, deepest);
}

node* deepestNode(node* root){
	int max_depth = 0;
	node* deepest = nullptr;
	deepestNodeHelper(root, 0, max_depth, deepest);
	return deepest;
}

// main function
int main(){
	node* root = newNode('a');
	root->left = newNode('b');
	root->right = newNode('c');
	root->left->left = newNode('d');
	
	auto ans = deepestNode(root);
	
	if(ans)
		cout << char(ans->data) << "\n";
	else
		cout << "No deepest node.\n";
	
	return 0;
}