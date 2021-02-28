#include <bits/stdc++.h>
using namespace std;

/*
Let's represent an integer in a linked list format by having
each node represent a digit in the number. The nodes make up
the number in reversed order.

For example, the following linked list:

1 -> 2 -> 3 -> 4 -> 5
is the number 54321.

Given two linked lists in this format, return their sum in
the same linked list format.

For example, given

9 -> 9
5 -> 2
return 124 (99 + 25) as:

4 -> 2 -> 1
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

node* listSum(node* n1, node* n2){
    node dummy;
    node* res = &dummy;
    dummy.next = nullptr;

    int sum, carry = 0;

    while(n1 || n2){
        sum = (n1 ? n1->data : 0) + (n2 ? n2->data : 0) + carry;
        carry = sum/10;
        res->next = newNode(sum%10);

        if(n1) n1 = n1->next;
        if(n2) n2 = n2->next;
        res = res->next;
    }

    if(carry) res->next = newNode(carry);

    return dummy.next;
}

// main function
int main(){
    auto n1 = newNode(9);
    n1->next = newNode(9);

    auto n2 = newNode(5);
    n2->next = newNode(2);

    printList(n1);
    printList(n2);
    printList(listSum(n1, n2));
    printList(listSum(n2, n1));

    return 0;
}
