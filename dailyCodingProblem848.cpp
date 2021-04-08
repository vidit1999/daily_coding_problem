#include <bits/stdc++.h>
using namespace std;

/*
Implement an LRU (Least Recently Used) cache.
It should be able to be initialized with a cache size n,
and contain the following methods:

set(key, value): sets key to value. If there are already n items
in the cache and we are adding a new item, then it should also
remove the least recently used item.

get(key): gets the value at key. If no such key exists, return null.
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


class LRU{
private:
	int count, capacity;
	node *head, *tail;
	unordered_map<int, node*> umap;
	
	void deleteNode(node* nd){
		if(nd->prev){
			nd->prev->next = nd->next;
			if(nd->next){
				nd->next->prev = nd->prev;
			}
		}
	}

	void addHead(node* nd){
		nd->next = head->next;
		nd->prev = head;
		if(head->next){
			head->next->prev = nd;
		}
		head->next = nd;
	}

public:

	LRU(int capacity_size){
		count = 0;
		capacity = capacity_size;
		head = newNode(-1, -1);
		tail = newNode(-1, -1);
		head->next = tail;
		head->prev = nullptr;
		tail->prev = head;
		tail->next = nullptr;
	}

	int get(int key){
		if(umap.find(key) == umap.end())
			return -1;
		auto nd = umap[key];
		deleteNode(nd);
		addHead(nd);
		return nd->value;
	}

	void set(int key, int value){
		if(umap.find(key) != umap.end()){
			auto nd = umap[key];
			nd->value = value;
			addHead(nd);
		}
		else{
			auto nd = newNode(key, value);
			umap[key] = nd;
			if(count < capacity){
				count++;
				addHead(nd);
			}
			else{
				umap.erase(tail->prev->key);
				deleteNode(tail->prev);
				addHead(nd);
			}
		}
	}
};

// main function
int main(){
	auto cache = LRU(2);

	cache.set(1, 10);
	cache.set(2, 20);
	cout << cache.get(1) << "\n";
	cache.set(3, 30);
	cout << cache.get(2) << "\n";
	cache.set(4, 40);
	cout << cache.get(1) << "\n";
	cout << cache.get(3) << "\n";
	cout << cache.get(4) << "\n";
	
	return 0;
}