#include <bits/stdc++.h>
using namespace std;

/*
Given a tree, find the largest tree/subtree that is a BST.
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

void printInorder(node* root){
    if(root){
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
    }
}

unordered_map<node*, bool> bstStore = {{NULL, true}};
unordered_map<node*, int> sizeStore = {{NULL, 0}};

// calculate the size of the tree
int size(node* root){
    if(sizeStore.find(root) != sizeStore.end()) // if we already have its size then resturn it
        return sizeStore[root];

    int size_root =  (!root)? 0 : (1 + size(root->left) + size(root->right));
    sizeStore[root] = size_root; // store the size
    return size_root;
}

bool checkBstUtil(node* root, int& prev){
    // if root is already stored in bstStore then return its value
    if(bstStore.find(root) != bstStore.end())
        return bstStore[root];

    if(root){
        if(
            (bstStore.find(root->left) != bstStore.end() && !bstStore[root->left]) || // if left is not bst, root is not bst
            (bstStore.find(root->right) != bstStore.end() && !bstStore[root->right]) || // if right is not bst, root is not bst
            !checkBstUtil(root->left, prev) || // check if left is bst
            root->data <= prev
        ){
            bstStore[root] = false;
            return false;
        }

        prev = root->data;

        bool ans = checkBstUtil(root->right, prev);
        bstStore[root] = ans;
        return ans;
    }

    return true;
}

bool checkBst(node* root){
    int prev = INT_MIN;
    return checkBstUtil(root, prev);
}

node* largestBSTSubtree(node* root){
    if(checkBst(root))
        return root;
    
    node *bstLeft = largestBSTSubtree(root->left), *bstRight = largestBSTSubtree(root->right);

    int size_left = size(bstLeft);
    int size_right = size(bstRight);

    return (size_left > size_right)? bstLeft : bstRight; 
}


int main(){
    node* root1 = newNode(5);
    root1->left = newNode(2);
    root1->right = newNode(4);
    root1->left->left = newNode(1);
    root1->left->right = newNode(3);

    printInorder(root1);
    cout << "\n";
    printInorder(largestBSTSubtree(root1));
    cout << "\n";

    node* root2 = newNode(50);
    root2->left = newNode(30);
    root2->left->left = newNode(5);
    root2->left->right = newNode(20);
    root2->right = newNode(60);
    root2->right->left = newNode(45);
    root2->right->right = newNode(70);
    root2->right->right->left = newNode(65);
    root2->right->right->right = newNode(80);

    printInorder(root2);
    cout << "\n";
    printInorder(largestBSTSubtree(root2));
    cout << "\n";
    return 0;
}