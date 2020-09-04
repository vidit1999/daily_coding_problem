#include <bits/stdc++.h>
using namespace std;

/*
Given a node in a binary tree, return the next bigger element,
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
	node *left, *right, *parent;
};

node* newNode(int data, node* parent){
	node* root = new node;
	root->data = data;
	root->parent = parent;
	root->left = root->right = nullptr;
	return root;
}

void printInorder(node* root){
    if(root){
        printInorder(root->left);
        cout << root->data << "\n";
        printInorder(root->right);
    }
}

node* nextBigger(node* root){
	if(!root) return nullptr;

	if(root->right){
		node* curr = root->right;
		while(curr->left) curr = curr->left;
		return curr;
	}
	
	node* curr = root;
	while(curr->parent && curr != curr->parent->left) curr = curr->parent;
	
	return curr->parent;
}

// main function
int main(){
	node *root = newNode(10, nullptr);
    root->left = newNode(05, root);
    root->right = newNode(30, root);
    root->right->left = newNode(22, root->right);
    root->right->right = newNode(35, root->right);

    printInorder(root);
    cout << "\n";

	node* ans = nextBigger(root->right->left);

	if(ans)
		cout << "Inorder successor : " << ans->data << "\n";
	else
		cout << "No inorder successor\n";
	
	return 0;
}