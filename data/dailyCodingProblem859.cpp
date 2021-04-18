#include <bits/stdc++.h>
using namespace std;

/*
The horizontal distance of a binary tree node describes
how far left or right the node will be when the tree is printed out.

More rigorously, we can define it as follows:

The horizontal distance of the root is 0.
The horizontal distance of a left child is hd(parent) - 1.
The horizontal distance of a right child is hd(parent) + 1.
For example, for the following tree, hd(1) = -2, and hd(6) = 0.

             5
          /     \
        3         7
      /  \      /   \
    1     4    6     9
   /                /
  0                8

The bottom view of a tree, then, consists of the lowest node
at each horizontal distance. If there are two nodes at the
same depth and horizontal distance, either is acceptable.

For this tree, for example, the bottom view could be [0, 1, 3, 6, 8, 9].

Given the root to a binary tree, return its bottom view.
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

void bottomViewHelper(node* root, map<int, int>& m, int hd){
    if(root){
        m[hd] = root->data;

        bottomViewHelper(root->left, m, hd-1);
        bottomViewHelper(root->right, m, hd+1);
    }
}

vector<int> bottomView(node* root){
    vector<int> ans;
    map<int, int> m;

    bottomViewHelper(root, m, 0);

    for(auto it : m){
        ans.push_back(it.second);
    }

    return ans;
}

// main function
int main(){
    auto root = newNode(5);
    root->left = newNode(3);
    root->left->left = newNode(1);
    root->left->left->left = newNode(0);
    root->left->right = newNode(4);
    root->right = newNode(7);
    root->right->left = newNode(6);
    root->right->right = newNode(9);
    root->right->right->left = newNode(8);

    printInorder(root); cout << "\n";

    for(int i : bottomView(root)){
        cout << i << " ";
    }
    cout << "\n";
    
    return 0;
}