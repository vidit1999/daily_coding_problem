#include <bits/stdc++.h>
using namespace std;

/*
Compute the running median of a sequence of numbers.
That is, given a stream of numbers, print out the median
of the list so far on each new element.

Recall that the median of an even-numbered list is the
average of the two middle numbers.

For example, given the sequence [2, 1, 5, 7, 2, 0, 5],
your algorithm should print out:

2
1.5
2
3.5
2
2
2
*/

void medianStream(int arr[], int n){
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> great;

    small.push(arr[0]);

    float m = arr[0];
    cout << m << "\n";

    for(int i=1; i<n; i++){
        if(small.size() > great.size()){
            if(arr[i] < m){
                great.push(small.top());
                small.pop();
                small.push(arr[i]);
            } else {
                great.push(arr[i]);
            }
            m = (small.top() + great.top()) / 2.0;
        } else if(small.size() < great.size()){
            if(arr[i] > m){
                small.push(great.top());
                great.pop();
                great.push(arr[i]);
            } else {
                small.push(arr[i]);
            }
            m = (small.top() + great.top()) / 2.0;
        } else {
            if(m > arr[i]){
                small.push(arr[i]);
                m = small.top();
            } else {
                great.push(arr[i]);
                m = great.top();
            }
        }
        cout << m << "\n";
    }
}

// main function
int main(){
    int arr[] = {2, 1, 5, 7, 2, 0, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    medianStream(arr, n);
    return 0;
}