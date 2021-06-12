#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of integers, where each element represents
the maximum number of steps that can be jumped going forward from
that element. Write a function to return the minimum number of
jumps you must take in order to get from the start to the end of the array.

For example, given [6, 2, 4, 0, 5, 1, 1, 4, 2, 9], you should return 2,
as the optimal solution involves jumping from 6 to 5, and then from 5 to 9.
*/

int countMinJumpToLastHelper(int arr[], int n, int i, unordered_map<int, int>& dp){
    if(i == n-1) return 0;
    if(arr[i] == 0) return INT_MAX;

    if(dp.find(i) != dp.end()) return dp[i];

    int count = INT_MAX;

    for(int k=1; k<=arr[i] && i+k<n; k++){
        int temp = countMinJumpToLastHelper(arr, n, i+k, dp);
        if(temp != INT_MAX)
            count = min(count, temp+1);
    }

    dp[i] = count;

    return count;
}

int countMinJumpToLast(int arr[], int n){
    int i = 0;
    unordered_map<int, int> dp;
    return countMinJumpToLastHelper(arr, n, i, dp);
}

// main function
int main(){
    int arr[] = {6, 2, 4, 0, 5, 1, 1, 4, 2, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << countMinJumpToLast(arr, n) << "\n";

    return 0;
}