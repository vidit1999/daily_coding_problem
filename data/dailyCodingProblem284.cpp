#include <bits/stdc++.h>
using namespace std;

/*
Two nodes in a binary tree can be called cousins if they are on the same
level of the tree but have different parents. For example,
in the following diagram 4 and 6 are cousins.

    1
   / \
  2   3
 / \   \
4   5   6
Given a binary tree and a particular node, find all cousins of that node.
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

vector<int> cousins(node* root, node* cousin_find){
	queue<node*> q;
	q.push(root);
	bool found = false;
	
	while(!q.empty() && !found){
		int sz = q.size();
		while(sz--){
			node* fr = q.front();
			q.pop();
			
			if(
				(fr->left == cousin_find) ||
				(fr->right == cousin_find)
			){
				found = true;
			}
			else{
				if(fr->left)
					q.push(fr->left);
				if(fr->right)
					q.push(fr->right);
			}
		}
	}
	
	vector<int> ans;
	if(found){
		while(!q.empty()){
			ans.push_back(q.front()->data);
			q.pop();
		}
	}
	
	return ans;
}

// main function
int main(){
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->right = newNode(6);

    for(int i : cousins(root, root->right->right))
        cout << i << "\n";
	return 0;
}