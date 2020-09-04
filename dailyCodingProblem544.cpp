#include <bits/stdc++.h>
using namespace std;

/*
Given a list of integers S and a target number k, write a function that
returns a subset of S that adds up to k. If such a subset cannot be made, then return null.

Integers can appear more than once in the list. You may assume all numbers in the list are positive.

For example, given S = [12, 1, 61, 5, 9, 2] and k = 24, return [12, 9, 2, 1] since it sums up to 24.
*/

bool isSubsetSum(int arr[], int n, int sum, vector<int>& ans){
    if(sum == 0)
        return true;
    if(n == 0 && sum != 0)
        return false;
    
    if(sum < arr[n-1])
        return isSubsetSum(arr, n-1, sum, ans);    
    
    if(isSubsetSum(arr, n-1, sum, ans))
        return true;
    else if(isSubsetSum(arr, n-1, sum - arr[n-1], ans)){
        ans.push_back(arr[n-1]);
        return true;
    }

    return false;
}

vector<int> subsetSum(int arr[], int n, int sum){
    vector<int> ans;
    if(isSubsetSum(arr, n, sum, ans))
        return ans;
    return {};
}

// main function
int main(){
    int arr[] = {12, 1, 61, 5, 9, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 15;

    for(int i : subsetSum(arr, n, sum))
        cout << i << "\n";
    return 0;
}