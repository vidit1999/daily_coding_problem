#include <bits/stdc++.h>
using namespace std;

/*
Implement a queue using two stacks.

Recall that a queue is a FIFO (first-in, first-out) data structure with
the following methods: enqueue, which inserts an element into the queue,
and dequeue, which removes it.
*/

class Queue{
    stack<int> s1, s2;

    public:
    bool empty();
    void enqueue(int item);
    int dequque();
};

bool Queue::empty(){
    return s2.empty() && s1.empty();
}

void Queue::enqueue(int item){
    s1.push(item);
}

int Queue::dequque(){
    if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }

    if(s2.empty()) return -1;
    
    int ans = s2.top();
    s2.pop();
    return ans;
}

// main function
int main(){
    Queue q;

    for(int i : {1, 2, 3, 4, 5, 6, 7}){
        q.enqueue(i);
    }

    while(!q.empty()){
        cout << q.dequque() << "\n";
    }
    
    return 0;
}