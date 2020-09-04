#include <bits/stdc++.h>
using namespace std;

/*
Suppose an arithmetic expression is given as a binary tree. Each leaf is an integer
and each internal node is one of '+', '−', '∗', or '/'.

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
	char data;
	node *left, *right;
};

node* newNode(char data){
	node* root = new node;
	root->data = data;
	root->left = root->right = nullptr;
	return root;
}

int evaluateExp(int num1, int num2, char op){
	switch(op){
		case '+' : return num1 + num2;
		case '-' : return num1 - num2;
		case '*' : return num1 * num2;
		default : return num1 / num2;
	}
}

int evaluateTree(node* root){
	if(!root) return 0;
	
	if(!root->left && !root->right){
		return (root->data - '0');
	}
	
	int left_eval = evaluateTree(root->left), right_eval = evaluateTree(root->right);
	
	return evaluateExp(left_eval, right_eval, root->data);
}

// main function
int main(){
	node* root = newNode('*');
	root->left = newNode('+');
	root->right = newNode('+');
	root->left->left = newNode('3');
	root->left->right = newNode('2');
	root->right->left = newNode('4');
	root->right->right = newNode('5');
	
	cout << evaluateTree(root) << "\n";
	
	return 0;
}