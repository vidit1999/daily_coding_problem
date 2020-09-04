#include <bits/stdc++.h>
using namespace std;

/*
Create a data structure that performs all
the following operations in O(1) time:

plus: Add a key with value 1. If the key already exists, increment its value by one.
minus: Decrement the value of a key. If the key's value is currently 1, remove it.
get_max: Return a key with the highest value.
get_min: Return a key with the lowest value.
*/

struct node{
	int data;
	unordered_set<int> arr;
	node *prev, *next;
};

class AllOne{
	unordered_map<int, node*> umap;
	node *head, *tail;
	
	public:
	AllOne(){ head = nullptr, tail = nullptr; }
	void plus(int key);
	void minus(int key);
	int get_max();
	int get_min();
};

node* newNode(int data){
	node* head = new node;
	head->data = data;
	head->arr = {};
	head->prev = head->next = nullptr;
	return head;
}

void AllOne::change_list(node* nd){
	if((nd->arr).empty()){
		if(nd == head){
			head = nd->next;
			if(nd->next) nd->next->prev = nullptr;
		}
		if(nd == tail){
			tail = nd->prev;
			if(nd->prev) nd->prev->next = nullptr;
		}
		delete nd;
	}
}

void AllOne::plus(int key){
	if(umap.find(key) != umap.end()){
		int val = umap[key]->data;
		
	}
}


// main function
int main(){
	return 0;
}