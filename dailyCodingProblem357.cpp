#include <bits/stdc++.h>
using namespace std;

/*
You are given a binary tree in a peculiar string representation.
Each node is written in the form (lr), where l corresponds to the
left child and r corresponds to the right child.

If either l or r is null, it will be represented as a zero.
Otherwise, it will be represented by a new (lr) pair.

Here are a few examples:

A root node with no children: (00)
A root node with two children: ((00)(00))
An unbalanced tree with three consecutive left children: ((((00)0)0)0)

Given this representation, determine the depth of the tree.
*/

int depthTree(string tree){
	int depth = 0, max_depth = 0;

	for(char c : tree){
		if(c == '('){
			depth++;
		}
		else if(c == ')'){
			if(--depth < 0) return -1;
		}

		max_depth = max(depth, max_depth);
	}

	return max_depth;
}

// main function
int main(){
	cout << depthTree("(00)") << "\n";
	cout << depthTree("((00)(00))") << "\n";
	cout << depthTree("((((00)0)0)0)") << "\n";
	return 0;
}