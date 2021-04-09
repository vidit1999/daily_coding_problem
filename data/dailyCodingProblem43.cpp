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
	stack<int> stk, max_stk;
	
	public:
	void push(int num);
	int pop();
	int max();
};

void MaxStack::push(int num){
	stk.push(num);
	
	if(!max_stk.empty()){
		max_stk.push(::max(max_stk.top(), num));
	}
	else{
		max_stk.push(num);
	}
}

int MaxStack::pop(){
	if(stk.empty()) return -1;
	
	int top = stk.top();
	stk.pop(); max_stk.pop();
	
	return top;
}

int MaxStack::max(){
	return (max_stk.empty())? -1 : max_stk.top();
}

// main function
int main(){
	MaxStack mstk;
	mstk.push(10);
	mstk.push(20);
	cout << mstk.max() << "\n";
	mstk.push(15);
	cout << mstk.max() << "\n";
	cout << mstk.pop() << "\n";
	cout << mstk.pop() << "\n";
	cout << mstk.max() << "\n";
	mstk.push(40);
	cout << mstk.max() << "\n";
	return 0;
}