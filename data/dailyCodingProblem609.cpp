#include <bits/stdc++.h>
using namespace std;

/*
Given a node in a binary search tree,
return the next bigger element,
also known as the inorder successor.

For example, the inorder successor of 22 is 30.

   10
  /  \
 5    30
     /  \
   22    35

You can assume each node has a parent pointer.
*/

struct node{
	int data;
	node *parent, *left, *right;
};

node* newNode(node* parent, int data){
	node* root = new node;
	root->data = data;
	root->parent = parent;
	root->left = nullptr;
	root->right = nullptr;
	return root;
}

void printInorder(node* root){
	if(root){
		printInorder(root->left);
		cout << root->data << " ";
		printInorder(root->right);
	}
}

node* inorderSucc(node* root){
	if(!root) return nullptr;
	
	if(root->right){
		// get the minimum value node in the right sub-tree
		node* curr = root->right;
		while(curr->left) curr = curr->left;
		return curr;
	}
	
	// go to the parent node untill a node which is
	// left sub-tree of its parent found
	node* curr = root;
	while(curr->parent && curr->parent->left != curr){
		curr = curr->parent;
	}
	
	return curr->parent;
}

// main function
int main(){
	node *root = newNode(nullptr, 10);
    root->left = newNode(root, 5);
    root->right = newNode(root, 30);
    root->right->left = newNode(root->right, 22);
    root->right->right = newNode(root->right, 35);

    printInorder(root);
    cout << "\n";

	node* ans = inorderSucc(root->right->left);

	if(ans)
		cout << "Inorder successor : " << ans->data << "\n";
	else
		cout << "No inorder successor\n";
	
	return 0;
}