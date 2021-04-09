#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers, return a new array where each element in
the new array is the number of smaller elements to the right of that element in the original input array.

For example, given the array [3, 4, 9, 6, 1], return [1, 1, 2, 1, 0], since:

There is 1 smaller element to the right of 3
There is 1 smaller element to the right of 4
There are 2 smaller elements to the right of 9
There is 1 smaller element to the right of 6
There are no smaller elements to the right of 1
*/

vector<int> rightSmaller(vector<int> arr){
    set<int> s;
    vector<int> ans(arr.size());
    
    for(int i=arr.size()-1;i>=0;i--){
        auto it  = s.insert(arr[i]);
        ans[i] = distance(s.begin(), it.first);
    }

    return ans;
}

void testFunc(vector<vector<int>> v){
    for(auto ans : v){
        for(int i : rightSmaller(ans))
            cout << i << " ";
        cout << "\n";
    }
}

// main function
int main(){
    testFunc({
        {12, 1, 2, 3, 0, 11, 4},
        {5, 4, 3, 2, 1},
        {1, 2, 3, 4, 5},
        {12, 10, 5, 4, 2, 20, 6, 1, 0, 2},
        {10, 6, 15, 20, 30, 5, 7}
    });
    return 0;
}