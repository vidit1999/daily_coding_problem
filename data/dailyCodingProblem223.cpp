#include <bits/stdc++.h>
using namespace std;

/*
Typically, an implementation of in-order traversal of a binary tree has O(h)
space complexity, where h is the height of the tree. Write a program to
compute the in-order traversal of a binary tree using O(1) space.
*/

struct node{
	int data;
	node *left, *right;
};

node* newNode(int data){
	node* root = new node;
	root->data = data;
	root->left = nullptr;
	root->right = nullptr;
	return root;
}

void morrisTraversal(node* root){
	if(root){
		node *curr = root, *pre;
		
		while(curr){
			if(!curr->left){
				cout << curr->data << " ";
				curr = curr->right;
			}
			else{
				pre = curr->left;
				
				while(pre->right && pre->right != curr) pre = pre->right;
				
				if(!pre->right){
					pre->right = curr;
					curr = curr->left;
				}
				else{
					pre->right = nullptr;
					cout << curr->data << " ";
					curr = curr->right;
				}
			}
		}
		cout << "\n";
	}
}

// main function
int main(){
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	
	morrisTraversal(root);
	
	return 0;
}