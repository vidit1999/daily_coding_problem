#include <bits/stdc++.h>
using namespace std;

/*
Given two singly linked lists that intersect at some point, find the intersecting node.
The lists are non-cyclical.

For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

In this example, assume nodes with the same value are the exact same node objects.

Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.
*/

struct node{
	int data;
	node* next;
};

node* newNode(int data){
	node* head = new node;
	head->data = data;
	head->next = NULL;
	return head;
}

void printList(node* head){
	while(head){
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
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

int getIntersectingPoint(node* head1, node* head2){
	int len1=0, len2=0;
	node *curr1 = head1, *curr2 = head2;
	
	while(curr1){
		len1++;
		curr1 = curr1->next;
	}
		
	while(curr2){
		len2++;
		curr2 = curr2->next;
	}
	
	curr1 = head1, curr2 = head2;
	
	if(len1 > len2){
		for(int i=0;i<len1-len2;i++)
			curr1 = curr1->next;
	}
	else{
		for(int i=0;i<len2-len1;i++)
			curr2 = curr2->next;
	}
	
	while(curr1 && curr2){
		if(curr1->data == curr2->data)
			return curr1->data;
		curr1 = curr1->next;
		curr2 = curr2->next;
	}
	
	return -1;
}

// main function
int main(){
	node* head1 = newNode(3);
	head1->next = newNode(7);
	head1->next->next = newNode(8);
	head1->next->next->next = newNode(10);
	printList(head1);
	
	node* head2 = newNode(99);
	head2->next = newNode(1);
	head2->next->next = newNode(8);
    head2->next->next->next = newNode(10);
	printList(head2);
	
	cout << getIntersectingPoint(head1, head2) << "\n";

    deleteList(&head1);
    deleteList(&head2);
	return 0;
}