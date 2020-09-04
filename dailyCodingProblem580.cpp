#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree, find a minimum path sum from root to a leaf.

For example, the minimum path in this tree is [10, 5, 1, -1], which has sum 15.

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

void minPathSumHelper(node* root, int sum, int& min_sum){
	if(root){
		sum += root->data;
		if(!root->left && !root->right) min_sum =  min(min_sum, sum);
        
        if(root->left) minPathSumHelper(root->left, sum, min_sum);
        if(root->right) minPathSumHelper(root->right, sum, min_sum);
	}
}

int minPathSum(node* root){
    if(!root) return 0;

    int sum = 0;
    int min_sum = INT_MAX;
    minPathSumHelper(root, sum, min_sum);
    return min_sum;
}

// main function
int main(){
    node* root1 = newNode(10);
    root1->left = newNode(5);
    root1->right = newNode(5);
    root1->left->right = newNode(2);
    root1->right->right = newNode(1);
    root1->right->right->left = newNode(-1);

    cout << minPathSum(root1) << "\n";

    node* root2 = newNode(10);
    root2->left = newNode(-2);
    root2->right = newNode(7);
    root2->left->left = newNode(8);
    root2->left->right = newNode(-4);

    cout << minPathSum(root2) << "\n";
	return 0;
}