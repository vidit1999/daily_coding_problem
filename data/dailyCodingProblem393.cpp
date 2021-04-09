#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers, return the largest range, inclusive, of integers that are all included in the array.

For example, given the array [9, 6, 1, 3, 8, 10, 12, 11], return (8, 12) since 8, 9, 10, 11, and 12 are all in the array.
*/

pair<int, int> largestRange(vector<int> arr){
    unordered_set<int> s(arr.begin(), arr.end());

    int larRange = 0;
    pair<int, int> ans;

    for(int i : arr){
        if(s.find(i-1) == s.end()){
            int j = i;
            while(s.find(j) != s.end())
                j++;
            if(larRange < j-i){
                larRange = j-i;
                ans = {i, j-1};
            }
        }
    }

    return ans;
}


// main function
int main(){
    auto ans = largestRange({9, 6, 1, 3, 8, 10, 12, 11});
    cout << ans.first << ", " << ans.second << "\n";
	return 0;
}