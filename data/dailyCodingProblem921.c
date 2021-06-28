#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

/*
An XOR linked list is a more memory efficient doubly linked list.
Instead of each node holding next and prev fields, it holds a field
named both, which is an XOR of the next node and the previous node.
Implement an XOR linked list; it has an add(element) which adds the
element to the end, and a get(index) which returns the node at index.

If using a language that has no pointers (such as Python),
you can assume you have access to get_pointer and dereference_pointer
functions that converts between nodes and memory addresses.
*/

typedef struct node{
    int data;
    struct node* xor_address;
} node;

node* newNode(int data){
    node* head = (node*)malloc(sizeof(node));
    head->data = data;
    head->xor_address = NULL;
    return head;
}

node* getXorAddress(node* n1, node* n2){
    return (node*)((uintptr_t)n1 ^ (uintptr_t)n2);
}

void printList(node* head){
    node *prev = NULL, *curr = head;

    while(curr){
        printf("%d ", curr->data);
        node* next = getXorAddress(prev, curr->xor_address);
        prev = curr;
        curr = next;
    }

    printf("\n");
}

void add(node** head, int data){
    if(*head == NULL){
        *head = newNode(data);
        (*head)->xor_address = getXorAddress(NULL, NULL);
        return;
    }

    node *prev = NULL, *curr = *head;

    while(getXorAddress(prev, curr->xor_address)){
        node* next = getXorAddress(prev, curr->xor_address);
        prev = curr;
        curr = next;
    }

    node* temp = newNode(data);
    temp->xor_address = getXorAddress(curr, NULL);

    node* curr_prev = getXorAddress(curr->xor_address, NULL);
    curr->xor_address = getXorAddress(curr_prev, temp);
}

node* get(node* head, int index){
    if(head == NULL) return NULL;

    node *prev = NULL, *curr = head;
    int i = 0;

    while(curr){
        if(i++ == index) return curr;
        node* next = getXorAddress(prev, curr->xor_address);
        prev = curr;
        curr = next;
    }

    return NULL;
}

// main function
int main(){
    srand(time(NULL));

    node* head = NULL;

    for(int i=0; i<10; i++){
        add(&head, rand());
    }

    printList(head);

    for(int i=0; i<10; i++){
        printf("%d ", get(head, i)->data);
    }

    printf("\n");

    return 0;
}