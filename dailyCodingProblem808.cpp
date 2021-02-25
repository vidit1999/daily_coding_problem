#include <bits/stdc++.h>
using namespace std;

/*
Typically, an implementation of in-order traversal
of a binary tree has O(h) space complexity, where h
is the height of the tree. Write a program to compute
the in-order traversal of a binary tree using O(1) space.
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

void printInorderConstant(node* root){
    while(root){
        if(!root->left){
            cout << root->data << " ";
            root = root->right;
        }
        else{
            auto prev = root->left;

            while(prev->right && prev->right != root){
                prev = prev->right;
            }

            if(!prev->right){
                prev->right = root;
                root = root->left;
            }
            else{
                prev->right = nullptr;
                cout << root->data << " ";
                root = root->right;
            }
        }
    }
}

// main function
int main(){
    auto root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    printInorder(root); cout << "\n";
    printInorderConstant(root); cout << "\n";

    return 0;
}
