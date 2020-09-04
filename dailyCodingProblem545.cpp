#include <bits/stdc++.h>
using namespace std;

/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
Assume that each node in the tree also has a pointer to its parent.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined
between two nodes v and w as the lowest node in T that has both v and w as descendants
(where we allow a node to be a descendant of itself).”
*/

struct node{
    int data;
    node *left, *right, *parent;
};

node* newNode(int data, node* parent){
    node* root = new node;
    root->data = data;
    root->left = root->right = NULL;
    root->parent = parent;
    return root;
}

node* lca(node* n1, node* n2){
    unordered_set<node*> rootPath;
    while(n1){
        rootPath.insert(n1);
        n1 = n1->parent;
    }

    while(n2){
        if(rootPath.find(n2) != rootPath.end())
            return n2;
        n2 = n2->parent;
    }

    return NULL;
}

// main function
int main(){
    node* root = newNode(20, NULL);
    root->left = newNode(8, root);
    root->right = newNode(22, root);
    root->left->left = newNode(4, root->left);
    root->left->right = newNode(12, root->left);
    root->left->right->left = newNode(10, root->left->right);
    root->left->right->right = newNode(14, root->left->right);

    cout << lca(root->left->right->left, root->right)->data << "\n";
	return 0;
}