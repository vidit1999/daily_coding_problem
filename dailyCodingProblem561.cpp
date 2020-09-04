#include <bits/stdc++.h>
using namespace std;

/*
Given a sorted array, convert it into a height-balanced binary search tree.
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

node* heightBalancedBST(int arr[], int start, int end){
	if(star <= end){
		int mid = (start + end)/2;
		node* root = newNode(arr[mid]);
		root->left = heightBalancedBST(arr, start, mid - 1);
		root->right = heightBalancedBST(arr, mid + 1, end);
		return root;
	}
	return NULL;
}

void inorder(node* root){
	if(root){
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

// main function
int main(){
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	inorder(heightBalancedBST(arr, 0, n-1));
	cout << "\n";
	return 0;
}