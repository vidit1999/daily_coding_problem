#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree, determine whether or not it is height-balanced.
A height-balanced binary tree can be defined as one in which the heights
of the two subtrees of any node never differ by more than one.
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

bool isHeightBalancedHelper(node* root, int& height){
    if(!root){
        height = 0;
        return true;
    }
    
    int lh = 0, rh = 0;
    
    bool left_balanced = isHeightBalancedHelper(root->left, lh);
    bool right_balanced = isHeightBalancedHelper(root->right, rh);
    
    height = max(lh, rh) + 1;
    
    return (abs(lh - rh) <= 1) && left_balanced && right_balanced; 
}

bool isHeightBalanced(node* root){
    int height = 0;
    return isHeightBalancedHelper(root, height);
}

// main function
int main(){
    auto root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    
    cout << isHeightBalanced(root1) << "\n";
    
    auto root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->left->left = newNode(5);
    
    cout << isHeightBalanced(root2) << "\n";
    
    return 0;
}