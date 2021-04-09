#include <bits/stdc++.h>
using namespace std;

/*
Create a data structure that performs all the following operations in O(1) time:

plus: Add a key with value 1. If the key already exists, increment its value by one.
minus: Decrement the value of a key. If the key's value is currently 1, remove it.
get_max: Return a key with the highest value.
get_min: Return a key with the lowest value.
*/

struct node{
	int data;
	unordered_set<int> uset;
	node *prev, *next;
};

node* newNode(int data){
	auto nd = new node;
	nd->data = data;
	nd->uset = {};
	nd->prev = nd->next = nullptr;
	return nd;
}

class AllOne{
	node *head, *tail;
	unordered_map<int, node*> umap;
	
	void setHead();
	void setTail();
	
	public:
	
	AllOne();
	void plus(int key);
	void minus(int key);
	int get_max();
	int get_min();
};

AllOne::AllOne(){
	head = tail = nullptr;
}

void AllOne::setHead(){
	if(head && head->prev){
		head = head->prev;
	}
}

void AllOne::setTail(){
	if(tail && tail->next){
		tail = tail->next;
	}
}

void AllOne::plus(int key){
	if(umap.find(key) == umap.end()){
		if(!head){ // no head and tail exists
			head = newNode(1);
			tail = head;
			(head->uset).insert(key);
			umap[key] = head;
		}
		else if(head->data != 1){
			auto nd = newNode(1);
			nd->next = head;
			head->prev = nd;
			(nd->uset).insert(key);
			umap[key] = nd;
		}
		else{
		    (head->uset).insert(key);
		    umap[key] = head;
		}
	}
	else{
		auto pos = umap[key];
		pos->uset.erase(key);
		
		// this node is not tail
		if(pos->next && pos->next->data == pos->data + 1){
			(pos->next->uset).insert(key);
			umap[key] = pos->next;
		}
		else{ // this node is tail or (pos->next->data != pos->data + 1)
			auto nd = newNode(pos->data+1);
			(nd->uset).insert(key);
			nd->next = pos->next;
			pos->next = nd;
			nd->prev = pos;
			if(nd->next) nd->next->prev = nd;
			umap[key] = nd;
		}
		
		// pos->next will exist for sure
		if(pos->uset.empty()){
			pos->next->prev = pos->prev;
			if(pos->prev){
				pos->prev->next = pos->next;
			}
			if(head == pos){
				head = pos->next;
			}
		}
	}

	setHead();
	setTail();
}

void AllOne::minus(int key){
	if(umap.find(key) != umap.end()){
		auto pos = umap[key];
		pos->uset.erase(key);
		
		if(pos->data - 1 != 0){
			// pos is not head
			if(pos->prev && pos->prev->data == pos->data - 1){
				pos->prev->uset.insert(key);
				umap[key] = pos->prev;
			}
			else{ // pos is head or pos->prev->data != pos->data - 1
				auto nd = newNode(pos->data - 1);
				nd->uset.insert(key);
				nd->next = pos;
				nd->prev = pos->prev;
				pos->prev = nd;
				if(nd->prev) nd->prev->next = nd;
				umap[key] = nd;
			}
		}
		
		// pos->prev will exist for sure
		if(pos->uset.empty()){
			pos->prev->next = pos->next;
			if(pos->next){
				pos->next->prev = pos->prev;
			}
			if(tail == pos){
				tail = pos->prev;
			}
		}

		setHead();
		setTail();
	}
}

int AllOne::get_max(){
	if(head && tail){
		return *(tail->uset).begin();
	}
	return -1;
}

int AllOne::get_min(){
	if(head && tail){
		return *(head->uset).begin();
	}
	return -1;
}

// main function
int main(){
	auto ds = AllOne();
        
	for(int i=1; i<=10; i++){
		ds.plus(i);
	}
	
	cout << ds.get_min() << "\n";
	cout << ds.get_max() << "\n";

    
	for(int i=1; i<=5; i++){
		ds.plus(i);
	}

    
	cout << ds.get_min() << "\n";
	cout << ds.get_max() << "\n";

	for(int i=5; i<10; i++){
		ds.minus(i);
	}
    
	cout << ds.get_min() << "\n";
	cout << ds.get_max() << "\n";

	return 0;
}