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
    root->right = root->left = nullptr;
    return root;
}

int sumRange(int a, int b, node* root){
    int sum = (root && root->data >= a && root->data <= b)? root->data : 0;
    if(root->left && root->data > a)
        sum += sumRange(a, b, root->left);
    if(root->right && root->data < b)
        sum += sumRange(a, b, root->right);
    return sum;
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
	cout << sumRange(4,9,root) << "\n";
	return 0;
}