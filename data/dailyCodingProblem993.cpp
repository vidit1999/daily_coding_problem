#include <bits/stdc++.h>
using namespace std;

/*
Given a list of elements, find the majority element,
which appears more than half the time (> floor(len(lst) / 2.0)).

You can assume that such element exists.

For example, given [1, 2, 1, 1, 3, 4, 0], return 1.
*/

int majorityElem(int arr[], int n){
    unordered_map<int, int> umap;

    for(int i=0; i<n; i++){
        umap[arr[i]]++;
    }

    for(auto it : umap){
        if(it.second > n/2){
            return it.first;
        }
    }

    return -1;
}

// main function
int main(){
    int arr[] = {2, 2, 2, 2, 5, 5, 2, 3, 3};// {1, 2, 1, 1, 3, 4, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << majorityElem(arr, n) << "\n";
    return 0;
}
