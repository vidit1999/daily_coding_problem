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

class Stack{
    stack<int> s1, s2;
    
    public:
    void push(int val);
    int pop();
    int max();
};

void Stack::push(int val){
    s1.push(val);
    s2.push((s2.empty()) ? val : ::max(s2.top(), val));
}

int Stack::pop(){
    if(s1.empty()) return -1;
    int ans = s1.top();
    s1.pop();
    s2.pop();
    return ans;
}

int Stack::max(){
    if(s2.empty()) return -1;
    return s2.top();
}

// main function
int main(){
    Stack s;
    s.push(1);
    s.push(3);
    s.push(2);
    
    cout << s.max() << "\n";
    cout << s.pop() << "\n";
    
    cout << s.max() << "\n";
    cout << s.pop() << "\n";
    
    cout << s.max() << "\n";
    cout << s.pop() << "\n";
    
    cout << s.max() << "\n";
    cout << s.pop() << "\n";
    
    return 0;
}