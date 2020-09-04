#include <bits/stdc++.h>
using namespace std;

/*
Huffman coding is a method of encoding characters based on their frequency.
Each letter is assigned a variable-length binary string, such as 0101 or 111110,
where shorter lengths correspond to more common letters. To accomplish this,
a binary tree is built such that the path from the root to any leaf uniquely
maps to a character. When traversing the path, descending to a left child
corresponds to a 0 in the prefix, while descending right corresponds to 1.

Here is an example tree (note that only the leaf nodes have letters):

        *
      /   \
    *       *
   / \     / \
  *   a   t   *
 /             \
c               s

With this encoding, cats would be represented as 0000110111.

Given a dictionary of character frequencies, build a Huffman tree,
and use it to determine a mapping between characters and their encoded binary strings.
*/

struct Node{
	char ch;
	int freq;
	Node *left, *right;
};

struct Comp{
	bool operator () (Node* l, Node* r){
		return l->freq > r->freq;
	}
};

Node* getNode(char ch, int freq, Node* left, Node* right){
	Node* node = new Node;
	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;
	
	return node;
}

void encode(Node* root, string s, unordered_map<char, string>& huffmanCodes){
	if(root){
		if(!root->left && !root->right)
			huffmanCodes[root->ch] = s;
		encode(root->left, s + "0", huffmanCodes);
		encode(root->right, s + "1", huffmanCodes);
	}
}

unordered_map<char, string> huffmanTree(unordered_map<char, int> char_count){
	priority_queue<Node*, vector<Node*>, Comp> pq;
	for(auto it : char_count)
		pq.push(getNode(it.first, it.second, nullptr, nullptr));
	
	while(pq.size() != 1){
		Node* l = pq.top();
		pq.pop();
		Node* r = pq.top();
		pq.pop();
		
		int sum = l->freq + r->freq;
		pq.push(getNode('\0', sum, l, r));
	}
	
	Node* root = pq.top();
	unordered_map<char, string> huffmanCodes;
	
	encode(root, "", huffmanCodes);
	
	return huffmanCodes;
}

// main function
int main(){
	string s = "Test string.";
	unordered_map<char, int> char_count;
	
	for(char c : s) char_count[c]++;
	
	for(auto it : huffmanTree(char_count))
		cout << it.first << " --> " << it.second << "\n";
	return 0;
}