#include <bits/stdc++.h>
using namespace std;

/*
Given an array of numbers and an index i, return
the index of the nearest larger number of the
number at index i, where distance is measured in array indices.

For example, given [4, 1, 3, 5, 6] and index 0,
you should return 3.

If two distances to larger numbers are the equal,
then return any one of them. If the array at i doesn't
have a nearest larger integer, then return null.

Follow-up: If you can preprocess the array,
can you do this in constant time?
*/

// returns the index of the nearest larger number if present
// else returns INT_MIN
int nearestLarger(vector<int> v, int idx){
    int checkVal = v[idx]; // value to be checked against
    int i = idx, j = idx; // i for previous elements and j for next elements

    while(--i >= 0 && ++j < v.size()){
        if(i >= 0 && v[i] > checkVal)
            return i;
        if(j < v.size() && v[j] > checkVal)
            return j;
    }
    return INT_MIN;
}

// main function
int main(){
    cout << nearestLarger(vector<int>({4, 1, 3, 5, 6}), 0) << "\n";
    return 0;
}