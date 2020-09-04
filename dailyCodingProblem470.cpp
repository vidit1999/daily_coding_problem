#include <bits/stdc++.h>
using namespace std;

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