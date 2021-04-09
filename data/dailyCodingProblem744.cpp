#include <bits/stdc++.h>
using namespace std;

/*
Implement an LFU (Least Frequently Used) cache.
It should be able to be initialized with a cache size n,
and contain the following methods:

set(key, value): sets key to value. If there are already
n items in the cache and we are adding a new item,
then it should also remove the least frequently used item.
If there is a tie, then the least recently used key should be removed.

get(key): gets the value at key.
If no such key exists, return null.

Each operation should run in O(1) time.
*/

struct node{
	int key, value;
	node *next, *prev;
};

node* newNode(int key, int value){
	auto head = new node;
	head->key = key;
	head->value = value;
	head->prev = head->next = nullptr;
	return head;
}

class LFU{
	int size;
	node *head, *tail;
	unordered_map<int, node*> node_map;

	void addHead(int key, int value);
	void deleteNode(node* nd);

public:
	
	LFU(int sz);
	void set(int key, int value);
	int get(int key);
};

LFU::LFU(int sz){
	size = sz;
	head = tail = nullptr;
}

void LFU::addHead(int key, int value){
	auto nd = newNode(key, value);
	if(head){
		head->prev = nd;
		nd->next = head;
	}
	head = nd;
	if(!tail) tail = head;
}

void LFU::deleteNode(node* nd){
	if(nd){
		if(nd == head) head = nd->next;
		if(nd == tail) tail = nd->prev;
		
		if(nd->next) nd->next->prev = nd->prev;
		if(nd->prev) nd->prev->next = nd->next;
		
		delete nd;
	}
}

void LFU::set(int key, int value){
	if(node_map.find(key) != node_map.end()){
		auto nd = node_map[key];
		node_map.erase(key);
		deleteNode(nd);
	}
	else if(node_map.size() >= size && tail){
		node_map.erase(tail->key);
		deleteNode(tail);
	}
	addHead(key, value);
	node_map[key] = head;
}

int LFU::get(int key){
	if(node_map.find(key) == node_map.end()){
		return -1;
	}
	auto nd = node_map[key];
	node_map.erase(key);
	addHead(key, nd->value);
	deleteNode(nd);
	node_map[key] = head;
	return head->value;
}

// main function
int main(){
	LFU l(3);

	cout << l.get(1) << "\n"; // expected -1
	l.set(1, 10);
	cout << l.get(1) << "\n"; // expected 10
	l.set(2, 20);
	cout << l.get(1) << "\n"; // expected 10
	cout << l.get(2) << "\n"; // expected 20
	l.set(3, 30);
	cout << l.get(3) << "\n"; // expected 30
	l.set(4, 40);
	cout << l.get(1) << "\n"; // expected -1
	cout << l.get(4) << "\n"; // expected 40
	l.set(5, 50);
	cout << l.get(2) << "\n"; // expected -1
	cout << l.get(5) << "\n"; // expected 50

	return 0;
}