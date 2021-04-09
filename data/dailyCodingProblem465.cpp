#include <iostream>
using namespace std;

/*
Given the head of a singly linked list, reverse it in-place.
*/

struct node{
	int data;
	struct node* next;
};

node* newNode(int data){
	node* head = new node;
	head->data = data;
	head->next = NULL;
	return head;
}

void printList(node* head){
	node* cur = head;
	while(cur){
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << "\n";
}

void reverseList(node** headRef){
	node* prev = NULL;
	node* cur = *headRef;
	while(cur){
		node* tempNext = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tempNext;
	}
	*headRef = prev;
}


// main function
int main(){
	node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next = newNode(4);
	head->next->next->next = newNode(5);
	head->next->next->next->next = newNode(6);
	printList(head);
	reverseList(&head);
	printList(head);
	return 0;
}