#include <bits/stdc++.h>
using namespace std;

/*
Given k sorted singly linked lists, write a function to merge all the lists into one sorted singly linked list.
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

void printList(node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

node* sortedMerge(node* a, node* b){
    if(!a) return b;
    if(!b) return a;

    node* result = NULL;

    if(a->data <= b->data){
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else{
        result = b;
        result->next = sortedMerge(a, b->next);
    }

    return result;
}

node* mergeKSorted(vector<node*> lists){
    if(lists.empty()) return NULL;
    
    node* result = lists[0];

    for(int i=1;i<lists.size();i++)
        result = sortedMerge(result, lists[i]);
    
    return result;
}

// main function
int main(){
    vector<node*> arr(3);

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

    for(node* head : arr)
        printList(head);
    
    node* merged = mergeKSorted(arr);

    printList(merged);
	return 0;
}