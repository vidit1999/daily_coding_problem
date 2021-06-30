#include <bits/stdc++.h>
using namespace std;

/*
Given a linked list and a positive integer k,
rotate the list to the right by k places.

For example, given the linked list 7 -> 7 -> 3 -> 5 and k = 2,
it should become 3 -> 5 -> 7 -> 7.

Given the linked list 1 -> 2 -> 3 -> 4 -> 5 and k = 3,
it should become 3 -> 4 -> 5 -> 1 -> 2.
*/

struct node{
    int data;
    node* next;
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

void rotateRight(node*& head, int k){
    int len = 0;
    auto curr = head, curr2 = head;

    while(curr){
        len++;
        curr = curr->next;
    }

    if(len == 0 || k%len == 0) return;

    k = len - k%len;

    curr = head;

    while(curr2->next){
        if(--k > 0) curr = curr->next;
        curr2 = curr2->next;
    }

    curr2->next = head;
    head = curr->next;
    curr->next = nullptr;
}

// main function
int main(){
    auto head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    int k = 3;

    printList(head);
    rotateRight(head, k);
    printList(head);

    return 0;
}
