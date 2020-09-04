#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree, return all paths from the root to leaves.

For example, given the tree

   1
  / \
 2   3
    / \
   4   5

it should return [[1, 2], [1, 3, 4], [1, 3, 5]].
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

void allRootToLeafHelper(node* root, vector<int> path, vector<vector<int>>& ans){
	if(!root) return;
	
	path.push_back(root->data);
	
	if(!root->left && !root->right){
		ans.push_back(path);
		return;
	}
	
	allRootToLeafHelper(root->left, path, ans);
	allRootToLeafHelper(root->right, path, ans);
}

vector<vector<int>> allRootToLeaf(node* root){
	vector<vector<int>> ans;
	allRootToLeafHelper(root, {}, ans);
	return ans;
}

// main function
int main(){
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(4);
	root->right->right = newNode(5);
	
	for(auto v : allRootToLeaf(root)){
		for(int i : v)
			cout << i << " ";
		cout << "\n";
	}
	
	return 0;
}