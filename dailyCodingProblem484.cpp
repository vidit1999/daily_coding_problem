#include <bits/stdc++.h>
using namespace std;

/*
Given the root to a binary search tree, find the second largest node in the tree.
*/

struct node{
    int data;
    node *left, *right;
};

// create a node
node* newNode(int data){
    node* root = new node;
    root->data = data;
    root->left = root->right = NULL;
    return root;
}

// create a node using data and insert it in a tree
// according to its position
node* insert(node* root, int data){
    if(root == NULL)
        return newNode(data);
    if(data < root->data)
        root->left =  insert(root->left, data);
    else if(data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// reverse Inorder tree helper
// takes root node and a vector and stores the data in a vector
void reverseInorderHelper(node* root, int& c, int& ans){
    if(root == NULL || c >= 2)
        return;
    reverseInorderHelper(root->right, c, ans);
    if(++c == 2){
        ans = root->data;
        return;
    }
    reverseInorderHelper(root->left, c, ans);
}

// reverse inorder traversal
// returns a vector
int reverseInorder(node* root){
    int ans, c = 0;
    reverseInorderHelper(root, c, ans);
    return ans;
}

// main function
int main(){
    node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80);

    cout << reverseInorder(root) << "\n";
    return 0;
}