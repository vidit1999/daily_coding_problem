#include <bits/stdc++.h>
using namespace std;

/*
Implement a queue using two stacks. Recall that a queue is a FIFO (first-in, first-out)
data structure with the following methods: enqueue, which inserts an element into the queue,
and dequeue, which removes it.
*/

class Queue{
	stack<int> s1, s2;
	
	public:
	
	void enqueue(int num);
	int dequeue();
};

void Queue::enqueue(int num){
	s1.push(num);
}

int Queue::dequeue(){
	if(s2.empty()){
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}
	}
	
	if(!s2.empty()){
		int t = s2.top();
		s2.pop();
		return t;
	}
	
	return -1;
}


// main function
int main(){
	Queue q;
	
	for(int i=1; i<=10; i++) q.enqueue(i);
	for(int i=0; i<5; i++) cout << q.dequeue() << "\n";
	for(int i=30; i<=35; i++) q.enqueue(i);
	for(int i=0; i<5; i++) cout << q.dequeue() << "\n";
	
	return 0;
}