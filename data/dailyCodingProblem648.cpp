#include <bits/stdc++.h>
using namespace std;

/*
Given the head to a singly linked list, where each node also has a “random” pointer
that points to anywhere in the linked list, deep clone the list.
*/

struct node{
	int data;
	node *next, *random;
};

node* newNode(int data){
	node* head = new node;
	head->data = data;
	head->next = head->random = nullptr;
	return head;
}

void printList(node* head){
	while(head){
		cout << head->data << ", " << head->random->data << "\n";
		head = head->next;
	}
}

node* listCopy(node* head){
	unordered_map<node*, node*> umap;
	
	node* curr = head;
	
	while(curr){
		umap[curr] = newNode(curr->data);
		curr = curr->next;
	}
	
	curr = head;
	
	while(curr){
		umap[curr]->next = umap[curr->next];
		umap[curr]->random = umap[curr->random];
		curr = curr->next;
	}
	
	return umap[head];
}

// main function
int main(){
	node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	head->next->next->next->next->next = newNode(6);
	
	head->random = head->next->next;
	head->next->random = head->next->next->next;
	head->next->next->random = head->next->next->next->next;
	head->next->next->next->random = head->next;
	head->next->next->next->next->random = head->next->next;
	head->next->next->next->next->next->random = head->next->next->next->next;
	
	printList(head);
	cout << "\n";
	
	printList(listCopy(head));
	
	return 0;
}