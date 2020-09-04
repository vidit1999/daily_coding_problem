#include <bits/stdc++.h>
using namespace std;

/*
Given the head of a singly linked list, reverse it in-place.
*/

struct node{
	int data;
	node* next;
};

node* newNode(int data){
	node* head = new node;
	head->data = data;
	head->next = nullptr;
	return head;
}

void printList(node* head){
	while(head){
		cout << head << " ";
		head = head->next;
	}
	cout << "\n";
}

void reverseLinkedList(node*& head){
	node *curr = head, *prev = nullptr;
	
	while(curr){
		node *next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	
	head = prev;
}

// main function
int main(){
	node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	head->next->next->next->next->next = newNode(6);
	head->next->next->next->next->next->next = newNode(7);
	
	printList(head);
	reverseLinkedList(head);
	printList(head);
	
	return 0;
}