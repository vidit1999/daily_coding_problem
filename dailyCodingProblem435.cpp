#include <bits/stdc++.h>
using namespace std;

/*
Given pre-order and in-order traversals of a binary tree, write a function to reconstruct the tree.

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
	root->left = root->right = NULL;
	return root;
}

void printInorder(node* root){
	if(root){
		printInorder(root->left);
		cout << root->data << "\n";
		printInorder(root->right);
	}
}

node* constructBinTreeHelper(int start, int end, int& preindex, vector<char> preOrder, unordered_map<char, int> m){
	if(start > end) return NULL;
	
	node* root = newNode(preOrder[preindex++]);
	int index = m[root->data];
	
	root->left = constructBinTreeHelper(start, index-1, preindex, preOrder, m);
	root->right = constructBinTreeHelper(index+1, end, preindex, preOrder, m);
	
	return root;
}

node* constructBinTree(vector<char> preOrder, vector<char> inOrder){
	int n = inOrder.size();
	unordered_map<char, int> m;
	
	for(int i=0;i<n;i++)
		m[inOrder[i]] = i;
	
    int preIndex = 0;
	return constructBinTreeHelper(0, n-1, preIndex, preOrder, m);
}

// main function
int main(){
    printInorder(constructBinTree(
        {'a', 'b', 'd', 'e', 'c', 'f', 'g'},
        {'d', 'b', 'e', 'a', 'f', 'c', 'g'}
    ));
	return 0;
}