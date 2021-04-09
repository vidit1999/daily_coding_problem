#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree, return the level of the tree with minimum sum.
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

int minSumLevel(node* root){
	queue<node*> q({root});
	
	int min_level = 0, level = 0, min_sum = INT_MAX;
	
	while(!q.empty()){
		level++;
		
		int sum = 0;
		int size = q.size();
		
		while(size--){
			node* f = q.front(); q.pop();
			sum += f->data;
			if(f->left) q.push(f->left);
			if(f->right) q.push(f->right);
		}
		
		if(sum < min_sum){
			min_sum = sum;
			min_level = level;
		}
	}
	
	return min_level;
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
	
	cout << minSumLevel(root) << "\n";
	
	return 0;
}