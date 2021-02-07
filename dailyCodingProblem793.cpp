#include <bits/stdc++.h>
using namespace std;

/*
Recall that a full binary tree is one in which each node
is either a leaf node, or has two children. Given a binary tree,
convert it to a full one by removing nodes with only one child.

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
    node *left, *right;
};

node* newNode(int data){
    auto root = new node;
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

node* fullPruning(node* root){
    if(!root){
        return nullptr;
    }
    
    root->left = fullPruning(root->left);
    root->right = fullPruning(root->right);
    
    if(!root->left && !root->right) return root;
    if(!root->left) return root->right;
    if(!root->right) return root->left;
    
    return root;
}

// main function
int main(){
    auto root = newNode(0);
    root->left = newNode(1);
    root->left->left = newNode(3);
    root->left->left->right = newNode(5);
    root->right = newNode(2);
    root->right->right = newNode(4);
    root->right->right->left = newNode(6);
    root->right->right->right = newNode(7);
    
    printInorder(root); cout << "\n";
    printInorder(fullPruning(root)); cout << "\n";
    return 0;
}