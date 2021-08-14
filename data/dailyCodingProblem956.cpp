#include <bits/stdc++.h>
using namespace std;

/*
Given k sorted singly linked lists, write a function to merge
all the lists into one sorted singly linked list.
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

void moveSortedNodes(node*& src, node*& dest){
    node* nd = src;    
    assert(nd != nullptr);
    src = nd->next;
    nd->next = dest;
    dest = nd;
}

node* sortedMerge(node* h1, node* h2){
    node dummy;
    node* tail = &dummy;
    dummy.next = nullptr;
    
    while(true) {
        if(!h1) {
            tail->next = h2;
            break;
        } else if(!h2) {
            tail->next = h1;
            break;
        }

        if(h1->data <= h2->data) {
            moveSortedNodes(h1, tail->next);
        } else {
            moveSortedNodes(h2, tail->next);
        }
        tail = tail->next;
    }

    return dummy.next;
}

node* sortedMergeLists(node* arr[], int k){
    node* res = nullptr;
    
    for(int i=0; i<k; i++){
        res = sortedMerge(res, arr[i]);
    }

    return res;
}


// main function
int main(){
    int k = 3; 

    node* arr[k];
 
    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);
 
    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);
 
    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);

    for(int i=0; i<k; i++){
        printList(arr[i]);
    }

    printList(sortedMergeLists(arr, k));
    
    return 0;
}