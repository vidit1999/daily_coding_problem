#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Given a linked list, rearrange the node values such that they appear
in alternating low -> high -> low -> high ... form. For example,
given 1 -> 2 -> 3 -> 4 -> 5, you should return 1 -> 3 -> 2 -> 5 -> 4.
*/

struct node{
	int data;
	struct node* next;
};

struct node* newNode(int data){
	struct node* head = (struct node*)malloc(sizeof(struct node));
	head->data = data;
	head->next = NULL;
	return head;
}

void deleteTree(struct node** head){
	struct node* curr = *head;
	struct node* next;
	
	while(curr){
		next = curr->next;
		free(curr);
		curr = next;
	}
	
	*head = NULL;
}

void swapData(struct node* a, struct node* b){
	if(a && b){
		int temp = a->data;
		a->data = b->data;
		b->data = temp;
	}
}

void alternatingLinkedList(struct node* head){
	bool greater = true;
	struct node* curr = head;
	
	while(curr && curr->next){
		if(greater){
			if(curr->data >= curr->next->data){
				swapData(curr, curr->next);
			}
		}
		else{
			if(curr->data <= curr->next->data){
				swapData(curr, curr->next);
			}
		}
		greater = !greater;
		curr = curr->next;
	}
}

void printList(struct node* head){
	while(head){
		printf("%d ",head->data);
		head = head->next;
	}
	printf("\n");
}

// main function
int main(){
	struct node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	head->next->next->next->next->next = newNode(6);
	head->next->next->next->next->next->next = newNode(7);
	head->next->next->next->next->next->next->next = newNode(8);
	head->next->next->next->next->next->next->next->next = newNode(6);
	
	printList(head);
	alternatingLinkedList(head);
	printList(head);
	return 0;
}