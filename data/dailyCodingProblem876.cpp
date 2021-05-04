#include <bits/stdc++.h>
using namespace std;

/*
You are given a list of N numbers, in which each number is located
at most k places away from its sorted position. For example, if k = 1,
a given element at index 4 might end up at indices 3, 4, or 5.

Come up with an algorithm that sorts this list in O(N log k) time.
*/

void kSortArray(vector<int>& arr, int k){
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.begin()+k+1);
    
    int index = 0;

    for(int i=k+1; i<arr.size(); i++){
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    while(!pq.empty()){
        arr[index++] = pq.top();
        pq.pop();
    }
}

void testFunc(vector<pair<vector<int>, int>> v){
    for(auto it : v){
        kSortArray(it.first, it.second);

        for(int i : it.first){
            cout << i << " ";
        }
        
        cout << "\n";
    }
}

// main function
int main(){
    testFunc({
        {{6, 5, 3, 2, 8, 10, 9}, 3},
        {{10, 9, 8, 7, 4, 70, 60, 50}, 4}
    });
    return 0;
}