#include <bits/stdc++.h>
using namespace std;

/*
Given the root of a binary tree,
return a deepest node.
For example, in the following tree, return d.

    a
   / \
  b   c
 /
d
*/

struct node{
    char data;
    node *left, *right;
};

node* newNode(char data){
    auto root = new node;
    root->data = data;
    root->left = root->right = nullptr;
    return root;
}

node* deepestNode(node* root){
    node* deepest = nullptr;
    queue<node*> q({root});

    while(!q.empty()){
        deepest = q.front(); q.pop();

        if(deepest->left) q.push(deepest->left);
        if(deepest->right) q.push(deepest->right);
    }

    return deepest;
}

// main function
int main(){
    auto root = newNode('a');
    root->left = newNode('b');
    root->right = newNode('c');
    root->left->left = newNode('d');

    auto deepest = deepestNode(root);
    
    if(deepest){
        cout << deepest->data << "\n";
    } else {
        cout << "Tree empty\n";
    }
    return 0;
}