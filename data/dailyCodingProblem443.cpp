#include <bits/stdc++.h>
using namespace std;

/*
Implement a queue using two stacks. Recall that a queue is a FIFO (first-in, first-out) data structure with the following methods: enqueue, which inserts an element into the queue, and dequeue, which removes it.
*/

class Queue{
    stack<int> s1, s2;

    public:

    void enqueue(int n){
        s1.push(n);
    }

    int dequeue(){
        if(s1.empty())
            return -1;
        
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        int x = s2.top();
        s2.pop();

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

        return x;
    }
};




// main function
int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << q.dequeue() << "\n";
    cout << q.dequeue() << "\n";
    cout << q.dequeue() << "\n";

    q.enqueue(10);
    q.enqueue(13);
    q.enqueue(16);

    cout << q.dequeue() << "\n";
    cout << q.dequeue() << "\n";
    cout << q.dequeue() << "\n";
}