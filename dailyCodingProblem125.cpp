#include <bits/stdc++.h>
using namespace std;

/*
Given the root of a binary search tree, and a target K,
return two nodes in the tree whose sum equals K.

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
	root->left = root->right = nullptr;
	return root;
}

void sumNodesHelper(node* root, int sum, pair<node*, node*>& ans, unordered_map<int, node*>& seen){
	if(root){
		if(seen.find(root->data) != seen.end()){
			ans = {root, seen[root->data]};
			return;
		}
		
		seen[sum - root->data] = root;
		
		sumNodesHelper(root->left, sum, ans, seen);
		sumNodesHelper(root->right, sum, ans, seen);
	}
}

pair<node*, node*> sumNodes(node* root, int sum){
	pair<node*, node*> ans = {nullptr, nullptr};
	unordered_map<int, node*> seen;
	sumNodesHelper(root, sum, ans, seen);
	return ans;
}

// main function
int main(){
	node* root = newNode(10);
	root->left = newNode(5);
	root->right = newNode(15);
	root->right->left = newNode(11);
	root->right->right = newNode(15);
	
	int k = 20;
	auto ans = sumNodes(root, sum);
	
	if(ans.first && ans.second)
		cout << ans.first->data << ", " << ans.second->data << "\n";
	else
		cout << "Not found.\n";
	
	return 0;
}