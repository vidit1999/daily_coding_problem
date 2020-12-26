#include <bits/stdc++.h>
using namespace std;

/*
Typically, an implementation of in-order traversal of a binary
tree has O(h) space complexity, where h is the height of the tree.
Write a program to compute the in-order traversal of a binary
tree using O(1) space.
*/

struct node{
	int data;
	node *left, *right;
};

node* newNode(int data){
	auto root = new node;
	root->data = data;
	root->left = root->right = nullptr;
	return root;
}

void printInorder(node* root){
	if(root){
		printInorder(root->left);
		cout << root->data << " ";
		printInorder(root->right);
	}
}

void morrisTraversal(node* root){
	node *curr, *prev;
	curr = root;

	while(curr){
		if(!curr->left){
			cout << curr->data << " ";
			curr = curr->right;
		}
		else{
			prev = curr->left;

			while(prev->right && prev->right != curr){
				prev = prev->right;
			}

			if(!prev->right){
				prev->right = curr;
				curr = curr->left;
			}
			else{ // if prev->right == curr
				prev->right = nullptr;
				cout << curr->data << " ";
				curr = curr->right;
			}
		}
	}
}

// main function
int main(){
	auto root = newNode(6);
	root->left = newNode(2);
	root->left->left = newNode(1);
	root->left->right = newNode(4);
	root->left->right->left = newNode(3);
	root->left->right->right = newNode(5);
	root->right = newNode(7);
	root->right->right = newNode(9);
	root->right->right->left = newNode(8);

	printInorder(root); cout << "\n";
	morrisTraversal(root); cout << "\n";
	morrisTraversal(root); cout << "\n";

	return 0;
}