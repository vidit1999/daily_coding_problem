#include <bits/stdc++.h>
using namespace std;

/*
Given the head of a singly linked list, swap every two nodes and return its head.

For example, given 1 -> 2 -> 3 -> 4, return 2 -> 1 -> 4 -> 3.
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

void swapEverySecond(node* head){
	while(head && head->next){
		swap(head->data, head->next->data);
        head = head->next->next;
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
	node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	head->next->next->next->next->next = newNode(6);
	head->next->next->next->next->next->next = newNode(7);
	
    printList(head);
	swapEverySecond(head);
	printList(head);
	
    return 0;
}