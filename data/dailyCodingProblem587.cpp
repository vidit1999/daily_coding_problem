#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree,
return all paths from the root to leaves.

For example, given the tree:

   1
  / \
 2   3
    / \
   4   5

Return [[1, 2], [1, 3, 4], [1, 3, 5]].
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

void printInorder(node* root){
	if(root){
		printInorder(root->left);
		cout << root->data << "\n";
		printInorder(root->right);
	}
}

void rootToLeafUtil(node* root, vector<int> root_path, vector<vector<int>>& all_paths){
	if(root){
		root_path.push_back(root->data);
		if(!root->left && !root->right)
			all_paths.push_back(root_path);
		rootToLeafUtil(root->left, root_path, all_paths);
		rootToLeafUtil(root->right, root_path, all_paths);
	}
}

vector<vector<int>> allRootToLeafPaths(node* root){
	vector<int> root_path;
	vector<vector<int>> all_paths;
	rootToLeafUtil(root, root_path, all_paths);
	return all_paths;
}

// main function
int main(){
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(4);
	root->right->right = newNode(5);
	
	for(auto v : allRootToLeafPaths(root)){
		for(int i : v)
			cout << i << " ";
		cout << "\n";
	}
	
	return 0;
}