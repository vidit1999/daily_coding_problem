#include <bits/stdc++.h>
using namespace std;

/*
Implement locking in a binary tree. A binary tree node can be
locked or unlocked only if all of its descendants or ancestors are not locked.

Design a binary tree node class with the following methods:

is_locked, which returns whether the node is locked

lock, which attempts to lock the node. If it cannot be locked,
then it should return false. Otherwise, it should lock it and return true.

unlock, which unlocks the node. If it cannot be unlocked, then it should return false.
Otherwise, it should unlock it and return true.

You may augment the node to add parent pointers or any other property you would like.
You may assume the class is used in a single-threaded program, so there is no need for
actual locks or mutexes. Each method should run in O(h),
where h is the height of the tree.
*/

struct node{
    int data;
    node *left, *right, *parent;
    bool is_locked;
    int count_locked_descendants;
};

node* newNode(int data){
    auto root = new node;
    root->data = data;
    root->left = root->right = root->parent = nullptr;
    root->is_locked = false;
    root->count_locked_descendants = 0;
    return root;
}

void printTree(node* root){
    if(!root) return;
    
    queue<node*> q({root});

    while(!q.empty()){
        auto f = q.front(); q.pop();

        cout << f->data << ", " << f->is_locked << ", " << f->count_locked_descendants << "\n";

        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
    }
}

bool canLockUnlock(node* root){
    if(root->count_locked_descendants > 0) return false;

    node* curr = root->parent;

    while(curr){
        if(curr->is_locked) return false;
        curr = curr->parent;
    }

    return true;
}

bool is_locked(node* root){
    return root->is_locked;
}

bool lock(node* root){
    if(canLockUnlock(root)){
        root->is_locked = true;

        node* curr = root->parent;

        while(curr){
            curr->count_locked_descendants++;
            curr = curr->parent;
        }

        return true;
    }

    return false;
}

bool unlock(node* root){
    if(canLockUnlock(root)){
        root->is_locked = false;

        node* curr = root->parent;

        while(curr){
            curr->count_locked_descendants--;
            curr = curr->parent;
        }

        return true;
    }

    return false;
}

// main function
int main(){
    auto root = newNode(1);
    root->parent = nullptr;
    
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->parent = root->left->parent = root;
    
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->parent = root->left->right->parent = root->left;

    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->parent = root->right->right->parent = root->right;

    printTree(root);

    cout << lock(root) << "\n";
    cout << lock(root->left) << "\n";
    cout << unlock(root) << "\n";
    cout << lock(root->right) << "\n";

    printTree(root);
    
    return 0;
}