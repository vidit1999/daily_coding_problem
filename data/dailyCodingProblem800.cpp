#include <bits/stdc++.h>
using namespace std;

/*
Given a linked list, rearrange the node values such
that they appear in alternating low -> high -> low -> high ... form.
For example, given 1 -> 2 -> 3 -> 4 -> 5,
you should return 1 -> 3 -> 2 -> 5 -> 4.
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

void rearrangeLowHigh(node* head){
    bool high = false; // true if head->data should be > head->next->data
    while(head && head->next){
        if(
            (high && head->data < head->next->data) ||
            (!high && head->data > head->next->data)
        ){
            swap(head->data, head->next->data);
        }
        high = !high;
        head = head->next;
    }
}

// main function
int main(){
    auto head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printList(head);
    rearrangeLowHigh(head);
    printList(head);

    return 0;
}
