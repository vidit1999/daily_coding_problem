#include <bits/stdc++.h>
using namespace std;

/*
Given two non-empty binary trees s and t,
check whether tree t has exactly the same
structure and node values with a subtree of s.
A subtree of s is a tree consists of a node in
s and all of this node's descendants. The tree
s could also be considered as a subtree of itself.
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

bool isSame(node* r1, node* r2){
    if(!r1 && !r2) return true;
    if(!r1 || !r2) return false;

    return (
        r1->data == r2->data &&
        isSame(r1->left, r2->left) &&
        isSame(r1->right, r2->right)
    );
}

bool isSubtreeSame(node* s, node* t){
    if(!t) return true;
    if(!s) return false;

    return (
        isSame(s, t) ||
        isSubtreeSame(s->left, t) ||
        isSubtreeSame(s->right, t)
    );
}

// main function
int main(){
    node* t = newNode(10);
    t->left = newNode(4);
    t->right = newNode(6);
    t->left->right = newNode(30);

    node* s = newNode(26);
    s->left = newNode(10);
    s->left->left = newNode(4);
    s->left->right = newNode(6);
    s->left->left->right = newNode(30);
    s->right = newNode(3);
    s->right->right = newNode(3);

    printInorder(t); cout << "\n";
    printInorder(s); cout << "\n";

    cout << isSubtreeSame(s, t) << "\n";

    return 0;
}