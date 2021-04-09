#include <bits/stdc++.h>
using namespace std;

/*
Given the head of a singly linked list,
swap every two nodes and return its head.

For example, given 1 -> 2 -> 3 -> 4,
return 2 -> 1 -> 4 -> 3.
*/

struct node{
	int data;
	node* next;
};

node* newNode(int data){
	auto head = new node;
	head->data = data;
	head->next = nullptr;
	return head;
}

void printList(node* head){
	while(head){
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}

void swapTwo(node*& head){	
	auto curr = head;
	
	while(curr && curr->next){
		swap(curr->data, curr->next->data);
		curr = curr->next->next;
	}
}

// main function
int main(){
	auto head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	head->next->next->next->next->next = newNode(6);
	
	printList(head);
	swapTwo(head);
	printList(head);
	
	return 0;
}