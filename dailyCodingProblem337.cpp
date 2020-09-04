#include <bits/stdc++.h>
using namespace std;

/*
Given a linked list, uniformly shuffle the nodes.
What if we want to prioritize space over time?
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

// o(n) time | O(n) space
void shuffleLinkedList(node* head){
	vector<int> list_vec;
    node* curr = head;

    while(curr){
        list_vec.push_back(curr->data);
        curr = curr->next;
    }

    random_shuffle(list_vec.begin(), list_vec.end());
    
    int count = 0;
    while(head){
        head->data = list_vec[count];
        head = head->next;
        count++;
    }
}

void shuffleLinkedList2(node* head){
    int len = 0;
    node *curr1 = head, *curr2 = head;
    
    while(curr1){
        len++;
        curr1 = curr1->next;
    }

    curr1 = head;
    while(curr1){
        // spot a random node
        curr2 = head;
        for(int i = 0; i < rand()%len; i++){
            curr2 = curr2->next;
        }

        swap(curr1->data, curr2->data);
        curr1 = curr1->next;
    }
}

// main function
int main(){
    srand(time(0));
    node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(6);
    head->next->next->next->next->next->next = newNode(7);

    printList(head);

    shuffleLinkedList(head);#include <bits/stdc++.h>
using namespace std;

/*
Given a linked list, uniformly shuffle the nodes.
What if we want to prioritize space over time?
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

// o(n) time | O(n) space
void shuffleLinkedList(node* head){
	vector<int> list_vec;
    node* curr = head;

    while(curr){
        list_vec.push_back(curr->data);
        curr = curr->next;
    }

    random_shuffle(list_vec.begin(), list_vec.end());
    
    int count = 0;
    while(head){
        head->data = list_vec[count];
        head = head->next;
        count++;
    }
}

// O(n^2) time | O(1) space
void shuffleLinkedList2(node* head){
    int len = 0;
    node *curr1 = head, *curr2 = head;
    
    while(curr1){
        len++;
        curr1 = curr1->next;
    }

    curr1 = head;
    while(curr1){
        // spot a random node
        curr2 = head;
        for(int i = 0; i < rand()%len; i++){
            curr2 = curr2->next;
        }

        swap(curr1->data, curr2->data);
        curr1 = curr1->next;
    }
}

// main function
int main(){
    srand(time(0));
    node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(6);
    head->next->next->next->next->next->next = newNode(7);

    printList(head);

    shuffleLinkedList(head);

    printList(head);

    shuffleLinkedList2(head);

    printList(head);
	
	return 0;
}

    printList(head);
	return 0;
}