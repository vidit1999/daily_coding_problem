#include <bits/stdc++.h>
using namespace std;

/*
Given a binary search tree, find the floor and ceiling of a given integer.
The floor is the highest element in the tree less than or equal to an integer,
while the ceiling is the lowest element in the tree greater than or equal to an integer.

If either value does not exist, return None.

       7
    /    \
   5      10
 /  \     /  \
3    6   8   12

floor of 9 = 8
ceiling of 9 = 10

floor of 14 = 12
ceiling of 14 = does not exist
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

void treeToVec(node* root, vector<int>& v){
	if(root){
		treeToVec(root->left, v);
		v.push_back(root->data);
		treeToVec(root->right, v);
	}
}

pair<int, int> floorCeiling(int number, node* root){
    vector<int> sortedArray;
    treeToVec(root, sortedArray);

    int floor = INT_MIN, ceiling = INT_MAX;

    for(int i=0;i<sortedArray.size();i++){
        if(sortedArray[i] <= number)
            floor = max(sortedArray[i], floor);
        if(sortedArray[i] >= number)
            ceiling = min(sortedArray[i], ceiling);
    }
    
    if(floor == INT_MIN || ceiling == INT_MAX) return {INT_MIN, INT_MAX};
    
    return {floor, ceiling};
}

void testFunc(vector<int> v, node* root){
    for(int i : v){
        auto ans = floorCeiling(i, root);
        cout << ans.first << " -- " << ans.second << "\n";
    }
}

// main function
int main(){
    node* root = newNode(7);
    root->left = newNode(5);
    root->right = newNode(10);
    root->left->left = newNode(3);
    root->left->right = newNode(6);
    root->right->left = newNode(8);
    root->right->right = newNode(12);

    testFunc({9, 14, 4, 1}, root);
	return 0;
}