#include <bits/stdc++.h>
using namespace std;

/*
Let's represent an integer in a linked list
format by having each node represent
a digit in the number. The nodes make
up the number in reversed order.

For example, the following linked list:

1 -> 2 -> 3 -> 4 -> 5
is the number 54321.

Given two linked lists in this format,
return their sum in the same linked list format.

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

node* addNumber(node* num1, node* num2){
	node dummy, *res;
	dummy.next = nullptr;
	res = &dummy;
	
	int sum = 0, carry = 0;
	
	while(num1 || num2){
		sum = ((num1)? num1->data : 0) + ((num2)? num2->data : 0) + carry;
		res->next = newNode(sum%10);
		carry = sum/10;
        if(num1) num1 = num1->next;
        if(num2) num2 = num2->next;
        res =  res->next;
	}
	
	if(carry) res->next = newNode(carry);
	
	return dummy.next;
}

// main function
int main(){
	// create first list 7->5->9->4->6 
	node* num1 = newNode(7);
	num1->next = newNode(5);
	num1->next->next = newNode(9);
	num1->next->next->next = newNode(4);
	num1->next->next->next->next = newNode(6);
	
	printList(num1);
	cout << "\n";
	
	// create second list 8->4
	node* num2 = newNode(8);
	num2->next = newNode(4);
	
	printList(num2);
	cout << "\n";
	
	printList(addNumber(num1, num2));
	cout << "\n";
	
	return 0;
}