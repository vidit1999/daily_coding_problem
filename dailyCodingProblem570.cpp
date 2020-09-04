#include <bits/stdc++.h>
using namespace std;

/*
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure
and node values with a subtree of s. A subtree of s is a tree consists of a node in s
and all of this node's descendants. The tree s could also be considered as a subtree of itself.
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

bool isSameTree(node* root1, node* root2){
	if(!root1 && !root2) return true; // both trees are empty then return true
	if(!root1 || !root2) return false; // only one is empty return false
	
	return (
		root1->data == root2->data && // roots have same data
		isSameTree(root1->left, root2->left) && // left trees are same
		isSameTree(root1->right, root2->right) // right trees are same
	);
}

bool isSubtreeSame(node* s, node* t){
	return (
        !t || // if the tree to check is NULL itself then return true
		isSameTree(s, t) || // t is same as s
		(s && (isSameTree(s->left, t) || isSameTree(s->right, t))) // s is not NULL and check for left tree or right tree
	);
}


// main function
int main(){
    node* t = newNode(10);
    t->left = newNode(4);
    t->right = newNode(6);
    t->left->right = newNode(30);

    printInorder(t);
    cout << "\n";

    node* s = newNode(26);
    s->left = newNode(10);
    s->right = newNode(3);
    s->left->left = newNode(4);
    s->left->right = newNode(6);
    s->left->left->right = newNode(30);
    s->right->right = newNode(3);

    printInorder(s);
    cout << "\n";

    if(isSubtreeSame(s, t))
        cout << "Yes\n";
    else
        cout << "No\n";
	return 0;
}