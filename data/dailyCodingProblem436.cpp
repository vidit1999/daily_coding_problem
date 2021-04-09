#include <bits/stdc++.h>
using namespace std;

/*
Implement 3 stacks using a single list:

class Stack:
    def __init__(self):
        self.list = []

    def pop(self, stack_number):
        pass

    def push(self, item, stack_number):
        pass
*/

struct stack_element{
    int data, prev_index;
};

class Stack{
    vector<stack_element> arr = {};
    unordered_set<int> freeIndices = {};
    int topIndices[3] = { -1, -1, -1};
    
    public:
    void push(int item, int sn){
        if(0 > sn || sn > 2) return;
        int top = topIndices[sn];
        if(!freeIndices.empty()){
            int freeIndex = *freeIndices.begin();
            arr[freeIndex] = {item, -1};
            freeIndices.erase(freeIndices.begin());
            topIndices[sn] = freeIndex;
        }
        else{
            arr.push_back({item, top});
            topIndices[sn] = arr.size()-1;
        }
    }

    int pop(int sn){
        if(topIndices[sn] == -1) return -1;
        auto elem = arr[topIndices[sn]];
        freeIndices.insert(topIndices[sn]);
        topIndices[sn] = elem.prev_index;
        return elem.data;
    }

    bool empty(int sn){
        return topIndices[sn] == -1;
    }
};

// main function
int main(){
    Stack s;
    s.push(1, 0);
    
    s.push(10, 1);
    s.push(11, 1);
    
    
    s.push(2, 0);
    s.push(3, 0);
    s.push(4, 0);

    s.push(20, 2);
    s.push(21, 2);

    s.push(12, 1);
    s.push(13, 1);
    
    s.push(22, 2);
    s.push(23, 2);

    for(int sn : {0, 1, 2}){
        while(!s.empty(sn))
            cout << s.pop(sn) << " ";
        cout << "\n";
    }
}