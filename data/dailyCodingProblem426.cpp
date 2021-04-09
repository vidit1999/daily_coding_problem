#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree, return the level of the tree with minimum sum.

	  4
	/   \
   2    -5
  / \    /\
-1   3 -2  6

answer = (-1 + 3 + -2 + 6) = 6
*/

struct node{
	int data;
	node *left, *right;
};

node* newNode(int data){
	node* root = new node;
	root->data = data;
	root->left = root->right = NULL;
	return root;
}

int levelSum(node* root){
	if(!root) return 0;
	
	int res = root->data;
	queue<node*> q;
	q.push(root);
	
	while(!q.empty()){
		int count = q.size();
		int sum = 0;
		
		while(count--){
			node* temp = q.front();
			q.pop();
			
			sum += temp->data;
			
			if(temp->left) q.push(temp->left);
			if(temp->right) q.push(temp->right);
		}
		
		res = max(res, sum);
	}
	
	return res;
}

// main function
int main(){
	node* root = newNode(4);
	root->left = newNode(2);
	root->right = newNode(-5);
	root->left->left = newNode(-1);
	root->left->right = newNode(3);
	root->right->left = newNode(-2);
	root->right->right = newNode(6);
	
	cout << levelSum(root) << "\n";
	return 0;
}