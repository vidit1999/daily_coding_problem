#include <bits/stdc++.h>
using namespace std;

/*
Write a program to merge two binary trees. Each node in
the new tree should hold a value equal to the sum of the
values of the corresponding nodes of the input trees.

If only one input tree has a node in a given position,
the corresponding node in the new tree should match that input node.
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

node* mergeTrees(node* root1, node* root2){
    if(!root1 && !root2) return nullptr;

    auto root = newNode(
        (root1 ? root1->data : 0) +
        (root2 ? root2->data : 0)
    );

    root->left = mergeTrees(
        root1 ? root1->left : nullptr,
        root2 ? root2->left : nullptr
    );
    root->right = mergeTrees(
        root1 ? root1->right : nullptr,
        root2 ? root2->right : nullptr
    );

    return root;
}

// main function
int main(){
    auto root1 = newNode(2);
    root1->left = newNode(1);
    root1->right = newNode(4);
    root1->left->left = newNode(5);

    auto root2 = newNode(3);
    root2->left = newNode(6);
    root2->right = newNode(1);
    root2->left->right = newNode(2);
    root2->right->right = newNode(7);

    printInorder(root1); cout << "\n";
    printInorder(root2); cout << "\n";
    printInorder(mergeTrees(root1, root2)); cout << "\n";
    printInorder(mergeTrees(root2, root1)); cout << "\n";

    return 0;
}
