#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
An XOR linked list is a more memory efficient doubly linked list.
Instead of each node holding next and prev fields, it holds a field named both,
which is an XOR of the next node and the previous node. Implement an XOR linked list;
it has an add(element) which adds the element to the end,
and a get(index) which returns the node at index.

If using a language that has no pointers (such as Python),
you can assume you have access to get_pointer and dereference_pointer
functions that converts between nodes and memory addresses.
*/

struct node{
    int data;
    struct node* xor_node;
};

struct node* xorAddress(struct node* a, struct node* b){
    return (struct node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

void add(struct node** headref, int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node*));
    new_node->data = data;
    
    if(*headref == NULL){
        new_node->xor_node = NULL;
        *headref = new_node;
    }
    else{
        struct node* curr = *headref;
        struct node* prev = NULL;

        while(xorAddress(curr->xor_node, prev)){
            struct node* next = xorAddress(curr->xor_node, prev);
            prev = curr;
            curr = next;
        }
        
        curr->xor_node = xorAddress(curr->xor_node, new_node);
        new_node->xor_node = xorAddress(curr, NULL);
    }
}

struct node* get(struct node* prev, struct node* head, int n){
    if(head == NULL)
        return NULL;
    if(n == 0)
        return head;
    
    struct node* next = xorAddress(prev, head->xor_node);
    return get(head, next, n-1);
}

void printList(struct node* head){
    struct node *curr = head, *prev = NULL;

    while(curr){
        printf("%d ", curr->data);
        struct node* next = xorAddress(curr->xor_node, prev);
        prev = curr;
        curr = next;
    }
    printf("\n");
}


// main function
int main(){
    struct node* head = NULL;
    
    add(&head, 10);
    add(&head, 20);
    add(&head, 30);
    add(&head, 40);
    add(&head, 50);
    add(&head, 60);

    printList(head);

    for(int i=0;i<6;i++)
        printf("%d\n",get(NULL, head, i)->data);
    return 0;
}