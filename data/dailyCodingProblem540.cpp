#include <bits/stdc++.h>
using namespace std;

/*
In Ancient Greece, it was common to write text with the first line going left to right, the second line going right to left, and continuing to go back and forth. This style was called "boustrophedon".

Given a binary tree, write an algorithm to print the nodes in boustrophedon order.

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
    node* root = new node;
    root->data = data;
    root->right = root->left = NULL;
    return root;
}

vector<int> boustrophedonOrderPrint(node* root){
    if(root == NULL)
        return {};
    
    stack<node*> s1, s2;
    vector<int> ans;
    s1.push(root);

    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            node* temp = s1.top();
            s1.pop();
            ans.push_back(temp->data);
            
            if(temp->left)
                s2.push(temp->left);
            if(temp->right)
                s2.push(temp->right);
        }
        while(!s2.empty()){
            node* temp = s2.top();
            s2.pop();
            ans.push_back(temp->data);
            
            if(temp->right)
                s1.push(temp->right);
            if(temp->left)
                s1.push(temp->left);
        }
    }

    return ans;
}

// main function
int main(){
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    for(int i : boustrophedonOrderPrint(root))
        cout << i << "\n";
	return 0;
}