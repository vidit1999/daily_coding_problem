#include <bits/stdc++.h>
using namespace std;

/*
Given the root of a binary tree, find the most frequent subtree sum.
The subtree sum of a node is the sum of all values under a node,
including the node itself.

For example, given the following tree:

  5
 / \
2  -5

Return 2 as it occurs twice: once as the left leaf,
and once as the sum of 2 + 5 - 5.
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

int subTreeSumHelper(node* root, unordered_map<int, int>& sum_map){
    if(!root) return 0;

    int sum = (
        root->data +
        subTreeSumHelper(root->left, sum_map) +
        subTreeSumHelper(root->right, sum_map)
    );

    sum_map[sum]++;
    
    return sum;
}

int mostFreqSubtreeSum(node* root){
    unordered_map<int, int> sum_map;
    subTreeSumHelper(root, sum_map);

    int ans = 0, freq = INT_MIN;

    for(auto it : sum_map){
        if(it.second > freq){
            ans = it.first;
        }
    }

    return ans;
}

// main function
int main(){
    auto root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(-5);

    cout << mostFreqSubtreeSum(root) << "\n";

    return 0;
}