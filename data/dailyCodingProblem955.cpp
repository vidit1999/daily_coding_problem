#include <bits/stdc++.h>
using namespace std;

/*
Suppose an arithmetic expression is given as a binary tree.
Each leaf is an integer and each internal node is one of '+', '−', '∗', or '/'.

Given the root to such a tree, write a function to evaluate it.

For example, given the following tree:

    *
   / \
  +    +
 / \  / \
3  2  4  5

You should return 45, as it is (3 + 2) * (4 + 5).
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

void printList(node* root){
    if(root){
        printList(root->left);
        cout << root->data << " ";
        printList(root->right);
    }
}

int evaluateExp(int num1, int num2, int op){
    switch(op){
        case '+' : return num1 + num2;
        case '-' : return num1 - num2;
        case '*' : return num1 * num2;
        case '/' : return num1 / num2;
        default  : return op;
    }
}

int evaluateBinaryTree(node* root){
    if(!root) return 0;

    int left = evaluateBinaryTree(root->left);
    int right = evaluateBinaryTree(root->right);

    return evaluateExp(left, right, root->data);
}

// main function
int main(){
    auto root = newNode('*');
    root->left = newNode('+');
    root->right = newNode('+');
    root->left->left = newNode(3);
    root->left->right = newNode(2);
    root->right->left = newNode(4);
    root->right->right = newNode(5);

    printList(root); cout << "\n";

    cout << evaluateBinaryTree(root) << "\n";

    return 0;
}