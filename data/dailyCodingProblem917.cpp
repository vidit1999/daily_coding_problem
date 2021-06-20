#include <bits/stdc++.h>
using namespace std;

/*
Given a linked list of numbers and a pivot k,
partition the linked list so that all nodes less
than k come before nodes greater than or equal to k.

For example, given the linked list 5 -> 1 -> 8 -> 0 -> 3 and k = 3,
the solution could be 1 -> 0 -> 5 -> 8 -> 3.
*/

struct node{
    int data;
    node *next;
};

node* newNode(int data){
    auto head = new node;
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

void partitionList(node*& head, int k){
    node *less = head, *curr = head;

    while(curr){
        if(curr->data < k){
            swap(curr->data, less->data);
            less = less->next;
        }
        curr = curr->next;
    }
}

// main function
int main(){
    int k1 = 3, k2 = 5;
    
    auto head1 = newNode(5);
    head1->next = newNode(1);
    head1->next->next = newNode(8);
    head1->next->next->next = newNode(0);
    head1->next->next->next->next = newNode(3);

    auto head2 = newNode(3);
    head2->next = newNode(5);
    head2->next->next = newNode(10);
    head2->next->next->next = newNode(2);
    head2->next->next->next->next = newNode(8);
    head2->next->next->next->next->next = newNode(2);
    head2->next->next->next->next->next->next = newNode(1);

    printList(head1);
    partitionList(head1, k1);
    printList(head1);

    cout << "\n";
    
    printList(head2);
    partitionList(head2, k2);
    printList(head2);

    return 0;
}