#include <bits/stdc++.h>
using namespace std;

/*
Given the sequence of keys visited by a postorder traversal of a binary search tree, reconstruct the tree.

For example, given the sequence 2, 4, 3, 8, 7, 5, you should construct the following tree:

    5
   / \
  3   7
 / \   \
2   4   8
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

node* fromPostOrderHelper(int arr[], int* postIndex, int key, int max, int min){
    if(*postIndex < 0)
        return nullptr;
    node* root = nullptr;
    
    if(key > min && key < max){
        root = newNode(key);
        *postIndex = *postIndex - 1;

        if(*postIndex >= 0){
            root->left = fromPostOrderHelper(arr, postIndex, arr[*postIndex], key, min);
            root->right = fromPostOrderHelper(arr, postIndex, arr[*postIndex], max, key);
        }
    }

    return root;
}

node* fromPostOrder(int arr[], int n){
    int postIndex = n-1;
    return fromPostOrderHelper(arr, &postIndex, arr[postIndex], INT_MAX, INT_MIN);
}

void printTree(node* root){
    if(root){
        printTree(root->left);
        cout << root->data << " ";
        printTree(root->right);
    }
}

// main function
int main(){
    int arr[] = {1, 7, 5, 50, 40, 10};
    int n =sizeof(arr)/sizeof(arr[0]);

    printTree(fromPostOrder(arr, n));
    return 0;
}