#include <bits/stdc++.h>
using namespace std;

/*
A Cartesian tree with sequence S is a binary tree defined by the following two properties:

It is heap-ordered, so that each parent value is strictly less than that of its children.
An in-order traversal of the tree produces nodes with values that correspond exactly to S.
For example, given the sequence [3, 2, 6, 1, 9], the resulting Cartesian tree would be:

      1
    /   \   
  2       9
 / \
3   6
Given a sequence S, construct the corresponding Cartesian tree.
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

node* buildTree(int arr[], int start, int end){
    if(start > end) return nullptr;

    int minIndex = start, min = arr[start];
    for(int i=start;i<=end;i++){
        if(arr[i] < min){
            min = arr[i];
            minIndex = i;
        }
    }

    node* root = newNode(min);
    root->left = buildTree(arr, start, minIndex-1);
    root->right = buildTree(arr, minIndex+1, end);
    return root;
}

// main function
int main(){
    int arr[] = {3, 2, 6, 1, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    printInorder(buildTree(arr, 0, n-1));
	return 0;
}