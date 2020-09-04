#include <bits/stdc++.h>
using namespace std;

/*
Print the nodes in a binary tree level-wise. For example, the following should print 1, 2, 3, 4, 5.

  1
 / \
2   3
   / \
  4   5
*/

struct node{
    int data;
    node *left, *right;
};

node* newNode(int data){
    node* root = new node;
    root->data = data;
    root->left = root->right = nullptr;
    return root;
}

void levelOrderTraversal(node* root){
    if(!root) return;

    queue<node*> q({root});

    while(!q.empty()){
        node* f = q.front(); q.pop();
        cout << f->data << " ";
        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
    }

    cout << "\n";
}

// main function
int main(){
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);

    levelOrderTraversal(root);
    
	return 0;
}