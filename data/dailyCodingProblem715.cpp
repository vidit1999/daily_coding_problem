#include <bits/stdc++.h>
using namespace std;

/*
Determine whether a doubly linked list is a palindrome.
What if it’s singly linked?

For example, 1 -> 4 -> 3 -> 4 -> 1 returns True
while 1 -> 4 returns False.
*/

struct node{
	int data;
	node* next;
};

struct dllnode{
	int data;
	dllnode *next, *prev;
};

node* newNode(int data){
	auto head = new node;
	head->data = data;
	head->next = nullptr;
	return head;
}

dllnode* newNode(int data, dllnode* prev){
	auto head = new dllnode;
	head->data = data;
	head->prev = prev;
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

void printListDll(dllnode* head){
	while(head){
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n";
}

bool checkPaildrome(node* head){
	stack<int> s;
	auto curr = head;
	
	while(curr){
		s.push(curr->data);
		curr = curr->next;
	}
	
	while(head){
		if(head->data != s.top()){
			return false;
		}
		s.pop();
		head = head->next;
	}
	
	return true;
}

bool checkPaildromeDll(dllnode* head){
	auto curr = head;
	
	while(curr->next){
		curr = curr->next;
	}
	
	while(curr != head){
		if(curr->data != head->data){
			return false;
		}
		curr = curr->prev;
		head = head->next;
	}
	
	return true;
}

// main function
int main(){
	auto head = newNode(1);
	head->next = newNode(4);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(1);
	
	printList(head);
	cout << checkPaildrome(head) << "\n";
	
	auto head2 = newNode(1, nullptr);
	head2->next = newNode(4, head2);
	head2->next->next = newNode(3, head2->next);
	head2->next->next->next = newNode(4, head2->next->next);
	head2->next->next->next->next = newNode(1, head2->next->next->next);
	
	printListDll(head2);
	cout << checkPaildromeDll(head2) << "\n";
	
	return 0;
}