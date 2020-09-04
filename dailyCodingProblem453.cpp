#include <bits/stdc++.h>
using namespace std;

/*
Given the root of a binary search tree, and a target K, return two nodes in the tree whose sum equals K.

For example, given the following tree and K of 20

    10
   /   \
 5      15
       /  \
     11    15
Return the nodes 5 and 15.
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

void getInorder(node* root, vector<int>& arr){
    if(root){
        getInorder(root->left, arr);
        arr.push_back(root->data);
        getInorder(root->right, arr);
    }
}

bool isPairSum(node* root, int sum){
    vector<int> arr;
    getInorder(root, arr);

    int i=0, j=arr.size()-1;

    while(j > i){
        if(arr[i] + arr[j] == sum)
            return true;
        if(arr[i] + arr[j] < sum)
            i++;
        else
            j--;
    }

    return false;
}

// main function
int main(){
    node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->right->left = newNode(11);
    root->right->right = newNode(15);

    if(isPairSum(root, 35))
        cout << "Yes\n";
    else
        cout << "No\n";
	return 0;
}