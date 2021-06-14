#include <bits/stdc++.h>
using namespace std;

/*
Given a complete binary tree, count the number of nodes in faster than O(n) time.
Recall that a complete binary tree has every level filled except the last,
and the nodes in the last level are filled starting from the left
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

int leftOrRightHeight(node* root, bool left){
    int height = 0;

    while(root){
        height++;
        root = left ? root->left : root->right;
    }

    return height;
}

int countNodesComplete(node* root){
    if(!root) return 0;

    int left_height = leftOrRightHeight(root, true);
    int right_height = leftOrRightHeight(root, false);

    if(left_height == right_height) return (1 << left_height) - 1;

    return 1 + countNodesComplete(root->left) + countNodesComplete(root->right);
}


// main function
int main(){
    auto root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);
    root->right->left->left = newNode(12);

    printInorder(root); cout << "\n";

    cout << countNodesComplete(root) << "\n";
    
    return 0;
}