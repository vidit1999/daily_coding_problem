#include <bits/stdc++.h>
using namespace std;

/*
Implement a stack API using only a heap. A stack implements the following methods:

push(item), which adds an element to the stack
pop(), which removes and returns the most recently added element
(or throws an error if there is nothing on the stack)
Recall that a heap has the following operations:

push(item), which adds a new key to the heap
pop(), which removes and returns the max value of the heap
*/

class Stack{
	priority_queue<pair<int, int>> pq;
	int count = 0;
	
	public:
	void push(int item);
	int pop();
	bool empty();
};

void Stack::push(int item){
	pq.push({count, item});
	count++;
}

bool Stack::empty(){
	return pq.empty();
}

int Stack::pop(){
	if(empty())
		return -1;
	int item = pq.top().second;
	pq.pop();
	count--;
	return item;
}

// main function
int main(){
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	
	cout << s.pop() << "\n";
	cout << s.pop() << "\n";
	cout << s.pop() << "\n";
	
	s.push(15);
	s.push(16);
	s.push(17);
	
	while(!s.empty()){
		cout << s.pop() << "\n";
	}
	
	cout << s.pop() << "\n";
	return 0;
}