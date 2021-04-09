#include <bits/stdc++.h>
using namespace std;

/*
Given k sorted singly linked lists, write a function
to merge all the lists into one sorted singly linked list.
*/

struct node{
	int data;
	node *next;
};

struct Compare{
    bool operator () (node* a, node* b){
        return a->data > b->data;
    }
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

node* sortedMergeK(node* arr[], int n){
	priority_queue<node*, vector<node*>, Compare> pq;
    for(int i=0; i<n; i++)
        pq.push(arr[i]);
    
    node *head = nullptr, *tail = nullptr;

    while(!pq.empty()){
        node* min = pq.top(); pq.pop();

        if(!head){ head = tail = min; }
        else{
            tail->next = min;
            tail = min;
        }

        if(min && min->next){ pq.push(min->next); }
    }

    return head;
}

// main function
int main(){
    int k = 3;
	node *list[k];

	list[0] = newNode(1);
	list[0]->next = newNode(5);
	list[0]->next->next = newNode(7);

	list[1] = newNode(2);
	list[1]->next = newNode(3);
	list[1]->next->next = newNode(6);
	list[1]->next->next->next = newNode(9);

	list[2] = newNode(4);
	list[2]->next = newNode(8);
	list[2]->next->next = newNode(10);
    
    printList(list[0]);
    printList(list[1]);
    printList(list[2]);

    printList(sortedMergeK(list, k));
	return 0;
}