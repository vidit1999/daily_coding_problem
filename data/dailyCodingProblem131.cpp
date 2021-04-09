#include <bits/stdc++.h>
using namespace std;

/*
Given the head to a singly linked list, where each node also has a “random” pointer
that points to anywhere in the linked list, deep clone the list.
*/

struct node{
	int data;
	node *next, *random;
};

node* newNode(int data){
	node* head = new node;
	head->data = data;
	head->next = head->random = nullptr;
	return head;
}

void printList(node* head){
	while(head){
		cout << head << " : " << head->data << " --> " << head->random->data << "\n";
		head = head->next;
	}
}

node* deepCopy(node* head){
	unordered_map<node*, node*> node_to_node;
	node *curr = head, *res;
	
	while(curr){
        node_to_node[curr] = newNode(curr->data);
        curr = curr->next;
    }

    curr = head;
    while(curr){
        node_to_node[curr]->next = node_to_node[curr->next];
        node_to_node[curr]->random = node_to_node[curr->random];
        curr = curr->next;
    }

    return node_to_node[head];
}

// main function
int main(){
	node* head = newNode(1);
	head->next = newNode(3);
	head->next->next = newNode(7);
	head->next->next->next = newNode(7);
	head->next->next->next->next = newNode(2);
	head->next->next->next->next->next = newNode(9);
	
	head->random = head->next->next;
	head->next->random = head;
	head->next->next->random = head->next->next;
	head->next->next->next->random = head->next;
	head->next->next->next->next->random = head->next;
	head->next->next->next->next->next->random = head->next->next->next->next;
	
	printList(head);
	cout << "\n\n";
    printList(deepCopy(head));

	return 0;
}