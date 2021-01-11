#include <bits/stdc++.h>
using namespace std;

/*
Given a singly linked list and an integer k,
remove the kth last element from the list.
k is guaranteed to be smaller than the length of the list.

The list is very long, so making more than
one pass is prohibitively expensive.

Do this in constant space and in one pass.
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

void deleteKth(node*& head, int k){
    if(!head) return;

    if(k == 1){
        auto temp = head;
        head = head->next;
        delete temp;
        return;
    }

    auto curr = head;
    for(int i=1; i<k-1; i++){
        curr = curr->next;
    }

    auto temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
}

// main function
int main(){
    auto head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printList(head);
    deleteKth(head, 2);
    printList(head);
    deleteKth(head, 1);
    printList(head);
    deleteKth(head, 3);
    printList(head);
    deleteKth(head, 1);
    printList(head);

    return 0;
}
