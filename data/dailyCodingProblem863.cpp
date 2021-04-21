#include <bits/stdc++.h>
using namespace std;

/*
Generate a finite, but an arbitrarily large binary tree quickly in O(1).

That is, generate() should return a tree whose size is unbounded but finite.
*/

struct node{
    node *left, *right;
};

node* newNode(){
    auto root = new node;
    root->left = root->right = nullptr;
    return root;
}

int height(node* root){
    if(!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

node* generate(){
    if(rand()%2){
        node* root = newNode();
        
        root->left = generate();
        root->right = generate();

        return root;
    }
    return nullptr;
}

// main function
int main(){
    srand(time(0));
    for(int i=0; i<5; i++){
        cout << height(generate()) << "\n";
    }
    return 0;
}