#include <bits/stdc++.h>
using namespace std;

/*
Given the sequence of keys visited by a postorder traversal
of a binary search tree, reconstruct the tree.

For example, given the sequence 2, 4, 3, 8, 7, 5, 
you should construct the following tree:

    5
   / \
  3   7
 / \   \
2   4   8
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

node* treeFormPostOrderHelper(vector<int>& arr, int& index, int min, int max){
	if(index < 0) return nullptr;
	
    int curr = arr[index];
    if(curr < min || curr > max) return nullptr;

    node* root = newNode(curr);
    index--;

    root->right = treeFormPostOrderHelper(arr, index, curr+1, max);
    root->left = treeFormPostOrderHelper(arr, index, min, curr-1);
    
    return root;
}

node* treeFormPostOrder(vector<int>& arr){
    int index = arr.size()-1;
    return treeFormPostOrderHelper(arr, index, INT_MIN, INT_MAX);
}

// main function
int main(){
    vector<int> arr = {2, 4, 3, 8, 7, 5};
    printInorder(treeFormPostOrder(arr));
	return 0;
}