#include <bits/stdc++.h>
using namespace std;

/*
You have N stones in a row, and would like to create from them a pyramid.
This pyramid should be constructed such that the height of each stone
increases by one until reaching the tallest stone, after which the
heights decrease by one. In addition, the start and end stones of
the pyramid should each be one stone high.

You can change the height of any stone by paying a cost of 1 unit
to lower its height by 1, as many times as necessary. Given this
information, determine the lowest cost method to produce this pyramid.

For example, given the stones [1, 1, 3, 3, 2, 1], the optimal
solution is to pay 2 to create [0, 1, 2, 3, 2, 1].
*/

int minCostPyramid(int arr[], int n){
    int left[n], right[n];
    
    left[0] = min(arr[0], 1);
    
    for(int i=1; i<n; i++){
        left[i] = min(arr[i], min(left[i-1] + 1, i + 1));
    }
    
    right[n-1] = min(arr[n-1], 1);
    
    for(int i=n-2; i>=0; i--){
        right[i] = min(arr[i], min(right[i+1] + 1, n - i));
    }
    
    int height = INT_MIN, max_height_index = 0;
    
    for(int i=0; i<n; i++){
        if(height < min(left[i], right[i])){
            height = min(left[i], right[i]);
            max_height_index = i;
        }
    }
    
    int temp = height, cost = 0;
    
    for(int i=max_height_index; i>=0; i--){
        cost += arr[i] - temp;
        if(temp > 0){
            temp--;
        }
    }
    
    temp = height - 1;
    
    for(int i=max_height_index+1; i<n; i++){
        cost += arr[i] - temp;
        if(temp > 0){
            temp--;
        }
    }
    
    return cost;
}

// main function
int main(){
    int arr[] = {1, 1, 3, 3, 2, 1}; // {1, 2, 3, 4, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << minCostPyramid(arr, n) << "\n";
    return 0;
}