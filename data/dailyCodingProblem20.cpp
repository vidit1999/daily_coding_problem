#include <bits/stdc++.h>
using namespace std;

/*
Given two singly linked lists that intersect at some point, find the intersecting node.
The lists are non-cyclical.

For example, given A = 3 -> 7 -> 8 -> 10 and
B = 99 -> 1 -> 8 -> 10,
return the node with value 8.

In this example, assume nodes with the same
value are the exact same node objects.

Do this in O(M + N) time (where M and N are
the lengths of the lists) and constant space.
*/

struct node{
	int data;
	node *next;
};

node* newNode(int data){
	node* head = new node;
	head->data = data;
	head->next = nullptr;
	return head;
}

node* intersectingNode(node* head1, node* head2){
	int len1 = 0, len2 = 0;
	node *curr1 = head1, *curr2 = head2;
	
	while(curr1){
		len1++;
		curr1 = curr1->next;
	}
	
	while(curr2){
		len2++;
		curr2 = curr2->next;
	}
	
	int diff = abs(len1 - len2);
	curr1 = head1, curr2 = head2;
	
	if(len1 > len2){
		while(diff--){
			curr1 = curr1->next;
		}
	}
	else{
		while(diff--){
			curr2 = curr2->next;
		}
	}
	
	while(curr1 && curr2){
		if(curr1 == curr2) return curr1;
		curr1 = curr1->next;
		curr2 = curr2->next;
	}
	
	return nullptr;
}

// main function
int main(){
	node* head = newNode(3);
	head->next = newNode(7);
	head->next->next = newNode(8);
	head->next->next->next = newNode(10);
	
	node* head1 = newNode(99);
	head1->next = newNode(1);
	head1->next->next = newNode(7);
	head1->next->next->next = head->next->next;
	
	node* intersect = intersectingNode(head1, head);
	if(intersect)
		cout << intersect->data << "\n";
	else
		cout << "No intersect\n";
	
	return 0;
}