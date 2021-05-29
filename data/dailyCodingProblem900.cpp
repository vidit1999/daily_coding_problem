#include <bits/stdc++.h>
using namespace std;

/*
Given an array of numbers, find the maximum sum of any contiguous subarray of the array.

For example, given the array [34, -50, 42, 14, -5, 86],
the maximum sum would be 137, since we would take elements 42, 14, -5, and 86.

Given the array [-5, -1, -8, -9], the maximum sum would be 0,
since we would not take any elements.

Do this in O(N) time.
*/

int maxContiguousSumArray(int arr[], int n){
    int max_ending_here = 0, max_so_far = 0;

    for(int i=0; i<n; i++){
        max_ending_here += arr[i];

        max_so_far = max(max_so_far, max_ending_here);
        max_ending_here = max(0, max_ending_here);
    }

    return max_so_far;
}

// main function
int main(){
    int arr1[] = {34, -50, 42, 14, -5, 86};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    
    int arr2[] = {-5, -1, -8, -9};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    cout << maxContiguousSumArray(arr1, n1) << "\n";
    cout << maxContiguousSumArray(arr2, n2) << "\n";

    return 0;
}