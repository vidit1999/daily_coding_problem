#include <iostream>
#include <climits>
#define MAX_SIZE 100
using namespace std;

/*
Implement a queue using a set of fixed-length arrays.
The queue should support enqueue, dequeue, and get_size operations.
*/

class Queue{
    private:
    int back;
    int *q;
    
    public:
    Queue(){
        back = 0;
        q = new int;
    }
    ~Queue(){
        delete[] q;
    }
    int get_size(){
        return back;
    }
    void enqueue(int data){
        if(back == MAX_SIZE){
            cout << "No space left\n";
            return;
        }
        q[back] = data;
        back++;
    }
    int dequeue(){
        if(back == 0)
            return INT_MAX;
        int temp = q[0];
        for(int i=1;i<back;i++){
            q[i-1] = q[i];
        }
        back--;
        return temp;
    }
};

// main function
int main(){
    int arr[] = {1,2,3,4,5,6};
    Queue q;
    cout << q.get_size() << "\n";
    for(int i=0;i<6;i++)
        q.enqueue(arr[i]);
    cout << q.get_size() << "\n---\n";
    while(q.get_size() > 0){
        cout << q.dequeue() << "\n";
    }
    cout << q.dequeue() << "\n";
	return 0;
}