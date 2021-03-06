#include <bits/stdc++.h>
using namespace std;

/*
In Ancient Greece, it was common to write text with
the first line going left to right, the second line
going right to left, and continuing to go back and forth.
This style was called "boustrophedon".

Given a binary tree, write an algorithm to print
the nodes in boustrophedon order.

For example, given the following tree:

       1
    /     \
  2         3
 / \       / \
4   5     6   7

You should return [1, 3, 2, 4, 5, 6, 7].
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

vector<int> boustrophedonOrder(node* root){
    vector<int> ans;
    stack<node*> s1, s2;
    s1.push(root);

    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            auto t = s1.top(); s1.pop();
            ans.push_back(t->data);

            if(t->left) s2.push(t->left);
            if(t->right) s2.push(t->right);
        }

        while(!s2.empty()){
            auto t = s2.top(); s2.pop();
            ans.push_back(t->data);

            if(t->right) s1.push(t->right);
            if(t->left) s1.push(t->left);
        }
    }

    return ans;
}

// main function
int main(){
    auto root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    auto ans = boustrophedonOrder(root);

    for(int i : ans){
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}
