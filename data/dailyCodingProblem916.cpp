#include <bits/stdc++.h>
using namespace std;

/*
Given the head of a singly linked list, reverse it in-place.
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

void reverseInPlace(node*& head){
    node *curr = head, *prev = nullptr;

    while(curr){
        auto next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

// main function
int main(){
    auto head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printList(head);
    reverseInPlace(head);
    printList(head);

    return 0;
}
