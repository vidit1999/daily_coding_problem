#include <bits/stdc++.h>
using namespace std;

/*
Given a linked list, sort it in O(n log n) time and constant space.

For example, the linked list 4 -> 1 -> -3 -> 99 should become -3 -> 1 -> 4 -> 99.
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


// merge two sorted linked list and return the sorted list
node* sortedMerge(node* a, node* b){
	if(a == NULL) return b;
	else if(b == NULL) return a;
	
	node* result = NULL;
	
	if(a->data <= b->data){
		result = a;
		result->next = sortedMerge(a->next, b);
	}
	else{
		result = b;
		result->next = sortedMerge(a, b->next);
	}
	
	return result;
}



// splits the given list in two halves
void frontBackSplit(node* head, node** front, node** back){
    node *slow = head, *fast = head->next;

    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    *front = head;
    *back = slow->next;
    slow->next = NULL;
}


// merger sort method
void mergeSort(node** headref){
    node* head = *headref;

    if(head && head->next){
        node *a, *b;
        frontBackSplit(head, &a, &b);
        mergeSort(&a);
        mergeSort(&b);
        *headref = sortedMerge(a, b);
    }
}


// main function
int main(){
    node* head = newNode(2);
    head->next = newNode(3);
    head->next->next = newNode(20);
    head->next->next->next = newNode(5);
    head->next->next->next->next = newNode(10);
    head->next->next->next->next->next = newNode(15);
    printList(head);

    mergeSort(&head);

    printList(head);
	return 0;
}