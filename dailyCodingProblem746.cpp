#include <bits/stdc++.h>
using namespace std;

/*
Implement a stack that has the following methods:

push(val), which pushes an element onto the stack

pop(), which pops off and returns the topmost element of the stack.
If there are no elements in the stack, then it should throw an error or return null.

max(), which returns the maximum value in the stack currently.
If there are no elements in the stack, then it should throw an error or return null.

Each method should run in constant time.
*/

class MaxStack{
	stack<int> s1, s2;

public:
	void push(int val);
	int pop();
	int max();
};

void MaxStack::push(int val){
	s1.push(val);
	s2.push((s2.empty())? val : ::max(s2.top(), val));
}

int MaxStack::pop(){
	if(s1.empty()) return -1;
	int ans = s1.top();
	s1.pop();
	s2.pop();
	return ans;
}

int MaxStack::max(){
	if(s2.empty()) return -1;
	return s2.top();
}

// main function
int main(){
	srand(time(0));

	MaxStack ms;

	for(int i=0; i<10; i++){
		int num = rand()%100;
		ms.push(num);
		cout << num << " -- " << ms.max() << "\n";
	}

	cout << "\n";

	for(int i=0; i<10; i++){
		cout << ms.pop() << "\n";
	}

	cout << "\n";
	cout << ms.max() << "\n";
	cout << ms.pop() << "\n";

	return 0;
}