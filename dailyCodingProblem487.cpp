#include <bits/stdc++.h>
using namespace std;

/*
Two nodes in a binary tree can be called cousins if they are
on the same level of the tree but have different parents.

For example, in the following diagram 4 and 6 are cousins.

    1
   / \
  2   3
 / \   \
4   5   6

Given a binary tree and a particular node, find all cousins of that node.
*/

struct node{
    int data;
    node *left, *right;
};

node* newNode(int data){
    node* root = new node;
    root->data = data;
    root->left = root->right = NULL;
    return root;
}

vector<int> cousins(node* root, node* givenNode){
    if(givenNode == root || root->left == givenNode || root->right == givenNode)
        return vector<int>();
    queue<node*> q;
    bool found = false;
    int size;
    q.push(root);
    while(!q.empty() && !found){
        size = q.size();
        while(size){
            node* p = q.front();
            q.pop();
            if(p->left == givenNode || p->right == givenNode)
                found = true;
            else{
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
            }
            size--;
        }
    }
    if(found)
        if(q.size() > 0){
            vector<int> v;
            while(!q.empty()){
                v.push_back(q.front()->data);
                q.pop();
            }
            return v;
        }
    return vector<int>();
}

// main function
int main(){
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    vector<int> c = cousins(root, root->right->right);
    for(int i : c)
        cout << i << "\n";
	return 0;
}