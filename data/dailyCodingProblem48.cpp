#include <bits/stdc++.h>
using namespace std;

/*
Given pre-order and in-order traversals of a binary tree,
write a function to reconstruct the tree.

For example, given the following preorder traversal:

[a, b, d, e, c, f, g]

And the following inorder traversal:

[d, b, e, a, f, c, g]

You should return the following tree:

    a
   / \
  b   c
 / \ / \
d  e f  g
*/

struct node{
	char data;
	node *left, *right;
};

node* newNode(char data){
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

void printPreorder(node* root){
    if(root){
        cout << root->data << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

node* constructUtil(
    int start, int end,
    int& pre_index, vector<char>& preorder,
    unordered_map<char, int>& inorder_index_map
){
    if(start > end) return nullptr;

    node* root = newNode(preorder[pre_index++]);

    int inorder_index = inorder_index_map[root->data];

    root->left = constructUtil(start, inorder_index-1, pre_index, preorder, inorder_index_map);
    root->right = constructUtil(inorder_index+1, end, pre_index, preorder, inorder_index_map);

    return root;
}

node* constructTree(vector<char> preorder, vector<char> inorder){
    unordered_map<char, int> inorder_index_map;
    for(int i=0; i<inorder.size(); i++){
        inorder_index_map[inorder[i]] = i;
    }
    int n = inorder.size(), pre_index = 0;
    return constructUtil(0, n-1, pre_index, preorder, inorder_index_map);
}

// main function
int main(){
	vector<char> preorder = {'a', 'b', 'd', 'e', 'c', 'f', 'g'};
    vector<char> inorder = {'d', 'b', 'e', 'a', 'f', 'c', 'g'};

    node* root = constructTree(preorder, inorder);

    printInorder(root); cout << "\n";
    printPreorder(root); cout << "\n";

	return 0;
}