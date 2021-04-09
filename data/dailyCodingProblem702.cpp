#include <bits/stdc++.h>
using namespace std;

/*
Given the root to a binary tree, implement serialize(root),
which serializes the tree into a string, and deserialize(s),
which deserializes the string back into the tree.

For example, given the following Node class

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
The following test should pass:

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'
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

string serialize(node* root){
    if(!root){
        return "-1$";
    }

    auto s = to_string(root->data) + "$";
    s += serialize(root->left);
    s += serialize(root->right);

    return s;
}

node* deserializeHelper(vector<int>& arr, int& i){
    if(arr[i] == -1){
        i++;
        return nullptr;
    }

    auto root = newNode(arr[i++]);
    root->left = deserializeHelper(arr, i);
    root->right = deserializeHelper(arr, i);
    
    return root;
}

node* deserialize(string s){
    vector<int> arr;
    string temp = "";

    for(int i=0; i<s.length(); i++){
        if(s[i] == '$'){
            arr.push_back(stoi(temp));
            temp = "";
        }
        else{
            temp += s[i];
        }
    }

    int index=0;
    return deserializeHelper(arr, index);
}

// main function
int main(){
    auto root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    printInorder(root);
    cout << "\n";

    auto ser = serialize(root);
    int i = 0;

    cout << ser << "\n";

    auto des = deserialize(ser);

    printInorder(des);
    cout << "\n";

    return 0;
}