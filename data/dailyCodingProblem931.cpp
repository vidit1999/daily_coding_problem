#include <bits/stdc++.h>
using namespace std;

/*
Given n numbers, find the greatest common denominator between them.

For example, given the numbers [42, 56, 14], return 14.
*/

int gcd(int a, int b){
    while(a){
        int temp = a;
        a = b%a;
        b = temp;
    }
    return b;
}

int greatestCommonDenominator(int arr[], int n){
    int ans = arr[0];
    
    for(int i=1; i<n; i++){
        ans = gcd(ans, arr[i]);
    }
    
    return ans;
}

// main function
int main(){
    int arr[] = {42, 56, 14};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << greatestCommonDenominator(arr, n) << "\n";
    return 0;
}