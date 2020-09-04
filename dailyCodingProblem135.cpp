#include <bits/stdc++.h>
using namespace std;

/*
For example, the minimum path in this tree is
[10, 5, 1, -1], which has sum 15.

  10
 /  \
5    5
 \     \
   2    1
       /
     -1
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

void minPathSumHelper(node* root, int curr_sum, int& path_sum){
	if(!root) return; // root does not exist then return 0
	
	// change curr_sum, add root->data to it
	curr_sum += root->data;
	
	// if root is leaf node then set path_sum to minimum of path_sum and curr_sum
	if(!root->left && !root->right) path_sum = min(path_sum, curr_sum);
	
	// recur for left and right nodes
	minPathSumHelper(root->left, curr_sum, path_sum);
	minPathSumHelper(root->right, curr_sum, path_sum);
}

int minPathSum(node* root){
	int path_sum = INT_MAX;
	minPathSumHelper(root, 0, path_sum);
	return path_sum;
}

// main function
int main(){
	node* root = newNode(10);
	root->left = newNode(5);
	root->right = newNode(5);
	root->left->right = newNode(2);
	root->right->right = newNode(1);
	root->right->right->left = newNode(-1);
	
	cout << minPathSum(root) << "\n";
	
	return 0;
}