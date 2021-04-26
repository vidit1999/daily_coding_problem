#include <bits/stdc++.h>
using namespace std;

/*
Determine whether a doubly linked list is a palindrome.
What if it’s singly linked?

For example, 1 -> 4 -> 3 -> 4 -> 1 returns True
while 1 -> 4 returns False.
*/

struct dllNode{
    int data;
    dllNode *prev, *next;
};

struct node{
    int data;
    node* next;
};

dllNode* newDLLNode(int data){
    auto head = new dllNode;
    head->data = data;
    head->prev = head->next = nullptr;
    return head;
}

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
    cout << "\n";
}

void reverse(node*& head){
    node *prev = nullptr;
    node* curr = head;

    while(curr){
        auto next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}


bool isPalindromeDLL(dllNode* head){
    dllNode *start = head, *end = head;

    while(end->next){
        end = end->next;
    }

    while(start != end){
        if(start->data != end->data) return false;
        start = start->next;
        end = end->prev;
    }

    return true;
}

bool isPalindromeHelper(node* head1, node* head2){
    while(head1 && head2){
        if(head1->data != head2->data) return false;
        head1 = head1->next;
        head2 = head2->next;
    }

    return !head1 && !head2;
}

bool isPalindrome(node* head){
    node *slow = head, *fast = head;
    node *second_half, *middle = nullptr, *prev_slow = nullptr;

    while(fast && fast->next){
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    if(fast){
        middle = slow;
        slow = slow->next;
    }

    second_half = slow;
    if(prev_slow) prev_slow->next = nullptr;
    reverse(second_half);
    bool ans = isPalindromeHelper(head, second_half);
    reverse(second_half);

    if(prev_slow){
        if(middle){
            prev_slow->next = middle;
            middle->next = second_half;
        } else {
            prev_slow->next = second_half;
        }
    }

    return ans;
}

// main function
int main(){
    auto head = newNode(1);// newDLLNode(1);
    head->next = newNode(4);// newDLLNode(4);
    head->next->next = newNode(3);// newDLLNode(3);
    head->next->next->next = newNode(4);// newDLLNode(4);
    head->next->next->next->next = newNode(1);// newDLLNode(1);

    // head->prev = nullptr;
    // head->next->prev = head;
    // head->next->next->prev = head->next;
    // head->next->next->next->prev = head->next->next;
    // head->next->next->next->next->prev = head->next->next->next;

    printList(head);

    cout << (isPalindrome(head) ? "Yes" : "No")<< "\n";
    
    return 0;
}