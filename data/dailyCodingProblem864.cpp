#include <bits/stdc++.h>
using namespace std;

/*
An imminent hurricane threatens the coastal town of Codeville.
If at most two people can fit in a rescue boat, and the maximum
weight limit for a given boat is k, determine how many boats will be needed to save everyone.

For example, given a population with weights [100, 200, 150, 80]
and a boat limit of 200, the smallest number of boats required will be three.
*/

int countMinBoats(vector<int> weights, int k){
    sort(weights.begin(), weights.end());
    int start=0, end=weights.size()-1, boat_count = 0;

    while(start <= end){
        if(weights[start] + weights[end] <= k){
            start++;
        }
        end--;
        boat_count++;
    }

    return boat_count;
}

// main function
int main(){
    cout << countMinBoats({100, 200, 150, 80}, 200) << "\n";
    return 0;
}