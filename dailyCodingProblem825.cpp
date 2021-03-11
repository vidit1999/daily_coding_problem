#include <bits/stdc++.h>
using namespace std;

/*
Given a sorted list of integers, square the
elements and give the output in sorted order.

For example, given [-9, -2, 0, 2, 3],
return [0, 4, 4, 9, 81].
*/

vector<int> sortedSquare(vector<int> arr){
    vector<int> ans(arr.size());
    
    int l = 0, r = arr.size()-1, i = arr.size()-1;
    
    while(l <= r){
        if(arr[l]*arr[l] > arr[r]*arr[r]){
            ans[i--] = arr[l]*arr[l];
            l++;
        }
        else{
            ans[i--] = arr[r]*arr[r];
            r--;
        }
    }
    
    return ans;
}

// main function
int main(){
    for(int i : sortedSquare({-9, -2, 0, 2, 3})){
        cout << i << "\n";
    }
    
    return 0;
}