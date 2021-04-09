#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree, find the lowest common ancestor (LCA)
of two given nodes in the tree. Assume that each node
in the tree also has a pointer to its parent.

According to the definition of LCA on Wikipedia:
“The lowest common ancestor is defined between
two nodes v and w as the lowest node in T that
has both v and w as descendants (where we allow
a node to be a descendant of itself).”
*/

struct node{
	int data;
	node *left, *right, *parent;
};

node* newNode(int data, node* parent){
	node* root = new node;
	root->data = data;
	root->parent = parent;
	root->left = root->right = nullptr;
	return root;
}

node* lca(node* n1, node* n2){
	unordered_set<node*> seen;
	
	while(n1){
		seen.insert(n1);
		n1 = n1->parent;
	}
	
	while(n2){
		if(seen.find(n2) != seen.end())
			return n2;
		n2 = n2->parent;
	}
	
	return nullptr;
}

// main function
int main(){
	node* root = newNode(20, nullptr);
	root->left = newNode(8, root);
	root->right = newNode(22, root);
	root->left->left = newNode(4, root->left);
	root->left->right = newNode(12, root->left);
	root->left->right->left = newNode(10, root->left->right);
	root->left->right->right = newNode(14, root->left->right);
	
	auto ans = lca(root->left->left, root->left->right);
	if(ans) cout << ans->data << "\n";
	
	ans = lca(root->left->left, root->left->right->right);
	if(ans) cout << ans->data << "\n";
	
	ans = lca(root->left, root->left->right->left);
	if(ans) cout << ans->data << "\n";
	
	ans = lca(root->right, root);
	if(ans) cout << ans->data << "\n";
	
	return 0;
}