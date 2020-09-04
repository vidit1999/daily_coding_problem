#include <bits/stdc++.h>
using namespace std;

/*
Given a linked list, sort it in O(n log n) time and constant space.

For example, the linked list 4 -> 1 -> -3 -> 99 should become -3 -> 1 -> 4 -> 99.
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
	cout << "\n";
}

node* sortedMerge(node* lst1, node* lst2){
	if(!lst1) return lst2;
	if(!lst2) return lst1;
	
	node* res = nullptr;
	if(lst1->data <= lst2->data){
		res = lst1;
		res->next = sortedMerge(lst1->next, lst2);
	}
	else{
		res = lst2;
		res->next = sortedMerge(lst1, lst2->next);
	}
	
	return res;
}


node* mergeSort(node* head){
	if(!head || !head->next) return head;
	
	node *slow = head, *fast = head->next;
	
	while(fast && fast->next){
		fast = fast->next->next;
		slow = slow->next;
	}
	
	node *left = head, *right = slow->next;
	slow->next = nullptr;
	
	left = mergeSort(left);
	right = mergeSort(right);
	
	return sortedMerge(left, right);
}

// main function
int main(){
	return 0;
}