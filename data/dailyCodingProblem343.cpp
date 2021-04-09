#include <bits/stdc++.h>
using namespace std;

/*
Given a binary search tree and a range [a, b] (inclusive),
return the sum of the elements of the binary search tree within the range.

For example, given the following tree:

    5
   / \
  3   8
 / \ / \
2  4 6  10
and the range [4, 9], return 23 (5 + 4 + 6 + 8).
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

void printInorder(node* root){
	if(root){
		printInorder(root->left);
		cout << root->data << " ";
		printInorder(root->right);
	}
}

int rangeSumBST(node* root, pair<int, int> range){
	if(root){
		int sum = (root->data >= range.first && root->data <= range.second)? root->data : 0;
		if(root->data > range.first) sum += rangeSumBST(root->left, range);
		if(root->data < range.second) sum += rangeSumBST(root->right, range);
		return sum;
	}
	return 0;
}


// main function
int main(){
    node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(8);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->left = newNode(6);
    root->right->right = newNode(10);

    printInorder(root);
    cout << "\n";

    cout << rangeSumBST(root, {4, 9}) << "\n";

	return 0;
}