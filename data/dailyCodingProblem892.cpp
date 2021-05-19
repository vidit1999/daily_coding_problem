#include <bits/stdc++.h>
using namespace std;

/*
The power set of a set is the set of all its subsets.
Write a function that, given a set, generates its power set.

For example, given the set {1, 2, 3}, it should return
{{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.

You may also use a list or array to represent a set.
*/

void powerSetHelper(
    int n, int i,
    vector<int>& arr,
    vector<int>& temp,
    vector<vector<int>>& power_set
){
    if(i == n){
        power_set.push_back(temp);
        return;
    }

    temp.push_back(arr[i]);
    powerSetHelper(n, i+1, arr, temp, power_set);

    temp.pop_back();
    powerSetHelper(n, i+1, arr, temp, power_set);
}

vector<vector<int>> powerSet(vector<int> arr){
    vector<int> temp;
    vector<vector<int>> power_set;
    powerSetHelper(arr.size(), 0, arr, temp, power_set);
    return power_set;
}

// main function
int main(){
    for(auto v : powerSet({1, 2, 3})){
        for(int i : v){
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
