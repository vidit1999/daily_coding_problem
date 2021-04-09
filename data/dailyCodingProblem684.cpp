#include <bits/stdc++.h>
using namespace std;

/*
reduce (also known as fold) is a function that takes in an array,
a combining function, and an initial value and builds up a result
by calling the combining function on each element of the array,
left to right. For example, we can write sum() in terms of reduce:

def add(a, b):
    return a + b

def sum(lst):
    return reduce(lst, add, 0)

This should call add on the initial value with the first element of the array,
and then the result of that with the second element of the array,
and so on until we reach the end, when we return the sum of the array.

Implement your own version of reduce.
*/

int reduce(int arr[], function<int(int, int)> f, int n, int start){
    for(int i=0; i<n; i++){
        start = f(start, arr[i]);
    }
    return start;
}

int add(int a, int b){
    return a+b;
}

int sum(int arr[], int n){
    return reduce(arr, add, n, 0);
}

// main function
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << sum(arr, n) << "\n";
	return 0;
}