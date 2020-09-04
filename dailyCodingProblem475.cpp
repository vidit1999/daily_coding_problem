#include <bits/stdc++.h>
using namespace std;

/*
Implement locking in a binary tree. A binary tree node can be locked or unlocked only if all of its descendants or ancestors are not locked.

Design a binary tree node class with the following methods:
is_locked, which returns whether the node is locked
lock, which attempts to lock the node. If it cannot be locked, then it should return false. Otherwise, it should lock it and return true.
unlock, which unlocks the node. If it cannot be unlocked, then it should return false. Otherwise, it should unlock it and return true.

You may augment the node to add parent pointers or any other property you would like.
You may assume the class is used in a single-threaded program,
so there is no need for actual locks or mutexes. Each method should run in O(h), where h is the height of the tree.
*/

class node{
	public:
	
	int data;
    node* parent;
	node *left, *right;
    bool isLock; // true for locked and false for unlocked

    node(int data, node* parent=NULL){
        this->data = data;
        this->parent = parent;
        this->left = this->right = NULL;
        this->isLock = false;
    }

    bool is_locked(){
        return this->isLock;
    }

    bool lock(){
        if(!isLockable())
            return false;
        this->isLock = true;
        return true;
    }

    bool unlock(){
        if(!isLockable())
            return false;
        this->isLock = false;
        return true;
    }

    friend bool isAncesterUnlocked(node* root);
    friend bool isDescendentUnlocked(node* root);
    private:
    bool isLockable(){
        return isAncesterUnlocked(this) && isDescendentUnlocked(this->left) && isDescendentUnlocked(this->right);
    }
    
};

// chekc if all ancesters are unlocked or not
// returns true if all are unlocked else false
bool isAncesterUnlocked(node* root){
    while(root->parent){
        if(root->parent->isLock){
            return false;
        }
        root = root->parent;
    }
    return true;
}

bool isDescendentUnlocked(node* root){
    if(root){
        return !root->isLock && isDescendentUnlocked(root->left) && isDescendentUnlocked(root->right);
    }
    return true;
}

void printTree(node* root){
    if(root){
        printTree(root->left);
        cout << root->data << " -- locked : ";
        if(root->is_locked())
            cout << "True\n";
        else
            cout << "False\n";
        printTree(root->right);
    }
}

/*
       1
    2     3
  4  5   6  7
*/


// main function
int main(){
    node root(1);
    node lc1(2,&root);
    root.left = &lc1;
    node rc1(3,&root);
    root.right = &rc1;
    node lc2(4,&lc1);
    lc1.left = &lc2;
    node rc2(5,&lc1);
    lc1.right = &rc2;
    node lc3(6,&rc1);
    rc1.left = &lc3;
    node rc3(7,&rc1);
    rc1.right = &rc3;
    printTree(&root);

    root.lock();
    lc1.lock();
    rc1.lock();
    cout << "\n-------\n";
    printTree(&root);
	return 0;
}