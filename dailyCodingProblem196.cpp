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
	node* root = new node;
	root->data = data;
	root->left = root->right = nullptr;
	return root;
}

int sumNodes(node* root, unordered_map<int, int>& sum_count){
    if(root == nullptr) return 0;

    int sum = root->data + sumNodes(root->left, sum_count) + sumNodes(root->right, sum_count);

    sum_count[sum]++;
    
    return sum;
}

int mostFreqSubtreeSum(node* root){
    unordered_map<int, int> sum_count;
    sumNodes(root, sum_count);

    int max_sum = INT_MIN, ans = INT_MIN;

    for(auto it : sum_count){
        if(it.second > max_sum){
            max_sum = it.second;
            ans = it.first;
        }
	}

    return ans;
}

// main function
int main(){
    node* root = newNode(5);
    root->left = newNode(2);
    root->right = newNode(-5);

    cout << mostFreqSubtreeSum(root) << "\n";
	return 0;
}