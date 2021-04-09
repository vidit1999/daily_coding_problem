#include <bits/stdc++.h>
using namespace std;

/*
Given a linked list of numbers and a pivot k, partition the linked list so
that all nodes less than k come before nodes greater than or equal to k.

For example, given the linked list 5 -> 1 -> 8 -> 0 -> 3 and k = 3,
the solution could be 1 -> 0 -> 5 -> 8 -> 3.
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

node* partitionPivot(node* head, int k){
	node *first = nullptr, *first_last = nullptr,\
	*second = nullptr, *second_last = nullptr,\
	*curr = head;
	
	while(curr){
		if(curr->data < k){
			if(first == nullptr){
				first_last = first = curr;
			}
			else{
				first_last->next = curr;
				first_last = curr;
			}
		}
		else{
			if(second == nullptr){
				second_last = second = curr;
			}
			else{
				second_last->next = curr;
				second_last = curr;
			}
		}
        curr = curr->next;
	}
	
	if(first_last != nullptr) first_last->next = nullptr;
	if(first == nullptr) return second;
	
	first_last->next = second;
	return first;
}

// main function
int main(){
	node* head = newNode(5);
	head->next = newNode(1);
	head->next->next = newNode(8);
	head->next->next->next = newNode(0);
	head->next->next->next->next = newNode(3);
	printList(head);
	
	printList(partitionPivot(head, 3));
	
	return 0;
}