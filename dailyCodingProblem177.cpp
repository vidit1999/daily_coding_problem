#include <bits/stdc++.h>
using namespace std;

/*
Given a linked list and a positive integer k, rotate the list to the right by k places.

For example, given the linked list 7 -> 7 -> 3 -> 5 and k = 2, it should become 3 -> 5 -> 7 -> 7.

Given the linked list 1 -> 2 -> 3 -> 4 -> 5 and k = 3, it should become 3 -> 4 -> 5 -> 1 -> 2.
*/

struct node{
	int data;
	node* next;
};

node* newNode(int data){
	node* head = new node;
	head->data = data;
	head->next =nullptr;
	return head;
}

void printList(node* head){
	while(head){
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}

void rotateList(node** head_ref, int k){
	if(k == 0) return;
	node* curr1 = *head_ref, *curr2 = *head_ref;

    for(int i=0; i<k; i++) curr1 = curr1->next;

    while(curr1->next){
        curr2 = curr2->next;
        curr1 = curr1->next;
    }

    curr1->next = *head_ref;
    *head_ref = curr2->next;
    curr2->next = nullptr;
}

// main function
int main(){
	node* head1 = newNode(1);
	head1->next = newNode(2);
	head1->next->next = newNode(3);
	head1->next->next->next = newNode(4);
	head1->next->next->next->next = newNode(5);

    printList(head1);
	rotateList(&head1, 3);
	printList(head1);

    node* head2 = newNode(7);
	head2->next = newNode(7);
	head2->next->next = newNode(3);
	head2->next->next->next = newNode(5);
	
	printList(head2);
	rotateList(&head2, 2);
	printList(head2);
	
	return 0;
}