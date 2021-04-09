#include <bits/stdc++.h>
using namespace std;

/*
Given a sorted list of integers, square the elements and give the output in sorted order.
For example, given [-9, -2, 0, 2, 3], return [0, 4, 4, 9, 81].
*/

vector<int> sortedSquare(vector<int> arr){
    vector<int> ans;

    int start = 0, end = arr.size()-1;

    while(start <= end){
        if(arr[start]*arr[start] > arr[end]*arr[end]){
            ans.push_back(arr[start]*arr[start]);
            start++;
        }
        else{
            ans.push_back(arr[end]*arr[end]);
            end--;
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

// main function
int main(){
    for(int i : sortedSquare({-9, -2, 0, 2, 3}))
        cout << i << "\n";
    return 0;
}