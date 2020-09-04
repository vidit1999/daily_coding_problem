#include <bits/stdc++.h>
using namespace std;

/*
Determine whether a doubly linked list is a palindrome.
What if it’s singly linked?

For example, 1 -> 4 -> 3 -> 4 -> 1 returns
true while 1 -> 4 returns false.
*/

struct node{
	int data;
	node *next, *prev;
};

node* newNode(int data, node* prev){
	node* head = new node;
	head->data = data;
	head->prev = prev;
	head->next = nullptr;
	return head;
}

bool isPlindromeList(node* head){
	if(!head) return true;
	
	node *left = head, *right = head;
	
	while(right->next) right = right->next;
	
	while(left && right){
		if(left->data != right->data) return false;
		left = left->next;
		right = right->prev;
	}
	
	return true;
}

// main function
int main(){
	node* head1 = newNode(1, nullptr);
	head1->next = newNode(4, head1);
	head1->next->next = newNode(3, head1->next);
	head1->next->next->next = newNode(4, head1->next->next);
	head1->next->next->next->next = newNode(1, head1->next->next->next);
	
    if(isPlindromeList(head1))
        cout << "Yes\n";
	else
		cout << "No\n";

	node* head2 = newNode(1, nullptr);
	head2->next = newNode(4, head2);
	
	if(isPlindromeList(head2))
        cout << "Yes\n";
	else
		cout << "No\n";
	
	return 0;
}
