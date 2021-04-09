#include <bits/stdc++.h>
#define K 3
using namespace std;

/*
A tree is symmetric if its data and shape remain unchanged when it is
reflected about the root node. The following tree is an example:

        4
      / | \
    3   5   3
  /           \
9              9

Given a k-ary tree, determine whether it is symmetric.
*/

struct node{
	int data;
	node* children[K];
};

node* newNode(int data){
	node* root = new node;
	root->data = data;
	for(int i=0; i<K; i++)
        root->children[i] = nullptr;
	return root;
}

bool isSymmetricUtil(node* root1, node* root2){
    if(!root1 && !root2) return true;

    if(root1 && root2 && root1->data == root2->data){
        for(int i=0; i<K; i++){
            if(!isSymmetricUtil(root1->children[i], root2->children[K-1-i]))
                return false;
        }
        return true;
    }
    return false;
}

bool isSymmetric(node* root){
    return isSymmetricUtil(root, root);
}

// main function
int main(){
    node* root = newNode(4);
    root->children[0] = newNode(3);
    root->children[1] = newNode(5);
    root->children[2] = newNode(3);
    root->children[0]->children[0]= newNode(9);
    root->children[2]->children[2] = newNode(9);

    if(isSymmetric(root))
        cout << "Yes\n";
    else
        cout << "No\n";
	return 0;
}