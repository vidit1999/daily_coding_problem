#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers out of order, determine the bounds of the smallest
window that must be sorted in order for the entire array to be sorted.
For example, given [3, 7, 5, 6, 9], you should return (1, 3)
*/

pair<int, int> smallestWindowSort(int arr[], int n){
    int left = -1, right = -1;
    int max_so_far = INT_MIN, min_so_far = INT_MAX;

    for(int i=0; i<n; i++){
        if(max_so_far < arr[i]){
            max_so_far = arr[i];
        }

        if(arr[i] < max_so_far){
            right = i;
        }
    }

    for(int i=n-1; i>=0; i--){
        if(min_so_far > arr[i]){
            min_so_far = arr[i];
        }

        if(arr[i] > min_so_far){
            left = i;
        }
    }

    return {left, right};
}

// main function
int main(){
    int arr[] = {3, 7, 5, 6, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    auto ans = smallestWindowSort(arr, n);

    cout << ans.first << ", " << ans.second << "\n";
    
    return 0;
}