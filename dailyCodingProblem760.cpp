#include <bits/stdc++.h>
using namespace std;

/*
Given a linked list, uniformly shuffle the nodes.
What if we want to prioritize space over time?
*/

struct node{
	int data;
	node *next;
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
}

// O(n) time and O(n) space
void shuffle1(node*& head){
	vector<int> v;
	auto curr = head;

	while(curr){
		v.push_back(curr->data);
		curr = curr->next;
	}

	random_shuffle(v.begin(), v.end());

	curr = head;

	for(int i : v){
		curr->data = i;
		curr = curr->next;
	}
}

// O(n^2) time and O(1) space
void shuffle2(node*& head){
	auto curr1 = head;
	int len = 0;

	while(curr1){
		len++;
		curr1 = curr1->next;
	}

	curr1 = head;

	while(curr1){
		auto curr2 = head;
		for(int i=0; i<rand()%len; i++){
			curr2 = curr2->next;
		}

		swap(curr1->data, curr2->data);
		curr1 = curr1->next;
	}
}

// main function
int main(){
	srand(time(0));

	auto head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);

	printList(head); cout << "\n";

	shuffle1(head);

	printList(head); cout << "\n";

	shuffle2(head);

	printList(head); cout << "\n";
	return 0;
}
