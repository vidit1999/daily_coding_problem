// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

/*
Given a linked list, remove all consecutive
nodes that sum to zero. Print out the remaining nodes.

For example, suppose you are given the input
3 -> 4 -> -7 -> 5 -> -6 -> 6. In this case,
you should first remove 3 -> 4 -> -7,
then -6 -> 6, leaving only 5.
*/

struct node{
    int data;
    node* next;
};

node* newNode(int data){
    auto head = new node;
    head->data = data;
    head->next = nullptr;
    return head;
}

node* createList(vector<int> arr){
    reverse(arr.begin(), arr.end());
    node* head = nullptr;
    
    for(int i : arr){
        auto nd = newNode(i);
        nd->next = head;
        head = nd;
    }
    
    return head;
}

void printList(node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

void printNonZeroSum(node* head){
    printList(head);
    auto curr = head;
    unordered_map<int, node*> sum_map;
    int sum = 0;
    
    while(curr){
        sum += curr->data;
        
        if(sum == 0){
            head = curr->next;
        }
        else if(sum_map.find(sum) != sum_map.end()){
            sum_map[sum]->next = curr->next;
        }
        else{
            sum_map[sum] = curr;
        }
        
        curr = curr->next;
    }
    
    printList(head);
}

void testFunc(vector<vector<int>> v){
    for(auto arr : v){
        auto head = createList(arr);
        printNonZeroSum(head);
        cout << "\n";
    }
}

int main(){
    testFunc({
        {3, 4, -7, 5, -6, 6},
        {1, 2, -3, 3, 1},
        {1, 2, 3, -3, 4},
        {1, 2, 3, -3, -2},
        {-1, 2, -1}
    });
    return 0;
}