#include <bits/stdc++.h>
using namespace std;

/*
Given an array of strictly the characters 'R', 'G', and 'B',
segregate the values of the array so that all the Rs come first,
the Gs come second, and the Bs come last. You can only swap elements of the array.

Do this in linear time and in-place.

For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'],
it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].
*/

void segregateArray(char arr[], int n){
    int r_i = 0, b_i = n-1;
    
    for(int i=0; i<n; i++){
        if(arr[i] == 'R'){
            swap(arr[i], arr[r_i]);
            r_i++;
        }
    }
    
    for(int i=n-1; i>=0; i--){
        if(arr[i] == 'B'){
            swap(arr[i], arr[b_i]);
            b_i--;
        }
    }
}


// main function
int main(){
    char arr[] = {'G', 'B', 'R', 'R', 'B', 'R', 'G'};
    int n = sizeof(arr)/sizeof(arr[0]);
    segregateArray(arr, n);
    
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    return 0;
}