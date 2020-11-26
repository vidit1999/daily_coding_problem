#include <bits/stdc++.h>
using namespace std;

/*
Suppose an arithmetic expression is given as a binary tree.
Each leaf is an integer and each internal node is one of '+', '−', '∗', or '/'.

Given the root to such a tree, write a function to evaluate it.

For example, given the following tree:

    *
   / \
  +    +
 / \  / \
3  2  4  5

You should return 45, as it is (3 + 2) * (4 + 5).
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

int evalExp(int num1, int num2, int op){
	switch(op){
		case '+' : return num1 + num2;
		case '-' : return num1 - num2;
		case '*' : return num1 * num2;
		case '/' : return num1 / num2;
	}
	return -1;
}

int evalTree(node* root){
	if(root){
		if(root->left && root->right){
			auto leftEval = evalTree(root->left);
			auto rightEval = evalTree(root->right);

			return evalExp(leftEval, rightEval, root->data);
		}
		return root->data;
	}
	return 0;
}

// main function
int main(){
	auto root = newNode('*');
	root->left = newNode('+');
	root->right = newNode('+');
	root->left->left = newNode(3);
	root->left->right = newNode(2);
	root->right->left = newNode(4);
	root->right->right = newNode(5);

	cout << evalTree(root) << "\n";

	return 0;
}