#include <bits/stdc++.h>
using namespace std;

/*
The horizontal distance of a binary tree node describes how far left or right the
node will be when the tree is printed out.

More rigorously, we can define it as follows:

The horizontal distance of the root is 0.
The horizontal distance of a left child is hd(parent) - 1.
The horizontal distance of a right child is hd(parent) + 1.
For example, for the following tree, hd(1) = -2, and hd(6) = 0.

             5
          /     \
        3         7
      /  \      /   \
    1     4    6     9
   /                /
  0                8
The bottom view of a tree, then, consists of the lowest node at each
horizontal distance. If there are two nodes at the same depth and
horizontal distance, either is acceptable.

For this tree, for example, the bottom view could be [0, 1, 3, 6, 8, 9].

Given the root to a binary tree, return its bottom view.
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

void bottomViewUtil(node* root, int dist, int level, map<int, pair<int, int>>& m){
	if(root){
		if(level >= m[dist].second){
			m[dist] = {root->data, level};
		}
		
		bottomViewUtil(root->left, dist-1, level+1, m);
		bottomViewUtil(root->right, dist+1, level+1, m);
	}
}

void printBottomView(node* root){
	/*
	m.first = horizontal distance
	m.second.first = value
	m.second.second = level
	*/
	map<int, pair<int, int>> m;
	bottomViewUtil(root, 0, 0, m);
	
	for(auto it : m)
		cout << it.second.first << " ";
	cout << "\n";
}

// main function
int main(){
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(5);
	root->right->right = newNode(6);
	root->right->left->left = newNode(7);
	root->right->left->right = newNode(8);
	printBottomView(root);
	return 0;
}