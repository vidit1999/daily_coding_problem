#include <bits/stdc++.h>
using namespace std;

/*
Given an array of numbers of length N,
find both the minimum and maximum using
less than 2 * (N - 2) comparisons.
*/

pair<int, int> minMax(int arr[], int n){
    if(n == 0) return {};

    pair<int, int> ans; // ans.first = min and ans.second = max
    int i = 0;

    if(n%2){
        ans.first = arr[0];
        ans.second = arr[0];
        i++;
    }
    else{
        if(arr[0] > arr[1]){
            ans.first = arr[0];
            ans.second = arr[1];
        }
        else{
            ans.first = arr[1];
            ans.second = arr[0];
        }
        i += 2;
    }

    while(i < n-1){
        if(arr[i] > arr[i+1]){
            if(arr[i] > ans.first){
                ans.first = arr[i];
            }
            if(arr[i+1] < ans.second){
                ans.second = arr[i+1];
            }
        }
        else{
            if(arr[i+1] > ans.first){
                ans.first = arr[i+1];
            }
            if(arr[i] < ans.second){
                ans.second = arr[i];
            }
        }
        i += 2;
    }

    return ans;
}


// main function
int main(){
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr)/sizeof(arr[0]);

    auto ans = minMax(arr, n);

    cout << ans.first << ", " << ans.second << "\n";

    return 0;
}
