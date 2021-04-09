#include <bits/stdc++.h>
using namespace std;

/*
Given a binary search tree, find the floor and ceiling of a given integer.
The floor is the highest element in the tree less than or equal to an integer,
while the ceiling is the lowest element in the tree greater than or equal to an integer.

If either value does not exist, return None.
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

void floorCeilHelper(node* root, int num, node* &flr, node* &cel){
    while(root){
        if(root->data == num){
            flr = cel = root;
            break;
        }
        else if(root->data > num){
            cel = root;
            root = root->left;
        }
        else{
            flr = root;
            root = root->right;
        }
    }
}

pair<int, int> floorCeil(node* root, int num){
    node *flr = nullptr, *cel = nullptr;
    floorCeilHelper(root, num, flr, cel);
    if(flr && cel)
        return {flr->data, cel->data};
    return {-1, -1};
}

// main function
int main(){
	node* root = newNode(8);
    root->left = newNode(4);
    root->right = newNode(10);
    root->left->left = newNode(2);
    root->left->right = newNode(6);
    root->right->left = newNode(9);
    root->right->right = newNode(12);

	printInorder(root);
    cout << "\n\n";
    for(int i=1;i<=15;i++){
        auto ans = floorCeil(root, i);
        cout << i << " -- " << ans.first << ", " << ans.second << "\n";
    }
	return 0;
}