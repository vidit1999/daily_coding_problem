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
	int count;
	priority_queue<pair<int, int>> pq;
	
	public:
	
	Stack():count(0){}
	void push(int num);
	int pop();
};

void Stack::push(int num){
	pq.push({++count, num});
}

int Stack::pop(){
	if(!pq.empty()){
		auto t = pq.top(); pq.pop();
		count--;
		return t.second;
	}
	cout << "No elements left.\n";
	return -1;
}

// main function
int main(){
	vector<int> arr = {1,2,3,4,5,6,7,8,9};
	Stack s;
	for(int i : arr)
		s.push(i);
	
	for(int i=0; i<11; i++)
		cout << s.pop() << "\n";
	
	return 0;
}