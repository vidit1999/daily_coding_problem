#include <bits/stdc++.h>
using namespace std;

/*
Let's represent an integer in a linked list format by having each node represent a digit in the number.
The nodes make up the number in reversed order.

For example, the following linked list:

1 -> 2 -> 3 -> 4 -> 5
is the number 54321.

Given two linked lists in this format, return their sum in the same linked list format.

For example, given

9 -> 9
5 -> 2
return 124 (99 + 25) as:

4 -> 2 -> 1
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

node* sumNumbers(node* num1, node* num2){
	node *result = NULL, *prev = NULL, *temp;
	int carry = 0;
	
	while(num1 || num2){
		int sum = ((num1)? num1->data : 0) + ((num2)? num2->data : 0) + carry;
		carry = sum/10;
		temp = newNode(sum%10);
		if(result == NULL)
			result = temp;
		else
			prev->next = temp;
		prev = temp;
		
		if(num1) num1 = num1->next;
		if(num2) num2 = num2->next;
	}
	
	if(carry > 0)
		temp->next = newNode(carry);
	
	return result;
}

// main function
int main(){
	node* head1 = newNode(9);
	head1->next = newNode(9);
	printList(head1);
	node* head2 = newNode(5);
	head2->next = newNode(2);
	printList(head2);
	printList(sumNumbers(head1, head2));
	return 0;
}