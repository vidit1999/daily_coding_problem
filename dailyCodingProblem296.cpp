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
	root->left = root->right = nullptr;
	return root;
}

void printInorder(node* root){
	if(root){
		printInorder(root->left);
		cout << root->data << " ";
		printInorder(root->right);
	}
}

node* sortedArrayToBST(int arr[], int start, int end){
	if(start > end)
		return nullptr;
	
	int mid = (start + end)/2;
	node* root = newNode(arr[mid]);
	root->left = sortedArrayToBST(arr, start, mid-1);
	root->right = sortedArrayToBST(arr, mid+1, end);
	return root;
}

// main function
int main(){
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int n = sizeof(arr)/sizeof(arr[0]);
	printInorder(sortedArrayToBST(arr, 0, n-1));
	return 0;
}