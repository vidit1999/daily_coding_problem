#include <bits/stdc++.h>
using namespace std;

/*
Given an array of elements, return the length of the
longest subarray where all its elements are distinct.

For example, given the array [5, 1, 3, 5, 2, 3, 4, 1],
return 5 as the longest subarray of distinct elements is [5, 2, 3, 4, 1].
*/

int longestSubarrayDistinct(int arr[], int n){
    int ans = 0, start = 0, i = 0;
    unordered_set<int> uset;

    while(i < n){
        while(uset.find(arr[i]) != uset.end()){
            uset.erase(arr[start++]);
        }
        uset.insert(arr[i++]);
        ans = max(ans, int(uset.size()));
    }
    return ans;
}

// main function
int main(){
    int arr[] = {5, 1, 3, 5, 2, 3, 4, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << longestSubarrayDistinct(arr, n) << "\n";
    return 0;
}
