#include <bits/stdc++.h>
using namespace std;

/*
Given an integer N, construct all possible binary search trees with N nodes.
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

void printPreorder(node* root){
	if(root){
		cout << root->data << " ";
		printPreorder(root->left);
		printPreorder(root->right);
	}
}

vector<node*> createAllPossibleBst(int start, int end){
	vector<node*> bsts;
	
	if(start > end){
		bsts.push_back(nullptr);
		return bsts;
	}
	
	for(int i=start; i<=end; i++){
		auto leftTree = createAllPossibleBst(start, i-1);
		auto rightTree = createAllPossibleBst(i+1, end);
		
		for(auto lnode : leftTree){
			for(auto rnode : rightTree){
				node* root = newNode(i);
				root->left = lnode;
				root->right = rnode;
				bsts.push_back(root);
			}
		}
	}
	
	return bsts;
}

// main function
int main(){
	for(auto root : createAllPossibleBst(1, 3)){
		printPreorder(root);
		cout << "\n";
	}
	return 0;
}