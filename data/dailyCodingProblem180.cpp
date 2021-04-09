#include <bits/stdc++.h>
using namespace std;

/*
Given a stack of N elements, interleave the first half of the stack with the second half
reversed using only one other queue. This should be done in-place.

Recall that you can only push or pop from a stack, and enqueue or dequeue from a queue.

For example, if the stack is [1, 2, 3, 4, 5], it should become [1, 5, 2, 4, 3].
If the stack is [1, 2, 3, 4], it should become [1, 4, 2, 3].

Hint: Try working backwards from the end state.
*/

void interleaveStack(stack<int>& s){
	queue<int> q;
	
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}
    
    int size = q.size();

	for(int i=0;i<size/2;i++){
		s.push(q.front());
		q.pop();
	}
	
	while(!s.empty()){
        if(size%2){
            q.push(q.front());
            q.push(s.top());
        }
        else{
            q.push(s.top());
            q.push(q.front());
        }
		q.pop();
		s.pop();
	}
    
    if(size%2){
        q.push(q.front());
        q.pop();
    }

	while(!q.empty()){
		s.push(q.front());
		q.pop();
	}
}

// main function
int main(){
	stack<int> s;
	for(int i : {1, 2, 3, 4, 5, 6})
		s.push(i);
	interleaveStack(s);
	
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\n";
	
	return 0;
}