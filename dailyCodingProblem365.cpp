#include <bits/stdc++.h>
using namespace std;

/*
A quack is a data structure combining properties of both stacks and queues.
It can be viewed as a list of elements written left to right such that three operations are possible:

push(x): add a new item x to the left end of the list
pop(): remove and return the item on the left end of the list
pull(): remove the item on the right end of the list.

Implement a quack using three stacks and O(1) additional memory,
so that the amortized time for any push, pop, or pull operation is O(1).
*/

class Quack{
	stack<int> s1, s2, s3;
	int sz;
	
	public:
	
	void push(int x);
	int pop();
	int pull();
};

void Quack::push(int x){
	s1.push(x);
	s2.push(x);
	sz++;
}

int Quack::pop(){
	if(sz == 0){
		s1 = stack<int>(); // empty stack
		s3 = stack<int>(); // empty stack
		return -1;
	}
	
	s2.pop();
	sz--;
	int ans = s1.top();
	s1.pop();
	return ans;
}

int Quack::pull(){
	if(sz == 0){
		s1 = stack<int>(); // empty stack
		s3 = stack<int>(); // empty stack
		return -1;
	}
	
	if(s3.empty()){
		while(!s2.empty()){
			s3.push(s2.top());
			s2.pop();
		}
	}
	
	int ans = s3.top();
	sz--;
	s3.pop();
	return ans;
}

// main function
int main(){
	Quack qu;
	
	qu.push(1);
	qu.push(2);
	qu.push(3);
	qu.push(4);
	
	cout << qu.pop() << "\n";
	cout << qu.pop() << "\n";
	
	qu.push(5);
	qu.push(6);
	
	cout << qu.pull() << "\n";
	cout << qu.pull() << "\n";
	
	return 0;
}