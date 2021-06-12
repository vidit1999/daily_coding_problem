#include <bits/stdc++.h>
using namespace std;

/*
Two nodes in a binary tree can be called cousins if
they are on the same level of the tree but have different parents.
For example, in the following diagram 4 and 6 are cousins.

    1
   / \
  2   3
 / \   \
4   5   6

Given a binary tree and a particular node,
find all cousins of that node.
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

vector<node*> cousionsNode(node* root, node* nd){
    if(nd == nullptr || root == nd) return {};

    bool found = false;
    vector<node*> ans;
    queue<node*> q({root});

    while(!q.empty()){
        int size = q.size();
        
        while(size--){
            auto f = q.front();
            q.pop();

            if(f->left == nd || f->right == nd){
                found = true;
            } else {
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
        }

        if(found){
            while(!q.empty()){
                ans.push_back(q.front());
                q.pop();
            }
            break;
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
    root->right->right = newNode(6);

    printInorder(root); cout << "\n";

    for(auto nd : cousionsNode(root, root->right->right)){
        cout << nd->data << "\n";
    }

    return 0;
}