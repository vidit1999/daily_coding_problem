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
The bottom view of a tree, then, consists of the lowest node at each horizontal distance.
If there are two nodes at the same depth and horizontal distance, either is acceptable.

For this tree, for example, the bottom view could be [0, 1, 3, 6, 8, 9].

Given the root to a binary tree, return its bottom view.
*/

struct node{
	int data, hd;
	node *left, *right;
};

node* newNode(int data){
	node* root = new node;
	root->data = data;
	root->hd = INT_MAX;
	root->left = root->right = NULL;
	return root;
}

vector<int> bottomView(node* root){
	if(root == NULL)
        return vector<int>();
    int hd = 0;
    root->hd = hd;

    queue<node*> q;
    map<int, int> hdNodes;
    q.push(root);

    while(!q.empty()){
        node* curr = q.front();
        q.pop();

        hd = curr->hd;
        hdNodes[hd] = curr->data;

        if(curr->left){
            curr->left->hd = hd-1;
            q.push(curr->left);
        }
        if(curr->right){
            curr->right->hd = hd+1;
            q.push(curr->right);
        }
    }
    vector<int> v;
    for(auto it : hdNodes){
        v.push_back(it.second);
    }
    return v;
}

// main function
int main(){
    node *root = newNode(20); 
    root->left = newNode(8); 
    root->right = newNode(22); 
    root->left->left = newNode(5); 
    root->left->right = newNode(3); 
    root->right->left = newNode(4); 
    root->right->right = newNode(25); 
    root->left->right->left = newNode(10); 
    root->left->right->right = newNode(14);

    vector<int> ans = bottomView(root);
    for(int i : ans)
        cout << i << "\n";
	return 0;
}