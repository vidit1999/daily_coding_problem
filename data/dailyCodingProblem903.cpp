#include <bits/stdc++.h>
using namespace std;

/*
Given an array of numbers and a number k,
determine if there are three entries in the array
which add up to the specified number k. For example,
given [20, 303, 3, 4, 25] and k = 49,
return true as 20 + 4 + 25 = 49.
*/

bool threeSumArray(int arr[], int n, int k){
    sort(arr, arr+n, greater<int>());

    for(int i=0; i<n; i++){
        int sum = k - arr[i];
        int low = i+1, high = n-1;

        while(low < high){
            if(arr[low] + arr[high] == sum) return true;
            else if(arr[low] + arr[high] > sum) low++;
            else high--;
        }
    }

    return false;
}

// main function
int main(){
    int arr[] = {20, 303, 3, 4, 25};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 49;

    cout << threeSumArray(arr, n, k) << "\n";
    return 0;
}