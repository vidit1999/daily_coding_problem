#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100

/*
Implement a queue using a set of fixed-length arrays.

The queue should support enqueue, dequeue, and get_size operations.
*/

class Queue{
	int back;
	int arr[MAX_SIZE];
	
	public:
	Queue();
	void enqueue(int x);
	int dequeue();
	int get_size();
};

Queue::Queue(){
	back = 0;
}

void Queue::enqueue(int x){
	if(back == MAX_SIZE){
		cout << "Max element reached.";
		return;
	}
	
	arr[back++] = x;
}

int Queue::dequeue(){
	if(back == 0){
		return INT_MAX;
	}
	
	int ans = arr[0];
	
	for(int i=1; i<back; i++){
		arr[i-1] = arr[i];
	}
	
	back--;
	
	return ans;
}

int Queue::get_size(){
	return back;
}

// main function
int main(){
	Queue q;
	
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	
	cout << q.get_size() << "$\n";
	cout << q.dequeue() << "\n";
	cout << q.dequeue() << "\n";
	cout << q.get_size() << "$\n";
	cout << q.dequeue() << "\n";
	cout << q.dequeue() << "\n";
	cout << q.get_size() << "$\n";
	cout << q.dequeue() << "\n";
	
	return 0;
}