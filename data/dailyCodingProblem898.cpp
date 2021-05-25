#include <bits/stdc++.h>
using namespace std;

/*
Implement a stack API using only a heap.
A stack implements the following methods:

push(item), which adds an element to the stack
pop(), which removes and returns the most recently added
element (or throws an error if there is nothing on the stack)

Recall that a heap has the following operations:

push(item), which adds a new key to the heap
pop(), which removes and returns the max value of the heap
*/

class Stack{
    int count;
    priority_queue<pair<int, int>> pq;

public:
    Stack():count(0){};
    void push(int item);
    int pop();
    bool empty();
};

void Stack::push(int item){
    pq.push({++count, item});
}

int Stack::pop(){
    if(pq.empty()) return -1;

    count--;
    auto t = pq.top();
    pq.pop();
    return t.second;
}

bool Stack::empty(){
    return pq.empty();
}

// main function
int main(){
    Stack s;

    for(int i=0; i<10; i++){
        s.push(i);
    }

    while(!s.empty()){
        cout << s.pop() << "\n";
    }

    cout << s.pop() << "\n";

    return 0;
}
