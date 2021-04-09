#include <bits/stdc++.h>
using namespace std;

/*
Given a singly linked list and an integer k, remove the kth last element from the list.
k is guaranteed to be smaller than the length of the list.

The list is very long, so making more than one pass is prohibitively expensive.
Do this in constant space and in one pass.
*/

struct node{
    int data;
    node *next;
};

node* newNode(int data){
    node* head = new node;
    head->data = data;
    head->next = NULL;
    return head;
}

// 1 based indexing is considered here.
// as k is always less than the length of list,
// head node will never be deleted
void deleteKthLast(node** headRef, int k){
    // if list is empty return
    if(!(*headRef) || k <= 0)
        return;

    node *curr1 = *headRef, *curr2 = *headRef;
    for(int i=0;i<k;i++)
        curr1 = curr1->next;
    
    // spot the k-1 th node from the last
    while(curr1->next){
        curr2 = curr2->next;
        curr1 = curr1->next;
    }

    node* temp = curr2->next;
    curr2->next = temp->next;
    delete temp;
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
    node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printList(head);
    deleteKthLast(&head, 4);
    printList(head);
	return 0;
}