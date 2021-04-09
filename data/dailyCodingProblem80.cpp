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
	char data;
	node *left, *right;
};

node* newNode(char data){
	node* root = new node;
	root->data = data;
	root->left = root->right = nullptr;
	return root;
}

void deepestNodeHelper(node* root, int level, char& deepest_node, int& max_level){
	if(root){
		if(level > max_level){
			max_level = level;
			deepest_node = root->data;
		}
		deepestNodeHelper(root->left, level+1, deepest_node, max_level);
		deepestNodeHelper(root->right, level+1, deepest_node, max_level);
	}
}

char deepestNode(node* root){
	char deepest_node = '\0';
	int max_level = INT_MIN;
	deepestNodeHelper(root, 0, deepest_node, max_level);
	return deepest_node;
}

// main function
int main(){
	node* root = newNode('a');
	root->left = newNode('b');
	root->right = newNode('c');
	root->left->left = newNode('d');
	
	cout << deepestNode(root) << "\n";
	
	return 0;
}