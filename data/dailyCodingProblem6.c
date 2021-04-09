#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/*
An XOR linked list is a more memory efficient doubly linked list.
Instead of each node holding next and prev fields, it holds a field
named both, which is an XOR of the next node and the previous node.
Implement an XOR linked list; it has an add(element) which adds the
element to the end, and a get(index) which returns the node at index.

If using a language that has no pointers (such as Python), you can
assume you have access to get_pointer and dereference_pointer
functions that converts between nodes and memory addresses.
*/

typedef struct node{
	int data;
	struct node* xor_node;
} node ;

node* newNode(int data){
	node* head = (node*)malloc(sizeof(node));
	head->data = data;
	head->xor_node = NULL;
	return head;
}

node* xor_address(node* a, node* b){
	return (node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

void printList(node* head){
    node* prev = NULL;
    while(head){
        printf("%d ", head->data);
        node* next = xor_address(prev, head->xor_node);;
        prev = head;
        head = next;
    }
    printf("\n");
}

void add(node** head, int element){
	if(!(*head)){
		(*head) = newNode(element);
		(*head)->xor_node = xor_address(NULL, NULL);
		return;
	}
	
	node* prev = NULL;
	node* curr = *head;
	
	while(xor_address(curr->xor_node, prev)){
		node* next = xor_address(curr->xor_node, prev);
		prev = curr;
		curr = next;
	}
	
	node* temp = newNode(element);
	temp->xor_node = xor_address(curr, NULL);
	curr->xor_node = xor_address(prev, temp);
}

int get(node* head, int index){
	if(!head) return -1;
	
	node* prev = NULL;
	int count = 0;
	
	while(head){
		if(count++ == index)
			return head->data;
		node* next = xor_address(prev, head->xor_node);
		prev = head;
		head = next;
	}
	
	return -1;
}

// main function
int main(){
	node* head = NULL;
	
	for(int i=1; i<=10; i++){
		add(&head, i);
	}
	
	for(int i=0; i<10; i++){
		printf("%d\n", get(head, i));
	}
	
	return 0;
}