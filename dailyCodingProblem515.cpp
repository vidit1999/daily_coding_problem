#include <bits/stdc++.h>
using namespace std;

/*
Given a linked list of numbers and a pivot k, partition the linked list
so that all nodes less than k come before nodes greater than or equal to k.

For example, given the linked list 5 -> 1 -> 8 -> 0 -> 3 and k = 3,
the solution could be 1 -> 0 -> 5 -> 8 -> 3.
*/

struct node{
	int data;
	node *next;
};

node* newNode(int data){
	node* head = new node;
	head->data = data;
	head->next = NULL;
	return head;
}

void deleteList(node** head){
	node *curr = *head, *next;
	while(curr){
		next = curr->next;
		delete curr;
		curr = next;
	}
	*head = NULL;
}

void listPartition(node* head){
	node *start = head, *curr = head;
	
	while(curr && start){
		if(curr->data < 3){
			int temp = start->data;
			start->data = curr->data;
			curr->data = temp;
			start = start->next;
		}
		curr = curr->next;
	}
}

void printList(node* head){
	while(head){
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}

// main function
int main(){
	node* head = newNode(5);
	head->next = newNode(1);
	head->next->next = newNode(8);
	head->next->next->next = newNode(0);
	head->next->next->next->next = newNode(3);
	
	printList(head);
	listPartition(head);
	printList(head);
	deleteList(&head);
	return 0;
}