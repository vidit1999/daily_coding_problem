#include <bits/stdc++.h>
using namespace std;

/*
Given a linked list, sort it in O(n log n) time and constant space.

For example, the linked list
4 -> 1 -> -3 -> 99 should
become -3 -> 1 -> 4 -> 99.
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

void moveNode(node*& src, node*& dest){
    node* new_node = src;

    assert(new_node != nullptr);

    src = new_node->next;
    new_node->next = dest;
    dest = new_node;
}

node* sortedMerge(node* a, node* b){
    node dummy;
    dummy.next = nullptr;
    node* tail = &dummy;

    while(true){
        if(!a || !b){
            tail->next = a ? a : b;
            break;
        }

        if(a->data <= b->data){
            moveNode(a, tail->next);
        } else {
            moveNode(b, tail->next);
        }

        tail = tail->next;
    }

    return dummy.next;
}

void splitListTwo(node* head, node*& a, node*& b){
    node *slow = head, *fast = head->next;

    while(fast){
        fast = fast->next;
        if(fast){
            slow = slow->next;
            fast = fast->next;
        }
    }

    a = head;
    b = slow->next;
    slow->next = nullptr;
}

void mergeSortList(node*& head){
    if(!head || !head->next) return;

    node *a, *b;

    splitListTwo(head, a, b);

    mergeSortList(a);
    mergeSortList(b);

    head = sortedMerge(a, b);
}

// main function
int main(){
    auto head = newNode(4);
    head->next = newNode(1);
    head->next->next = newNode(-3);
    head->next->next->next = newNode(99);

    printList(head);

    mergeSortList(head);

    printList(head);

    return 0;
}