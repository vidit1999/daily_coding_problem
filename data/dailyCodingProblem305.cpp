#include <bits/stdc++.h>
using namespace std;

/*
Given a linked list, remove all consecutive nodes that sum to zero.
Print out the remaining nodes.

For example, suppose you are given the input 3 -> 4 -> -7 -> 5 -> -6 -> 6.
In this case, you should first remove 3 -> 4 -> -7, then -6 -> 6, leaving only 5.

Example 1:
Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.

Example 2:
Input: head = [1,2,3,-3,4]
Output: [1,2,4]

Example 3:
Input: head = [1,2,3,-3,-2]
Output: [1]
*/

struct node{
	int data;
	node* next;
};

node* newNode(int data){
	node* head = new node;
	head->data = data;
	head->next = nullptr;
	return head;
}

void printList(node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}

node* zeroSumDelete(node* head){
    node* dummy = newNode(0);
    dummy->next = head;
    unordered_map<int, node*> running_sum_node = {{0, dummy}};
    int sum = 0;

    while(head){
        sum += head->data;
        running_sum_node[sum] = head;
        head = head->next;
    }

    head = dummy;
    sum = 0;

    while(head){
        sum += head->data;
        node* temp = running_sum_node[sum];
        if(temp != head){
            head->next = temp->next;
        }
        head = head->next;
    }

    return dummy->next;
}



// main function
int main(){
    node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(-3);
    head->next->next->next->next = newNode(-2);
    printList(head);
    cout << "\n";

    printList(zeroSumDelete(head));
	return 0;
}