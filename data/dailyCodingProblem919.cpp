#include <bits/stdc++.h>
using namespace std;

/*
A wall consists of several rows of bricks of various integer
lengths and uniform height. Your goal is to find a vertical
line going from the top to the bottom of the wall that cuts
through the fewest number of bricks. If the line goes through
the edge between two bricks, this does not count as a cut.

For example, suppose the input is as follows, where values
in each row represent the lengths of bricks in that row:

[[3, 5, 1, 1],
 [2, 3, 3, 2],
 [5, 5],
 [4, 4, 2],
 [1, 3, 3, 3],
 [1, 1, 6, 1, 1]]

The best we can we do here is to draw a line after the eighth brick,
which will only require cutting through the bricks in the third and fifth row.

Given an input consisting of brick lengths for each row such
as the one above, return the fewest number of bricks that must
be cut to create a vertical line.
*/

int fewestCuts(vector<vector<int>> wall){
    int ans = INT_MAX;
    unordered_map<int, int> through_count;

    for(auto& row : wall){
        int curr_sum = 0;
        for(int i=0; i<row.size()-1; i++){
            curr_sum += row[i];
            through_count[curr_sum]++;
        }
    }

    for(auto it : through_count){
        ans = min(ans, int(wall.size() - it.second));
    }

    return ans;
}

// main function
int main(){
    vector<vector<int>> wall = {
        {3, 5, 1, 1},
        {2, 3, 3, 2},
        {5, 5},
        {4, 4, 2},
        {1, 3, 3, 3},
        {1, 1, 6, 1, 1},
    };

    cout << fewestCuts(wall) << "\n";

    return 0;
}