#include <bits/stdc++.h>
using namespace std;

/*
Compute the running median of a sequence of numbers.
That is, given a stream of numbers, print out the
median of the list so far on each new element.

Recall that the median of an even-numbered
list is the average of the two middle numbers.

For example, given the sequence
[2, 1, 5, 7, 2, 0, 5],
your algorithm should print out:

2
1.5
2
3.5
2
2
2
*/

float getMedian(
    priority_queue<int>& first_half,
    priority_queue<int, vector<int>, greater<int>>& second_half
){
    if(first_half.size() > second_half.size()){
        return first_half.top();
    }
    else if(first_half.size() < second_half.size()){
        return second_half.top();
    }
    return (first_half.top() + second_half.top()) / 2.0;
}

void runningMedian(int arr[], int n){
    priority_queue<int> first_half;
    priority_queue<int, vector<int>, greater<int>> second_half;
    
    for(int i=0; i<n; i++){
        if(first_half.empty() && second_half.empty()){
            first_half.push(arr[i]);
        }
        else if(first_half.size() != second_half.size()){
            int t;
            if(first_half.size() > second_half.size()){
                t = first_half.top(); first_half.pop();
            }
            else{
                t = second_half.size(); second_half.pop();
            }
            first_half.push(min(t, arr[i]));
            second_half.push(max(t, arr[i]));
        }
        else{
            auto median = getMedian(first_half, second_half);
            if(arr[i] < median){
                first_half.push(arr[i]);
            }
            else{
                second_half.push(arr[i]);
            }
        }
        
        cout << getMedian(first_half, second_half) << "\n";
    }
}

// main function
int main(){
    int arr[] = {2, 1, 5, 7, 2, 0, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    runningMedian(arr, n);
	return 0;
}