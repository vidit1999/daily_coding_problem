#include <bits/stdc++.h>
using namespace std;

/*
Recall that a full binary tree is one in which each node is either a leaf node, or has two children.
Given a binary tree, convert it to a full one by removing nodes with only one child.

For example, given the following tree:

         0
      /     \
    1         2
  /            \
3                 4
  \             /   \
    5          6     7

You should convert it to:

     0
  /     \
5         4
        /   \
       6     7
*/

struct node{
    int data;
    node *right, *left;
};


node* newNode(int data){
    node* root = new node;
    root->data = data;
    root->right = root->left = NULL;
    return root;
}


node* removeHalfNode(node* root){
    if(root == NULL)
        return NULL;
    root->left = removeHalfNode(root->left);
    root->right = removeHalfNode(root->right);

    if(root->left == NULL && root->right == NULL)
        return root;
    if(root->left == NULL){
        node* temp = root->right;
        delete root;
        return temp;
    }
    if(root->right == NULL){
        node* temp = root->left;
        delete root;
        return temp;
    }
    return root;
}


void printTree(node* root){
    if(root){
        printTree(root->left);
        cout << root->data << " -- ";
        printTree(root->right);
    }
}

// main function
int main(){
    node* root = newNode(0);
    root->left = newNode(1);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->left->right = newNode(5);
    root->right->right = newNode(4);
    root->right->right->left = newNode(6);
    root->right->right->right = newNode(7);

    printTree(root);
    cout << "\n\n";
    root = removeHalfNode(root);
    printTree(root);
    cout << "\n\n";
    return 0;
}