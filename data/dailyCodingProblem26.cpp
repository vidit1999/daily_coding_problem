#include <bits/stdc++.h>
using namespace std;

/*
Given a singly linked list and an integer k,
remove the kth last element from the list.
k is guaranteed to be smaller than the length of the list.

The list is very long, so making more than
one pass is prohibitively expensive.

Do this in constant space and in one pass.
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
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}

void removeKthLast(node* head, int k){
	if(!head || k <= 0) return;
	
	node* curr = head;
	
	while(k--) head = head->next;
	
	while(head->next){
		curr = curr->next;
		head = head->next;
	}
	
	node* temp = curr->next;
	curr->next = temp->next;
	delete temp;
}

// main function
int main(){
	node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
	
	printList(head);
	removeKthLast(head, 3);
	printList(head);
	
	return 0;
}