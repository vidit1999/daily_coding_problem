#include <bits/stdc++.h>
using namespace std;

/*
Write a program to merge two binary trees. Each node in the new tree should hold a
value equal to the sum of the values of the corresponding nodes of the input trees.

If only one input tree has a node in a given position, the corresponding node in
the new tree should match that input node.

Input: 
	 Tree 1            Tree 2                  
	   2                 3                             
	  / \               / \                            
	 1   4             6   1                        
	/                   \   \                      
   5                     2   7                  

Output: Merged tree:
	 5
	/ \
   7   5
  / \   \ 
 5   2   7

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

void printInorder(node* root){
	if(root){
		printInorder(root->left);
		cout << root->data << " ";
		printInorder(root->right);
	}
}

node* mergeTrees(node* a, node* b){
	if(a || b){
		node* root = newNode(
			((a)? a->data : 0) +
			((b)? b->data : 0)
		);
		
		root->left = mergeTrees(
			(a)? a->left : nullptr ,
			(b)? b->left : nullptr
		);
		
		root->right = mergeTrees(
			(a)? a->right : nullptr ,
			(b)? b->right : nullptr
		);
		
		return root;
	}
	return nullptr;
}

// main function
int main(){
	node* a = newNode(2);
    a->left = newNode(1);
    a->right = newNode(4);
    a->left->left = newNode(5);

    node* b = newNode(3);
    b->left = newNode(6);
    b->right = newNode(1);
    b->left->right = newNode(2);
    b->right->right = newNode(7);

    printInorder(a);
    cout << "\n";

    printInorder(b);
    cout << "\n";

    printInorder(mergeTrees(a, b));
    cout << "\n";

    printInorder(a);
    cout << "\n";

    printInorder(b);
    cout << "\n";
	
	return 0;
}