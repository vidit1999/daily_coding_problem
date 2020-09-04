#include <bits/stdc++.h>
using namespace std;

/*
Given two non-empty binary trees s and t, check whether tree t has exactly
the same structure and node values with a subtree of s.
A subtree of s is a tree consists of a node in s and all
of this node's descendants. The tree s could also
be considered as a subtree of itself.
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

bool isSame(node* root1, node* root2){
	if(!root1 && !root2) return true; // both are empty so return true
	
	// both are non-empty
	if(root1 && root2){
		return (
			(root1->data == root2->data) &&
			isSame(root1->left, root2->left) &&
			isSame(root1->right, root2->right)
		);
	}
	
	// one is empty and one is not
	return false;
}

bool isSubtree(node* s, node* t){
	if(!s) return false;
	
	if(!t) return true;
	
	if(isSame(s, t)) return true;
	
	return isSubtree(s->left, t) || isSubtree(s->right, t);
}


// main function
int main(){
	node* t = newNode(10);
	t->left = newNode(4);
	t->right = newNode(6);
	t->left->right = newNode(30);
	
	node* s = newNode(26);
	s->left = newNode(10);
	s->right = newNode(3);
	s->left->left = newNode(4);
	s->left->right = newNode(6);
	s->left->left->right = newNode(30);
	s->right->right = newNode(3);
	
	cout << ((isSubtree(s, t))? "Yes" : "No") << "\n";
	
	return 0;
}