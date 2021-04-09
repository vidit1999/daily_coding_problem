#include <bits/stdc++.h>
using namespace std;

/*
Given a linked list and an integer k, remove the k-th node from the
end of the list and return the head of the list.

k is guaranteed to be smaller than the length of the list.

Do this in one pass.
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

node* deleteKth(node* head, int k){
	node *first = head, *second = head;
	
	for(int i=0;i<k;i++){
		if(second->next == NULL){
			head = head->next;
			return head;
		}
		second = second->next;
	}
	
	while(second->next){
		first = first->next;
		second = second->next;
	}
	
	node* temp = first->next;
	first->next = temp->next;
	delete temp;
	
	return head;
}

// main function
int main(){
	node* head1 = newNode(2);
	head1->next = newNode(3);
	head1->next->next = newNode(1);
	head1->next->next->next = newNode(7);
	
	printList(head1);
	head1 = deleteKth(head1, 1);
	printList(head1);
	
	node* head2 = newNode(1);
	head2->next = newNode(2);
	head2->next->next = newNode(3);
	head2->next->next->next = newNode(4);
	
	printList(head2);
	head2 = deleteKth(head2, 4);
	printList(head2);
	return 0;
}